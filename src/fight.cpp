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
    int step = FightPreparationState::PUT_FIGHT_SET;

    while(1) {
        switch(step) {
        case FightPreparationState::PUT_FIGHT_SET:
            FightSet();
            step = FightPreparationState::CHANGE_SPELLS_MENU;
            break;
        case FightPreparationState::CHANGE_SPELLS_MENU:
            ChangeSpellsMenu();
            step = FightPreparationState::START_FIGHT_STRATEGY;
            break;
        case FightPreparationState::START_FIGHT_STRATEGY:
        {
            int fightReturn = CallFightStrategy();
            if(E_OK == fightReturn) {
                step = FightPreparationState::AFTER_FIGHT_SET;
            } else if(E_KO_MAP_NOT_CHANGED == fightReturn) {
                AfterFightSet();
                return E_KO_MAP_NOT_CHANGED;
                break;
            } else if(E_IM_A_GHOST == fightReturn) { // I'm a Ghost
                step = FightPreparationState::RETURN_E_IM_A_GHOST;
            } else {
                step = -1;
            }
            break;
        }
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
        case FightPreparationState::RETURN_E_IM_A_GHOST:
            return E_IM_A_GHOST;
            break;
        default:
            return E_KO;
            break;
        }
    }

}

void Fight::FightSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    if(_hunter) {
        inputs::PressCtrlKey(Set::HUNTER);
    } else {
        inputs::PressCtrlKey(Set::BERSERK);
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::ProspecSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey(Set::PROSPEC);
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
    std::this_thread::sleep_for(std::chrono::seconds(15));
    inputs::PressCtrlKey(0); // Reset Ctrl key.
    //inputs::Click(RIGHT_X - 20, UP_Y + 20); // random click.

    std::this_thread::sleep_for(std::chrono::seconds(2));
    Fight::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    //inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey(Set::PODS);
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Fight::AfterFightSit()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey(Set::SIT);
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
            ProspecSet();
        }
    }

    _currentStrategy->PrintStrategyName();

    return _currentStrategy->Execute();
}