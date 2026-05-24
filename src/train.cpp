#include "train.hpp"
#include "fight.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "roadmap.hpp"
#include "openCVOperations.hpp"

#include "system/inputs.hpp"
#include "system/file.hpp"

#include "fightStrategy/fecaAgiBruteStrategy.hpp"
#include "fightStrategy/ocraLejanoStrategy.hpp"

Train::Train()
{
    std::cout << "Train mode ON" << std::endl;
}

Train::~Train()
{
    std::cout << "Train mode OFF" << std::endl;
}

int Train::CheckMobSize(int &x, int &y)
{
    if(check::IsFight()) {
        return 1; // Already in fight, say that I found a monster.
    }

    int enemiesNumber = 0;

    inputs::PressKeyLocked('z'); // activate mob information bubble

    // First check where the bubble at. // RIGHT, DOWN, LEFT, UP
    bool isBubble = false;
    int cardinalPoint = RIGHT;

    //isBubble = check::IsBubble(x + 50, y);
    //if(isBubble) {
    //    cardinalPoint = RIGHT;
    //} else {
    //    isBubble = check::IsBubble(x - 50, y);
    //    if(isBubble) {
    //        cardinalPoint = LEFT;
    //    } else {
    
            //if(y > UP_Y) {
            //    isBubble = check::IsBubble(x, y - 50);
                //SetCursorPos(x, y - 50);
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            //}
    //        if(isBubble) cardinalPoint = UP;
    //    }
    //    
    //}

    // Check Bubble size.
    //if(isBubble) {
    //    if(cardinalPoint == RIGHT) {
    //        y -= 50;
    //        x += 50;
    //    } else if(cardinalPoint == LEFT) {
    //        y -= 50;
    //        x -= 50;
    //    } else if(cardinalPoint == UP) {
    //        y += 10;
    //    }
    //} else {
    //    inputs::PressKey('z'); // Release the pressed key.
    //    return -1; // No mob found.
    //}

    bool topBubbleFound = false;
    bool bottomBubbleFound = false;
    int firstDistancePoint = 0;
    int boxSize = 0;

    // iterate vertical line
    for(int yy = 0; yy < 400 && !topBubbleFound && (y - yy) > UP_Y; ++++yy) {

        //SetCursorPos(x, y - yy);
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if(!bottomBubbleFound && check::IsBubbleBottom(x, y - yy)) {
            bottomBubbleFound = true;
            firstDistancePoint = yy;
        }else if(bottomBubbleFound && check::IsBubbleTop(x, y - yy)) {
            topBubbleFound = true;
            boxSize = yy - firstDistancePoint;
        }
    }

    File::LogFile(("Bubble box size: " + std::to_string(boxSize)).c_str(), true);

    if(boxSize == 0) { // 0 enemies ?
        enemiesNumber = 0;
    } else if(boxSize < 40) { // 0 enemies aprox.
        enemiesNumber = 0;
    } else if(boxSize < 70) { // 2 enemies aprox.
        enemiesNumber = 2;
    } else if(boxSize < 90) { // 3 enemies aprox.
        enemiesNumber = 3;
    } else if(boxSize < 105) { // 4 enemies aprox.
        enemiesNumber = 4;
    } else if (boxSize < 140) {
        enemiesNumber = 6;
    } else {
        enemiesNumber = 8;
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    inputs::PressKey('z'); // Release the pressed key.

    return enemiesNumber;
}

int Train::IterateBetweenMaps()
{
    int ret = E_KO;

    for(int cardinalPoint = 0; cardinalPoint < 4; ++cardinalPoint) { // RIGHT, DOWN, LEFT, UP
        //ret = IterateCells();
        if(E_OK != ret) {
            return ret;
        }

        inputs::ChangeMap(cardinalPoint);
    }

    File::LogFile("Map iteration OK!", true);

    return ret;
}

int Train::IterateCells()
{
    const int NUM_ENEMIES_TO_FIND = 3;

    uint32_t iteration = 0;
    int oddSuplement = 22;
    int xxAvoid = 0; // When clicking a real player, don't interact with him.
    COLORREF color;

    for(int xx = LIMIT_CELL_X_MAX; xx > LIMIT_CELL_X_MIN; xx -= 44) {
        for(int yy = LIMIT_CELL_Y_MAX + oddSuplement; yy > LIMIT_CELL_Y_MIN; yy -= 44) {

            if((iteration % 5) == 0) {
                ++yy;
            }

            //SetCursorPos(xx, yy);
            color = basicOperations::GetColor(xx, yy, false);
            inputs::PressKey('x');
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            if(color != basicOperations::GetColor(xx, yy, false)) { // color different than before, there is a monster.

                SetCursorPos(xx, yy);
                File::LogFile("Possible MOOB found!",true);

                // Check for small mob.
                int mobSize = CheckMobSize(xx, yy);
                if(mobSize <= 0) { // mob NOT found or to little.
                    File::LogFile("MOOB NOT really found.",true);
                } else if(mobSize > NUM_ENEMIES_TO_FIND) { // mob NOT found or to little.
                    File::LogFile("MOOB to large.",true);
                } else { // I wanna fight this mob.

                    // Click the mob.
                    inputs::Click(xx + xxAvoid, yy);

                    std::this_thread::sleep_for(std::chrono::seconds(8));

                    if(check::IsFight()) {

                        ReadyToFight();

                        xx -= 88;
                    }
                }

                xxAvoid -= 2;
                yy -= (88+88);
            }

        }

        if(++iteration % 2 == 0) {
            oddSuplement = 22;
        } else {
            oddSuplement = 0;
        }

        xxAvoid = 0;

    }

    return E_OK;
}



int Train::ReadyToFight()
{
    int fightReturn = E_KO;

    // Check Pj.
    bool classFeca = OpenCVOperations::CheckPj("Feca");
    bool classOcra = OpenCVOperations::CheckPj("Ocra");
    bool classAnutrof = OpenCVOperations::CheckPj("Anutrof");

    std::unique_ptr<FightStrategy> selectedStrategy = nullptr;

    if(classFeca) {
        selectedStrategy = std::make_unique<FecaAgiBruteStrategy>();
    } else if(classOcra) {
        selectedStrategy = std::make_unique<OcraLejanoStrategy>();
    } else if(classAnutrof) {
        selectedStrategy = std::make_unique<OcraLejanoStrategy>(); // TODO: anu.
    } else {
        selectedStrategy = std::make_unique<OcraLejanoStrategy>();
    }

    // Call fight strategy.
    Fight fight(true, std::move(selectedStrategy)); // wait for the pj to arrive at the mob.
    fightReturn = fight.Start();
    if(E_OK != fightReturn) {
        File::LogFile("[Train] Fight NOT ended well for me...", true);

        inputs::PressEscape();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        if(check::IsMenuPrincipalBox()) {
            inputs::PressEscape();
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }

    }
    
    return fightReturn;
}




int Train::FindMob(std::string mobName, std::vector<int> mobNumber)
{
    int ret = E_KO;

    //////////////////////////
    // From mobName and mobNumber, build a vector of strings with the correct images to do check it.
    //////////////////////////
    std::string mobImage;
    std::vector<std::string> mobImages;
    for(int ii = 0; ii < mobNumber.size(); ++ii) {
        mobImage = mobName + std::to_string(mobNumber[ii]); // "Astrub2"
        // Find all available images in the sequence
        int index = 0;
        while(true) {
            // Construct the filename (make sure to adjust the extension if using .jpg)
            std::string fileName = mobImage + "_" + std::to_string(index) + ".PNG"; // "Astrub2_0.PNG"

            // Check if the file exists on the hard drive. 
            if(!File::ExistFile(fileName)) {
                break; 
            }

            // Add the valid file path to our vector
            mobImages.push_back(fileName);
            ++index;
        }
    }

    //////////////////
    // OpenCV call for mob recognition.
    //////////////////
    int posX = 0;
    int posY = 0;
    bool mobFound = false;//OpenCVOperations::FindImages(mobImages, posX, posY);
    if(mobFound) {
        File::LogFile("Mob found!", true);
        SetCursorPos(posX, posY);
        inputs::Click(posX, posY);

        std::this_thread::sleep_for(std::chrono::seconds(8));

        if(check::IsFight()) {
            ReadyToFight();
        }

        ret = E_OK;
    }

    return ret;
}