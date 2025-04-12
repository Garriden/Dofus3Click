#pragma once
#include <memory>
#include "fightStrategy/fightStrategy.hpp"

class Fight {
    public:
        Fight();
        Fight(std::unique_ptr<FightStrategy> strategy);
        Fight(int hunter, std::unique_ptr<FightStrategy> strategy);
        ~Fight();

        int Start();

    private:
        void FightSet();
        void ChangeObjectsMenu();
        void ChangeSpellsMenu();

        int CallFightStrategy();

        void AfterFightSet();
        void AfterFightSit();
        void AfterFightHeal();
        

        bool _hunter;
        std::unique_ptr<FightStrategy> _currentStrategy;

        enum FightPreparationState {
            FIGHT_SET                   = 0,
            CHANGE_SPELLS_MENU          = 1,
            START_FIGHT_STRATEGY        = 2,
            CHECK_FIGHT_ENDED           = 3,
            AFTER_FIGHT_SET             = 4,
            AFTER_FIGHT_SIT             = 5,
            WAIT_UNTIL_HEALED           = 6,
            RETURN_E_OK                 = 7
        };

};