#include "fight.hpp"
#include "menuMappings.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "zaap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "fightStrategy/professionMobStrategy.hpp"
#include "fightStrategy/fecaAgiBruteStrategy.hpp"
#include <string>

Fight::Fight() :
    _hunter(false),
    _currentStrategy(nullptr)
{
    std::cout << "Fight mode ON" << std::endl;
}

Fight::Fight(std::unique_ptr<FightStrategy> strategy) :
    _hunter(false),
    _currentStrategy(std::move(strategy))
{
    std::cout << "Fight mode ON" << std::endl;
}

Fight::Fight(int hunter, std::unique_ptr<FightStrategy> strategy) :
    _hunter(hunter),
    _currentStrategy(std::move(strategy))
{
    std::cout << "Fight mode ON, hunter: " << hunter << std:: endl;
}

Fight::~Fight()
{
    std::cout << "Fight mode OFF" << std::endl;
}

int Fight::Start()
{
    int step = FightPreparationState::FIGHT_SET;

    while(1) {
        switch(step) {
        case FightPreparationState::FIGHT_SET:
            FightSet();
            step = FightPreparationState::CHANGE_SPELLS_MENU;
            break;
        case FightPreparationState::CHANGE_SPELLS_MENU:
            ChangeSpellsMenu();
            step = FightPreparationState::START_FIGHT_STRATEGY;
            break;
        case FightPreparationState::START_FIGHT_STRATEGY:
            if(E_OK == CallFightStrategy()) {
                step = FightPreparationState::AFTER_FIGHT_SET;
            } else {
                step = -1;
            }
            break;
        case FightPreparationState::AFTER_FIGHT_SET:
            AfterFightSet();
            step = FightPreparationState::AFTER_FIGHT_SIT;
            break;
        case FightPreparationState::AFTER_FIGHT_SIT:
            AfterFightSit();
            step = WAIT_UNTIL_HEALED;
            break;
        case FightPreparationState::WAIT_UNTIL_HEALED:
            //AfterFightHeal(); // Wait until healed.
            step = RETURN_E_OK;
            break;
        case FightPreparationState::RETURN_E_OK:
            return E_OK;
            break;
        default:
            return E_KO;
            break;
        }
    }

}

void Fight::FightSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(_hunter) {
        inputs::PressCtrlKey('6'); // Hunter Set
    } else {
        inputs::PressCtrlKey('5'); // Berserk Set
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

// Todo: sned to inputs
void Fight::ChangeObjectsMenu()
{
    if(check::IsSpellsMenu()) {
        inputs::ClickSwitchBottomMenu();
    } else {
        //File::LogFile("Already Objects menu.", true);
    }
}

void Fight::ChangeSpellsMenu()
{
    if(check::IsSpellsMenu()) {
        //File::LogFile("Already Spells menu.", true);
    } else {
        inputs::ClickSwitchBottomMenu();
    }

}

void Fight::AfterFightSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(10));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('4'); // Koli Set hack
    std::this_thread::sleep_for(std::chrono::seconds(5));
    inputs::PressCtrlKey('3'); // Pods Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::AfterFightSit()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('2'); // Sit
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::AfterFightHeal()
{
    while(!check::HaveIHealth()) {
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

int Fight::CallFightStrategy() 
{
    if(_currentStrategy == nullptr) {
        if(inputs::FindEnemiesPositions().size() > 1) {
            _currentStrategy = std::move( std::make_unique<FecaAgiBruteStrategy>() );
        } else {
            _currentStrategy = std::move( std::make_unique<ProfessionMobStrategy>() );
        }
    }

    _currentStrategy->PrintStrategyName();

    return _currentStrategy->Execute();
}