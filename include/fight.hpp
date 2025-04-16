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
        void ProspecSet();
        void ChangeObjectsMenu();
        void ChangeSpellsMenu();

        int CallFightStrategy();

        void AfterFightSet();
        void AfterFightSit();
        void AfterFightHeal();
        

        bool _hunter;
        std::unique_ptr<FightStrategy> _currentStrategy;

        enum FightPreparationState {
            PUT_FIGHT_SET               = 0,
            CHANGE_SPELLS_MENU          = 1,
            START_FIGHT_STRATEGY        = 2,
            CHECK_FIGHT_ENDED           = 3,
            AFTER_FIGHT_SET             = 4,
            AFTER_FIGHT_SIT             = 5,
            WAIT_UNTIL_HEALED           = 6,
            RETURN_E_OK                 = 7,
            RETURN_E_IM_A_GHOST         = 8
        };

        enum Set {
            SIT                         = 2 +'0', // NOT a set but a emote/action to recover health.
            PODS                        = 3 +'0',
            KOLI                        = 4 +'0',
            BERSERK                     = 5 +'0',
            HUNTER                      = 6 +'0',
            PROSPEC                     = 7 +'0'
        };

};