#include "train.hpp"
#include "fight.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "roadmap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"

#include "fightStrategy/fecaAgiBruteStrategy.hpp"

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
    
            if(y > UP_Y) {
                isBubble = check::IsBubble(x, y - 50);
                //              SetCursorPos(x, y - 50);
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
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
    for(int yy = 0; yy < 300 && !topBubbleFound && (y - yy) > UP_Y; ++++yy) {

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
    } else if(boxSize < 60) { // 2 enemies aprox.
        enemiesNumber = 2;
    } else if(boxSize < 110) { // 4 enemies aprox.
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
        ret = IterateCells();
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

            if(color != basicOperations::GetColor(xx, yy, false)) { // color different than before, there is a monster.

                SetCursorPos(xx, yy);
                File::LogFile("Possible MOOB found!",true);

                // Check for small mob.
                int mobSize = CheckMobSize(xx, yy);
                if(mobSize <= 0) { // mob NOT found or to little.
                    File::LogFile("MOOB NOT really found.",true);
                } else if(mobSize > 4) { // mob NOT found or to little.
                    File::LogFile("MOOB to large.",true);
                } else { // I wanna fight this mob.

                    // Click the mob.
                    inputs::Click(xx + xxAvoid, yy);

                    std::this_thread::sleep_for(std::chrono::seconds(8));

                    if(check::IsFight()) {
                        Fight fight(true, std::make_unique<FecaAgiBruteStrategy>()); // wait for the pj to arrive at the mob.
                        int fightReturn = fight.Start();
                        if(E_OK != fightReturn) {
                            File::LogFile("Fight NOT ended well for me...", true);
                            return fightReturn;
                        }
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