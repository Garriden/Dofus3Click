#pragma once
#include <memory>
#include "fightStrategy/fightStrategy.hpp"

/**
 * @file fight.hpp
 * @brief High-level Fight control class used to prepare and execute fights.
 *
 * The Fight class orchestrates pre-fight preparation (setting menus, spells
 * and objects), runs a provided FightStrategy implementation and performs
 * post-fight actions (healing, sitting, etc.). It owns the currently active
 * strategy via a unique_ptr so strategies can be swapped at runtime.
 */

class Fight {
    public:

        /** @brief Default constructor. Creates a Fight controller with no strategy. */
        Fight();

        /**
         * @brief Construct a Fight controller with the provided strategy.
         * @param strategy Unique pointer to a FightStrategy implementation to use.
         */
        Fight(std::unique_ptr<FightStrategy> strategy);

        /**
         * @brief Construct a Fight controller with hunter flag and a strategy.
         * @param hunter If non-zero, the fight controller will behave as hunter-mode.
         * @param strategy Unique pointer to a FightStrategy implementation to use.
         */
        Fight(int hunter, std::unique_ptr<FightStrategy> strategy);

        /** @brief Destructor. Cleans up owned strategy. */
        ~Fight();

        /**
         * @brief Start the fight flow.
         *
         * Prepares the UI and objects, runs the configured strategy and handles
         * post-fight steps. Returns an integer status code (E_OK / E_KO or
         * other defined error constants).
         *
         * @return int Status code.
         */
        int Start();

    private:

        /** @brief Prepare the fight set (equipment/objects) before starting. */
        void FightSet();

        /** @brief Prepare prospection set before fight. */
        void ProspecSet();

        /** @brief Switch the objects menu in the UI. */
        void ChangeObjectsMenu();

        /** @brief Switch the spells menu in the UI. */
        void ChangeSpellsMenu();

        /**
         * @brief Invoke the configured FightStrategy and return its result.
         * @return int Result code from the strategy execution.
         */
        int CallFightStrategy();

        /** @brief Series of actions executed after a fight ends (general). */
        void AfterFightSet();

        /** @brief Sit the character after fight to recover heakth if needed. */
        void AfterFightSit();

        /** @brief Keep the character sitted while healing. */
        void AfterFightHeal();

        /// True when the controller is in hunter mode.
        bool _hunter;

        /// Currently selected fight strategy.
        std::unique_ptr<FightStrategy> _currentStrategy;

        /**
         * @enum FightPreparationState
         * @brief Internal states used during fight preparation and processing.
         */
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

        /**
         * @enum Set
         * @brief Convenience enum to represent sets/emotes used by the fight flow.
         */
        enum Set {
            SIT                         = 2 +'0', // NOT a set but an emote/action to recover health.
            PODS                        = 3 +'0',
            KOLI                        = 4 +'0',
            BERSERK                     = 5 +'0',
            HUNTER                      = 6 +'0',
            PROSPEC                     = 7 +'0'
        };

};