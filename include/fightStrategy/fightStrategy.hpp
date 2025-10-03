#pragma once
#include <vector>

/**
 * @file fightStrategy.hpp
 * @brief Abstract base class for fight strategies.
 *
 * Concrete strategies implement specific behavior for executing moves during
 * a fight. The engine calls Execute() to run the strategy for a fight.
 */

class FightStrategy {
    public:
        /** @brief Construct a base FightStrategy. */
        FightStrategy();

        /** @brief Virtual destructor for polymorphic cleanup. */
        virtual ~FightStrategy() = default;

        /**
         * @brief Execute the strategy for the current fight.
         *
         * Implementations should perform the full strategy for the current
         * fight (casting spells, moving, passing turns) and return a status
         * code (E_OK on success or other error codes on failure).
         *
         * @return int Status code.
         */
        virtual int Execute() = 0;

        /** @brief Print the human-readable name of the strategy (debugging). */
        virtual void PrintStrategyName() = 0;

    protected:

        /// Current turn number (strategy-specific usage).
        int _turn;

        /// X position of the player in the fight menu UI.
        int _myXPositionInMenuFight;

        /// X positions of enemies in the fight menu UI.
        std::vector<int> _enemiesXPositionInMenuFight;

        /** @brief Throw defensive spells to the player. */
        void DefendMyself();

        /**
         * @brief Generic helper to cast a spell.
         *
         * @param spell Identifier taken from menuMappings enums.
         * @param who Target selector: self or enemies (strategy-defined values).
         * @param upperRow True if the spell is on the upper row, false if on the lower row.
         */
        void ThrowSpell(int spell, int who, int upperRow);

        /**
         * @brief Convenience helper to throw a spell on enemies.
         * @param spell Spell id.
         * @param upperRow True for upper row spells.
         */
        void ThrowSpellToEnemies(int spell, int upperRow);

        /**
         * @brief Convenience helper to throw a spell on self.
         * @param spell Spell id.
         * @param upperRow True for upper row spells.
         */
        void ThrowSpellToMyself(int spell, int upperRow);

        /**
         * @brief Perform randomized small movements for the player to end a turn.
         * @param moves Number of small random moves to perform.
         */
        void RandomMovePj(int moves);

        /** @brief Pass the current turn. */
        void PassTurn();

        /** @brief Start fight internal flow (helper). */
        void StartFight();

        /** @brief Wait until it's the player's turn. */
        void WaitForMyTurn();

        /**
         * @brief Called after fight to perform common cleanup and return status.
         * @return int Status code after cleanup.
         */
        int AfterFight();
};