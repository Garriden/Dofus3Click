#pragma once
#include <vector>

class Fight {
    public:
        Fight();
        Fight(int turn);
        ~Fight();

        void Start();

    private:
        void FightSet();
        void ChangeObjectsMenu();
        void ChangeSpellsMenu();
        void FindMyPosition();
        void FindEnemiesPositions();
        void ReadyToFight();
        void AfterFightSet();
        void AfterFightSit();

        int _turn;
        int _myXPositionInMenuFight;
        std::vector<int> _enemiesXPositionInMenuFight;

        enum FightPreparationState {
            FIGHT_SET                   = 0,
            CHANGE_SPELLS_MENU          = 1,
            FIND_MY_POSITION_MENU       = 2,
            FIND_ENEMY_POSITIONS_MENU   = 3,
            READY_TO_FIGHT              = 4,
            START_FIGHT_STRATEGY        = 5,
            CHECK_FIGHT_ENDED           = 6,
            AFTER_FIGHT_SET             = 7,
            AFTER_FIGHT_SIT             = 8
        };

        int FightStrategySM();
        void DefendMyself();

        /**
         * spell: from menuMappings enums.
         * who: to myself or enemies.
         * upperRow: True if spell on the upper row(SpellsRow::SPELLS_ROW), fals if spell on under row(SpellsCtrlRow::SPELLS_CTRL_ROW).
         */
        void ThrowSpell(int spell, int who, int upperRow);
        void ThrowSpellToEnemies(int spell, int upperRow);
        void ThrowSpellToMyself(int spell, int upperRow);
};