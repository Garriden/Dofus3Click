#include "fight.hpp"
#include "menuMappings.hpp"
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
        case FightPreparationState::FIND_ENEMY_POSITIONS_MENU:
            FindEnemiesPositions();
            step = FightPreparationState::READY_TO_FIGHT;
            break;
        case FightPreparationState::READY_TO_FIGHT:
            ReadyToFight();
            step = FightPreparationState::START_FIGHT_STRATEGY;
            break;
        case FightPreparationState::START_FIGHT_STRATEGY:
            FightStrategySM();
            step = FightPreparationState::AFTER_FIGHT_SET;
            break;
        case FightPreparationState::AFTER_FIGHT_SET:
            AfterFightSet();
            step = FightPreparationState::AFTER_FIGHT_SIT;
            break;
        case FightPreparationState::AFTER_FIGHT_SIT:
            AfterFightSit();
            step = -1;
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

    inputs::ChangeMenuBar(5, false);

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
            _myXPositionInMenuFight = ii + 10; // When my turn, window gets slightly bigger.
            File::LogFile(("My X position in fight menu: " + std::to_string(_myXPositionInMenuFight)).c_str(), true);
            return;
        }
        ii += 10;
    }
}

void Fight::FindEnemiesPositions()
{
    int ii = FIGTH_MENU_FRIEND_POS_X;
    int its = 10;
    while(its --> 0) {
        SetCursorPos(ii, FIGTH_MENU_FRIEND_POS_Y);
        COLORREF color1 = basicOperations::GetColor(ii, FIGTH_MENU_FRIEND_POS_Y, true);

        if(
        (int(GetRValue(color1)) < FIGTH_MENU_ENEMY_COLOR_RED    + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color1)) > FIGTH_MENU_ENEMY_COLOR_RED    - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) < FIGTH_MENU_ENEMY_COLOR_GREEN  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) > FIGTH_MENU_ENEMY_COLOR_GREEN  - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) < FIGTH_MENU_ENEMY_COLOR_BLUE   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) > FIGTH_MENU_ENEMY_COLOR_BLUE   - ERROR_GET_COLOUR_QUITE)
        )
        {
            its = 10; // if enemy found, keep iterating to find more enemies.
            _enemiesXPositionInMenuFight.push_back(ii + 20); // When my turn, window gets slightly bigger.
            File::LogFile(("_enemiesXPositionInMenuFight: " + std::to_string(ii+5)).c_str(), true);
            ii += 80; // increment more or less where is the next enemy.
        }
        ii += 10;
    }
}

void Fight::ReadyToFight()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));

    inputs::PressSpace();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    //inputs::Click(ACCEPT_RETO_POS_X, ACCEPT_RETO_POS_Y); // Not needed if put automatically.
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::AfterFightSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('3'); // Pods Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::AfterFightSit()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('2'); // Fight Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int Fight::FightStrategySM() 
{
    File::LogFile("FightStrategySM() ! ", true);
    while(1 /*!dead || !fightFinished*/) {
        while(!check::CheckFight()) {} // Wait for my turn.

        if(_turn % 3 == 0) {
            DefendMyself();
        }

        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::MOON + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::SILBO + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::BORRASCA + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::ESCALOFRIO + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::MANIOBRA + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::PASTO + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::LLAMILLA + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
            inputs::PressKey(SpellsRow::LLAMILLA + '0');
            SetCursorPos(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            inputs::Click(_enemiesXPositionInMenuFight[ii], FIGTH_MENU_FRIEND_POS_Y);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }


        //std::this_thread::sleep_for(std::chrono::seconds(1));

        if(check::CheckFight()) { // if still my turn, pass
            inputs::PressSpace();
        }

        ++_turn;
    }

    /*
    int step = FightStrategyState::CHECK_TURN;

    while(1) {
        switch(step) {
        case FightStrategyState::CHECK_TURN:
            check::CheckFight();
            step = FightStrategyState::DEFEND_MYSELF;
            break;
        case FightStrategyState::DEFEND_MYSELF:
            //ChangeSpellsMenu();
            //step = FightPreparationState::FIND_MY_POSITION_MENU;
            break;
        default:
            return -1;
            break;
        }
    }
*/
    return 0;
}

void Fight::DefendMyself()
{
    inputs::PressCtrlKey(SpellsCtrlRow::MURALLA + '0');
    inputs::Click(_myXPositionInMenuFight, FIGTH_MENU_FRIEND_POS_Y);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    inputs::PressCtrlKey(SpellsCtrlRow::ESCUDO + '0');
    inputs::Click(_myXPositionInMenuFight, FIGTH_MENU_FRIEND_POS_Y);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}