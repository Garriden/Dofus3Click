#include "menus.hpp"
#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"
#include <iostream>

void Astrub()
{
    while(true) {
        restart_roadmap_ = false;
        File::LogFile("lv.1  [ASTRUB] . . . ");
        //back_to_starting_roadmap_ = "Wood/fromAstrubZaapToWoodLv1";
        use_zaap_ = false;

        if(first_time_go_to_initial_map_) {
            first_time_go_to_initial_map_ = false;
            ClickOnExe();
            Sleep(10 * SECONDS);
            PressCtrlKey('3'); // Pods
            Sleep(3 * SECONDS);
            CheckFight();
            if(!CheckZaapAstrub()) {
                PressCtrlKey('0');		// Recall Potion
            }
            Sleep(2 * SECONDS);
            restart_roadmap_ = false;
            std::cout << "fromAstrubZaapToWoodLv1" << std::endl;
            if(!restart_roadmap_) ExecuteRoadMap("Wood/fromAstrubZaapToWoodLv1");
        }

        std::cout << "astrubAshLv1" << std::endl;
        if(!restart_roadmap_) ExecuteRoadMap("Wood/astrubAshLv1");

        LogFile("[ASTUB] [OK]");
    }
    first_time_go_to_initial_map_ = true;
}

void Menu::Wood()
{
    Show::WoodMenu();
    Wood wood();

    int in, x, y;
    std::cin >> in;

    switch(in) {
        case 0:
        default:
            break;

        case 1:
            wood.astrub();
            break;
    }

}