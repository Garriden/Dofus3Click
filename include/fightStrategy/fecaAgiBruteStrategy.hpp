#pragma once
#include "fightStrategy.hpp"

class FecaAgiBruteStrategy : public FightStrategy {
    public:
        void PrintStrategyName() override;
        int Execute() override;
};