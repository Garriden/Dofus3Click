#include "fightStrategy/fightStrategy.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "zaap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

FightStrategy::FightStrategy() :
    _turn(0),
    _myXPositionInMenuFight(0),
    _enemiesXPositionInMenuFight{}
{
    std::cout << "FightStrategy ON" << std::endl;
}

void FightStrategy::DefendMyself()
{
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    //ThrowSpellToMyself(SpellsCtrlRow::MURALLA, SpellsCtrlRow::SPELLS_CTRL_ROW);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ThrowSpellToMyself(SpellsCtrlRow::ESCUDO, SpellsCtrlRow::SPELLS_CTRL_ROW);
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void FightStrategy::ThrowSpell(int spell, int who, int upperRow)
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

void FightStrategy::ThrowSpellToEnemies(int spell, int upperRow)
{
    for(int ii = 0; ii < _enemiesXPositionInMenuFight.size(); ++ii) {
        if(check::IsAlmostTheEndOfTheTurn()) {
            PassTurn();
        } else if(check::IsFight()) { // if still on fight or my turn.
            ThrowSpell(spell, _enemiesXPositionInMenuFight[ii], upperRow);
        }
    }
}

void FightStrategy::ThrowSpellToMyself(int spell, int upperRow)
{
    if(check::IsFight()) { // if still on fight or my turn.
        ThrowSpell(spell, _myXPositionInMenuFight, upperRow);
    }
}

void FightStrategy::PassTurn()
{
    if(check::IsFight()) { // if still my turn...
        int enemiesUpdated = false;
        if(!enemiesUpdated) { // if I still have time, check how many enemies are still alive.
            _enemiesXPositionInMenuFight.clear();
            _enemiesXPositionInMenuFight = inputs::FindEnemiesPositions();
            enemiesUpdated = true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(check::IsFight()) { // if still my turn...
            inputs::PressSpace();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}

void FightStrategy::RandomMovePj(int moves)
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

void FightStrategy::StartFight() 
{
    File::LogFile("FightStarted ! ", true);

    _myXPositionInMenuFight = inputs::FindMyPosition();
    _enemiesXPositionInMenuFight = inputs::FindEnemiesPositions();
    PassTurn();
    _turn = 0;
}

void FightStrategy::WaitForMyTurn()
{
    while(!check::IsFight()) { // Wait for my turn.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(check::IsFightFinished()) {
            File::LogFile("Fight finished !", true);
            return;
        }
}
}

int FightStrategy::AfterFight() 
{
    _turn = 0;

    if(check::IsFenixBox()) { // fenix - ghost
        inputs::Click(FENIX_BOX_CLICK_POS_X_1, FENIX_BOX_CLICK_POS_Y_1);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        inputs::Click(FENIX_BOX_CLICK_POS_X_2, FENIX_BOX_CLICK_POS_Y_2);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        inputs::PressEscape();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Start roadmap ghost.
        return E_IM_A_GHOST;

    } else if(check::AmIDefeated()) {
        return E_KO;
    } else if(check::AmILevelUp() || check::IsAttentionBox()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        inputs::PressEscape();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    inputs::PressEscape();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if(zaap::CheckZaapAstrub()) {
        return E_KO;
    }

    return E_OK;
}