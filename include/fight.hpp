#pragma once

class Fight {
    public:
        Fight();
        Fight(int turn);
        ~Fight();

        void Start();
        void FightSet();

    private:

        int _turn;

        enum FightPreparationState {
            FIGHT_SET                   = 0,
            CHANGE_SPELLS_MENU          = 1,
            FIND_MY_POSITION_MENU       = 2,
            FIND_ENEMY_POSITIONS_MENU   = 3,
            START_FIGHT_STRATEGY        = 4,
            CHECK_FIGHT_ENDED           = 5,
            AFTER_FIGHT_SET             = 6,
            AFTER_FIGHT_SIT             = 7
        };

        enum FightStrategyState {
            CHECK_TURN                  = 0,
            DEFEND_MYSELF               = 1
        };


};