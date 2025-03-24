#include "fight.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

Fight::Fight() :
    _turn(0),
    _myXPositionInMenuFight(0)
{
    std::cout << "Fight constructor called" << std::endl;
}

Fight::Fight(int turn) :
    _turn(turn),
    _myXPositionInMenuFight(0)
{
    std::cout << "Fight constructor 2 called" << std::endl;
}

Fight::~Fight()
{
    std::cout << "Fight destructor called" << std::endl;
}

void Fight::Start()
{
    int step = FightPreparationState::FIGHT_SET;

    while(1) {
        switch(step) {
        case FightPreparationState::FIGHT_SET:
            FightSet();
            step = FightPreparationState::CHANGE_SPELLS_MENU;
            break;
        case FightPreparationState::CHANGE_SPELLS_MENU:
            ChangeSpellsMenu();
            step = FightPreparationState::FIND_MY_POSITION_MENU;
            break;
        case FightPreparationState::FIND_MY_POSITION_MENU:
            FindMyPosition();
            step = FightPreparationState::FIND_ENEMY_POSITIONS_MENU;
            break;
        default:
            return;
            break;
        }
    }

}

void Fight::FightSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    inputs::ChangeMenuBar(5, true);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('4'); // Fight Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::ChangeObjectsMenu()
{
    if(check::IsSpellsMenu()) {
        inputs::ClickSwitchBottomMenu();
    } else {
        File::LogFile("Already Objects menu.", true);
    }
}

void Fight::ChangeSpellsMenu()
{
    if(check::IsSpellsMenu()) {
        File::LogFile("Already Spells menu.", true);
    } else {
        inputs::ClickSwitchBottomMenu();
    }

}

void Fight::FindMyPosition()
{
    int ii = FIGTH_MENU_FRIEND_POS_X;
    int its = 50;
    while(its --> 0) {
        SetCursorPos(ii, FIGTH_MENU_FRIEND_POS_Y);
        COLORREF color1 = basicOperations::GetColor(ii, FIGTH_MENU_FRIEND_POS_Y, true);

        if(
        (int(GetRValue(color1)) < FIGTH_MENU_FRIEND_COLOR_RED    + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color1)) > FIGTH_MENU_FRIEND_COLOR_RED    - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) < FIGTH_MENU_FRIEND_COLOR_GREEN  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) > FIGTH_MENU_FRIEND_COLOR_GREEN  - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) < FIGTH_MENU_FRIEND_COLOR_BLUE   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) > FIGTH_MENU_FRIEND_COLOR_BLUE   - ERROR_GET_COLOUR_QUITE)
        )
        {
            _myXPositionInMenuFight = ii;
            File::LogFile(("My X position in fight menu: " + std::to_string(_myXPositionInMenuFight)).c_str(), true);
            return;
        }
        ii += 10;

    }

}