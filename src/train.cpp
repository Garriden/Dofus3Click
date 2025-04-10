#include "train.hpp"
#include "fight.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "roadmap.hpp"

Train::Train()
{
    std::cout << "Train mode ON" << std::endl;
}

Train::~Train()
{
    std::cout << "Train mode OFF" << std::endl;
}

int Train::IterateBetweenMaps()
{
    int ret = E_KO;

    for(int cardinalPoint = 0; cardinalPoint < 4; ++cardinalPoint) { // RIGHT, DOWN, LEFT, UP
        if(IterateCells() != E_OK) {
            return ret;
        }

        inputs::ChangeMap(cardinalPoint);
    }

    File::LogFile("Map iteration OK!", true);

    return E_OK;
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

                File::LogFile("MOOB found!",true);

                inputs::Click(xx + xxAvoid, yy);

                std::this_thread::sleep_for(std::chrono::seconds(8));

                if(check::IsFight()) {
                    Fight fight(true);
                    int fightReturn = fight.Start();
                    if(E_OK != fightReturn) {
                        File::LogFile("Fight NOT ended well for me...", true);
                        return fightReturn;
                    }
                    xx -= 88;
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