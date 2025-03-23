#include "fight.hpp"
#include "basicOperations.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"

Fight::Fight() :
    _turn(0) 
{
    std::cout << "Fight constructor called" << std::endl;
}

Fight::Fight(int turn) :
    _turn(turn) 
{
    std::cout << "Fight constructor 2 called" << std::endl;
}

Fight::~Fight()
{
    std::cout << "Fight destructor called" << std::endl;
}

void Fight::Start()
{
    int step = FightPreparationState::FIGHT_SET;

    while(1) {
        switch(step) {

        case FightPreparationState::FIGHT_SET:
            FightSet();
            
            step = FightPreparationState::CHANGE_SPELLS_MENU;
            break;

        default:
            return;
            break;
        }
    }

}

void Fight::FightSet()
{
    // Objects menu
    // TODO: atajo teclado.
    int x = MENU_BAR_ARROW_DOWN_POS_X; // up down
    int y = MENU_BAR_ARROW_DOWN_POS_Y;

    inputs::Click(x, y);


    std::this_thread::sleep_for(std::chrono::seconds(2));
    File::LogFile("FightSet", true);
    inputs::PressCtrlKey('4'); // Fight Set
    std::this_thread::sleep_for(std::chrono::seconds(2));

}