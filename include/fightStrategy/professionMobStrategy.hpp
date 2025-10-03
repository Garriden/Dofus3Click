#pragma once
#include "fightStrategy.hpp"

/**
 * @file professionMobStrategy.hpp
 * @brief FightStrategy used when fighting profession mobs (resource mobs).
 */

class ProfessionMobStrategy : public FightStrategy {
    public:
        /** @brief Print this strategy's name for debugging/logging. */
        void PrintStrategyName() override;

        /**
         * @brief Execute the profession mob strategy.
         * @return int Status code (E_OK on success).
         */
        int Execute() override;
};