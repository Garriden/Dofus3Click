#include "fightStrategy/fecaAgiBruteStrategy.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "zaap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

void FecaAgiBruteStrategy::PrintStrategyName()
{
    File::LogFile("FecaAgiBruteStrategy", true);
}

int FecaAgiBruteStrategy::Execute() 
{
    StartFight();

    while(!check::IsFightFinished()) {

        WaitForMyTurn();

        File::LogFile(("turn: " + std::to_string(_turn)).c_str(), true);

        //RandomMovePj(1); // Random Click.
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));

        //ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);

        if(_turn % 4 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::MURALLA, SpellsCtrlRow::SPELLS_CTRL_ROW);
        }

        if(_turn % 3 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::ESCUDO, SpellsCtrlRow::SPELLS_CTRL_ROW);
        } else if(_turn % 4 == 3) {
            ThrowSpellToMyself(SpellsCtrlRow::BASTION,   SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToMyself(SpellsCtrlRow::BARRICADA, SpellsCtrlRow::SPELLS_CTRL_ROW);
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
            ThrowSpellToEnemies(SpellsCtrlRow::ESCAPADITA, SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsCtrlRow::ESCARCHA,   SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsRow::NATURAL,        SpellsRow::SPELLS_ROW);
        }

        RandomMovePj(15); // Move randomly the Pj!

        if(_turn % 3 == 2 && _enemiesXPositionInMenuFight.size() != 1) {
            ThrowSpellToMyself(SpellsRow::RECELO,  SpellsRow::SPELLS_ROW);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(!check::IsRecallPoti()) {
            ThrowSpellToEnemies(SpellsCtrlRow::POMPA,      SpellsCtrlRow::SPELLS_CTRL_ROW);
            ThrowSpellToEnemies(SpellsRow::MOON,        SpellsRow::SPELLS_ROW);
            ThrowSpellToEnemies(SpellsRow::SILBO,       SpellsRow::SPELLS_ROW);
            ThrowSpellToEnemies(SpellsRow::BORRASCA,    SpellsRow::SPELLS_ROW);
        }

        PassTurn();

        ++_turn;
    }

    return AfterFight();
}