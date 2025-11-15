#include "fightStrategy/ocraLejanoStrategy.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "zaap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <string>

void OcraLejanoStrategy::PrintStrategyName()
{
    File::LogFile("OcraLejanoStrategy", true);
}

int OcraLejanoStrategy::Execute() 
{
    StartFight();

    while(!check::IsFightFinished()) {

        WaitForMyTurn();

        File::LogFile(("turn: " + std::to_string(_turn)).c_str(), true);

        //RandomMovePj(1); // Random Click.
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));

        //ThrowSpellToMyself(SpellsCtrlRow::ATARAXIA, SpellsCtrlRow::SPELLS_CTRL_ROW);

        if(_turn % 4 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::MURALLA, SpellsCtrlRow::SPELLS_CTRL_ROW); // Potente.
            //ThrowSpellToMyself(SpellsCtrlRow::ESCUDO, SpellsCtrlRow::SPELLS_CTRL_ROW); // Lejano.
        }

        if((_turn-1) % 3 == 0) {
            ThrowSpellToMyself(SpellsCtrlRow::ESCUDO, SpellsCtrlRow::SPELLS_CTRL_ROW);
        }

        ThrowSpellToEnemies(SpellsRow::BORRASCA,    SpellsRow::SPELLS_ROW); // Absorbente.

        //if(_turn % 3 == 0) {
            ThrowSpellToEnemies(SpellsRow::RECELO,       SpellsRow::SPELLS_ROW); // Charge Expi.
        //}

        //if(_turn % 2 == 0) {
            ThrowSpellToEnemies(SpellsRow::VIGIA,        SpellsRow::SPELLS_ROW); // Charge Casti.
        //}


        ThrowSpellToEnemies(SpellsCtrlRow::WEAPON,  SpellsRow::SPELLS_ROW); // weapon is just 'q'
        ThrowSpellToEnemies(SpellsRow::SILBO,       SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::ESCALOFRIO,  SpellsRow::SPELLS_ROW); // Optica.
        ThrowSpellToEnemies(SpellsRow::MANIOBRA,    SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::PASTO,       SpellsRow::SPELLS_ROW);
        //ThrowSpellToEnemies(SpellsRow::MOON,        SpellsRow::SPELLS_ROW);
        ThrowSpellToEnemies(SpellsRow::LLAMILLA,    SpellsRow::SPELLS_ROW);

        if(_enemiesXPositionInMenuFight.size() == 1) {

        }

        RandomMovePj(20); // Move randomly the Pj!

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(!check::IsRecallPoti()) {
            ThrowSpellToEnemies(SpellsRow::BORRASCA,    SpellsRow::SPELLS_ROW); // Absorbente.
            //if(_turn % 3 == 0) {
                ThrowSpellToEnemies(SpellsRow::RECELO,       SpellsRow::SPELLS_ROW); // Charge Expi.
            //}
    
            //if(_turn % 2 == 0) {
                ThrowSpellToEnemies(SpellsRow::VIGIA,        SpellsRow::SPELLS_ROW); // Charge Casti.
            //}

            ThrowSpellToEnemies(SpellsRow::ESCALOFRIO,  SpellsRow::SPELLS_ROW); // Optica.
        }

        PassTurn();

        ++_turn;
    }

    return AfterFight();
}