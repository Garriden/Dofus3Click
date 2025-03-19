#include "menus.hpp"
#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void Astrub()
{
    while(true) {
        int restartRoadmap = false;
        File::LogFile("lv.1  [ASTRUB] . . . ", true);
        //back_to_starting_roadmap_ = "Wood/fromAstrubZaapToWoodLv1";
        //use_zaap_ = false;

        //if(first_time_go_to_initial_map_) {
            //first_time_go_to_initial_map_ = false;
            //ClickOnExe();
            //Sleep(10 * SECONDS); std::this_thread::sleep_for(std::chrono::seconds(1));
            //PressCtrlKey('3'); // Pods
            std::this_thread::sleep_for(std::chrono::seconds(3));
            //CheckFight();
            //if(!CheckZaapAstrub()) {
            //    PressCtrlKey('0');		// Recall Potion
            //}
            std::this_thread::sleep_for(std::chrono::seconds(2));
            //restart_roadmap_ = false;
            //std::cout << "fromAstrubZaapToWoodLv1" << std::endl;
            if(!restartRoadmap) {
                ExecuteRoadMap("Wood/fromAstrubZaapToWoodLv1");
            }
        //}

        if(!restartRoadmap) {
            ExecuteRoadMap("Wood/fromAstrubZaapToWoodLv1");
        }
        File::LogFile("lv.1  [ASTRUB] [OK]", true);
    }
    //first_time_go_to_initial_map_ = true;
}

void Menu::Wood()
{
    Show::WoodMenu();
    //Wood wood();

    int in, x, y;
    std::cin >> in;

    switch(in) {
        case 0:
        default:
            break;

        case 1:
            //wood.Astrub();
            Astrub();
            break;
    }

}