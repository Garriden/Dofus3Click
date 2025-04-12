#pragma once
#include "fightStrategy.hpp"

class ProfessionMobStrategy : public FightStrategy {
    public:
        void PrintStrategyName() override;
        int Execute() override;
};