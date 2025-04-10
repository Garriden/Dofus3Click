#include "fight.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

Fight::Fight() :
    _turn(0),
    _myXPositionInMenuFight(0),
    _enemiesXPositionInMenuFight{}
{
    std::cout << "Fight mode ON" << std::endl;
}

Fight::Fight(int turn) :
    _turn(turn),
    _myXPositionInMenuFight(0),
    _enemiesXPositionInMenuFight{}
{
    std::cout << "Fight mode ON 2" << std::endl;
}

Fight::~Fight()
{
    std::cout << "Fight mode OFF" << std::endl;
}

int Fight::Start()
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
            if(E_OK == FightStrategySM()) {
                step = FightPreparationState::AFTER_FIGHT_SET;
            } else {
                step = -1;
            }
            break;
        case FightPreparationState::AFTER_FIGHT_SET:
            AfterFightSet();
            step = FightPreparationState::AFTER_FIGHT_SIT;
            break;
        case FightPreparationState::AFTER_FIGHT_SIT:
            AfterFightSit();
            step = WAIT_UNTIL_HEALED;
            break;
        case FightPreparationState::WAIT_UNTIL_HEALED:
            AfterFightHeal(); // Wait until healed.
            step = RETURN_E_OK;
            break;
        case FightPreparationState::RETURN_E_OK:
            return E_OK;
            break;
        default:
            return E_KO;
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
    inputs::PressCtrlKey('5'); // Fight Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Todo: sned to inputs
void Fight::ChangeObjectsMenu()
{
    if(check::IsSpellsMenu()) {
        inputs::ClickSwitchBottomMenu();
    } else {
        //File::LogFile("Already Objects menu.", true);
    }
}

void Fight::ChangeSpellsMenu()
{
    if(check::IsSpellsMenu()) {
        //File::LogFile("Already Spells menu.", true);
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
        COLORREF color1 = basicOperations::GetColor(ii, FIGTH_MENU_FRIEND_POS_Y, false);

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
            //File::LogFile(("My X position in fight menu: " + std::to_string(_myXPositionInMenuFight)).c_str(1), true);
            return;
        }
        ii += 10;
    }
}

void Fight::FindEnemiesPositions()
{
    int ii = FIGTH_MENU_FRIEND_POS_X;
    int its = 50;
    while(its --> 0) {
        SetCursorPos(ii, FIGTH_MENU_FRIEND_POS_Y);
        COLORREF color1 = basicOperations::GetColor(ii, FIGTH_MENU_FRIEND_POS_Y, false);

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
            _enemiesXPositionInMenuFight.push_back(ii + 10); // When my turn, window gets slightly bigger.
            //File::LogFile(("_enemiesXPositionInMenuFight: " + std::to_string(ii+10)).c_str(), true);
            ii += 58; // increment more or less where is the next enemy.
        }
        ii += 18;
    }
    File::LogFile(("Number of enemies: " + std::to_string(_enemiesXPositionInMenuFight.size())).c_str(), true);
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
    std::this_thread::sleep_for(std::chrono::seconds(10));
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

void Fight::AfterFightHeal()
{
    while(!check::HaveIHealth()) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

int Fight::FightStrategySM() 
{
    File::LogFile("FightStarted ! ", true);
    while(!check::IsFightFinished()) {

        while(!check::IsFight()) { // Wait for my turn.
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if(check::IsFightFinished()) {
                File::LogFile("Fight finished !!!!!!!!! while waiting for my turn to arrive", true);
                break;
            }
        }

        File::LogFile(("turn: " + std::to_string(_turn)).c_str(), true);

        ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);
        
        if(_turn % 4 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::MURALLA, SpellsCtrlRow::SPELLS_CTRL_ROW);
        }
        if(_turn % 3 == 0) {
            DefendMyself();
        } 
        if(_turn % 4 == 3) {
            ThrowSpellToMyself(SpellsCtrlRow::BASTION,   SpellsCtrlRow::SPELLS_CTRL_ROW);
        } 
        if(_turn % 8 == 7) {
            ThrowSpellToMyself(SpellsCtrlRow::BARRICADA, SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToMyself(SpellsRow::VIGIA,         SpellsRow::SPELLS_ROW);
        }

        ThrowSpellToEnemies(SpellsCtrlRow::WEAPON,  SpellsRow::SPELLS_ROW); // weapon is just 'q'
        ThrowSpellToEnemies(SpellsRow::SILBO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::BORRASCA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::ESCALOFRIO,  SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::MANIOBRA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::PASTO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::MOON,        SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::LLAMILLA,    SpellsRow::SPELLS_ROW);

        if(_enemiesXPositionInMenuFight.size() == 1) {
            ThrowSpellToEnemies(SpellsCtrlRow::ESTRATO,   SpellsCtrlRow::SPELLS_CTRL_ROW);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            ThrowSpellToEnemies(SpellsCtrlRow::ESCAPADITA, SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsCtrlRow::POMPA,      SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsCtrlRow::ESCARCHA,   SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsRow::NATURAL,        SpellsRow::SPELLS_ROW);
        }

        RandomMovePj(10); // Move randomly the Pj!

        if(_turn % 3 == 2 && _enemiesXPositionInMenuFight.size() != 1) {
            ThrowSpellToMyself(SpellsRow::RECELO,  SpellsRow::SPELLS_ROW);
        }

        if(check::IsFight()) { // if still my turn, pass
            PassTurn();
        }

        ++_turn;
    }

    _turn = 0;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    inputs::PressEscape();
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    if(check::AmIDefeated()) {
        //if(ghost) // TODO
        return E_KO;
    } else if(check::AmILevelUp()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        inputs::Click(I_AM_LEVEL_UP_POS_X_4, I_AM_LEVEL_UP_POS_Y_4);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    return E_OK;
}

void Fight::DefendMyself()
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //ThrowSpellToMyself(SpellsCtrlRow::MURALLA, SpellsCtrlRow::SPELLS_CTRL_ROW);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ThrowSpellToMyself(SpellsCtrlRow::ESCUDO, SpellsCtrlRow::SPELLS_CTRL_ROW);
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Fight::ThrowSpell(int spell, int who, int upperRow)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    if(upperRow) {
        inputs::PressKey(spell);
    } else {
        inputs::PressCtrlKey(spell);
    }
    SetCursorPos(who, FIGTH_MENU_FRIEND_POS_Y);
    inputs::Click(who, FIGTH_MENU_FRIEND_POS_Y);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Fight::ThrowSpellToEnemies(int spell, int upperRow)
{
    for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
        if(check::IsAlmostTheEndOfTheTurn()) {
            PassTurn();
        } else if(check::IsFight()) { // if still on fight or my turn.
            ThrowSpell(spell, _enemiesXPositionInMenuFight[ii], upperRow);
        }
    }
}

void Fight::ThrowSpellToMyself(int spell, int upperRow)
{
    if(check::IsFight()) { // if still on fight or my turn.
        ThrowSpell(spell, _myXPositionInMenuFight, upperRow);
    }
}

void Fight::PassTurn()
{
    int enemiesUpdated = false;
    if(!enemiesUpdated) { // if I still have time, check how many enemies are still alive.
        _enemiesXPositionInMenuFight.clear();
        FindEnemiesPositions();
        enemiesUpdated = true;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if(check::IsFight()) { // if still my turn...
        inputs::PressSpace();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void Fight::RandomMovePj(int moves)
{
    for (int ii = 0; ii < moves; ++ii) {
        if(check::IsAlmostTheEndOfTheTurn()) {
            PassTurn();
        } else if(check::IsFight()) { // if still on fight or my turn.
            int ruletNumberPosX = basicOperations::RuletaInput(FIGHT_X_LIMIT_MIN, FIGHT_X_LIMIT_MAX);
            int ruletNumberPosY = basicOperations::RuletaInput(FIGHT_Y_LIMIT_MIN, FIGHT_Y_LIMIT_MAX);
            inputs::Click(ruletNumberPosX, ruletNumberPosY);
        }
    }
}