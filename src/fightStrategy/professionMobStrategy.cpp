#include "fightStrategy/professionMobStrategy.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "zaap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

void ProfessionMobStrategy::PrintStrategyName() 
{
    File::LogFile("ProfessionMobStrategy", true);
}

int ProfessionMobStrategy::Execute() 
{
    StartFight();

    while(!check::IsFightFinished()) {

        WaitForMyTurn();

        File::LogFile(("turn: " + std::to_string(_turn)).c_str(), true);

        //RandomMovePj(1); // Random Click. If space keyboard activate chat.
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if(_turn % 4 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::BASTION,   SpellsCtrlRow::SPELLS_CTRL_ROW);
        }

        ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);

        //ThrowSpellToEnemies(SpellsCtrlRow::WEAPON,  SpellsRow::SPELLS_ROW); // weapon is just 'q'
        ThrowSpellToEnemies(SpellsRow::SILBO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::BORRASCA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::ESCALOFRIO,  SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::MANIOBRA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::PASTO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::MOON,        SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::LLAMILLA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::NATURAL,     SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::RECELO,      SpellsRow::SPELLS_ROW);

        RandomMovePj(30); // Move randomly the Pj!

        ThrowSpellToEnemies(SpellsRow::MOON,        SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::NATURAL,     SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::SILBO,       SpellsRow::SPELLS_ROW);

        ThrowSpellToMyself(SpellsRow::ESCALOFRIO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToMyself(SpellsCtrlRow::BARRICADA,    SpellsCtrlRow::SPELLS_CTRL_ROW);
        ThrowSpellToMyself(SpellsRow::VIGIA,            SpellsRow::SPELLS_ROW);

        PassTurn();

        ++_turn;
    }

    return AfterFight();
}