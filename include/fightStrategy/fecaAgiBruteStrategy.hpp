#pragma once

#include "fightStrategy.hpp"

/**
 * @file fecaAgiBruteStrategy.hpp
 * @brief Concrete FightStrategy for a Feca agility brute tactic.
 */

class FecaAgiBruteStrategy : public FightStrategy {
    public:
        /** @brief Print this strategy's name for debugging/logging. */
        void PrintStrategyName() override;

        /**
         * @brief Execute the Feca agility brute strategy.
         * @return int Status code (E_OK on success).
         */
        int Execute() override;
};