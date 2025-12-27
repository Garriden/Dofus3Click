#pragma once

#include "fightStrategy.hpp"

/**
 * @file ocraLejanoStrategy.hpp
 * @brief Ocra with disparo lejano, agility tactic. Charge Casti + Expi.
 */

class OcraLejanoStrategy : public FightStrategy {
    public:
        /** @brief Print this strategy's name for debugging/logging. */
        void PrintStrategyName() override;

        /**
         * @brief Execute the Feca agility brute strategy.
         * @return int Status code (E_OK on success).
         */
        int Execute() override;
};