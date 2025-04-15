#pragma once
#include <vector>

class FightStrategy {
    public:
        FightStrategy();
        //FightStrategy();
        virtual ~FightStrategy() = default;

        virtual int Execute() = 0;
        virtual void PrintStrategyName() = 0;

        
    protected:


        int _turn;
        int _myXPositionInMenuFight;
        std::vector<int> _enemiesXPositionInMenuFight;

        void DefendMyself();

        /**
         * spell: from menuMappings enums.
         * who: to myself or enemies.
         * upperRow: True if spell on the upper row(SpellsRow::SPELLS_ROW), fals if spell on under row(SpellsCtrlRow::SPELLS_CTRL_ROW).
         */
        void ThrowSpell(int spell, int who, int upperRow);
        void ThrowSpellToEnemies(int spell, int upperRow);
        void ThrowSpellToMyself(int spell, int upperRow);

        // Click "moves" times in a random pixel around the center of the screen. To the Pj to move before ending the turn.
        void RandomMovePj(int moves);

        void PassTurn();

        void StartFight();
        void WaitForMyTurn();
        int AfterFight();
};