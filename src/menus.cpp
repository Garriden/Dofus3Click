#include "menus.hpp"
#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "roadmap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <iostream>
#include <thread>
#include <chrono>

namespace {
void Astrub()
{
    while(true) {
        if(!inputs::ClickOnExe()) {
            File::LogFile("! Error Cannot find Dofus exe!", true);
            return;
        }
        
        int restartRoadmap = true;
        File::LogFile("lv.1  [ASTRUB] . . . ", true);
        //back_to_starting_roadmap_ = "Wood/fromAstrubZaapToWoodLv1";
        //use_zaap_ = false;

        if(restartRoadmap) {
            restartRoadmap = false;
            //roadmap::ExecuteRoadMap("Wood\\fromAstrubZaapToWoodLv1");
            roadmap::ExecuteRoadMap("../../Telemetry/Wood/fromAstrubZaapToWoodLv1.csv");
        }

        //if(first_time_go_to_initial_map_) {
            //first_time_go_to_initial_map_ = false;

            //Sleep(10 * SECONDS); std::this_thread::sleep_for(std::chrono::seconds(10));
            //PressCtrlKey('3'); // Pods
            std::this_thread::sleep_for(std::chrono::seconds(3));
            //CheckFight();
            //if(!CheckZaapAstrub()) {
            //    PressCtrlKey('0');		// Recall Potion
            //}
            std::this_thread::sleep_for(std::chrono::seconds(2));
            //restart_roadmap_ = false;
            //std::cout << "fromAstrubZaapToWoodLv1" << std::endl;
        //}
        roadmap::ExecuteRoadMap("../../Telemetry/Wood/astrubAshLv1.csv");

        File::LogFile("lv.1  [ASTRUB] [OK]", true);
    }
    //first_time_go_to_initial_map_ = true;
}
}

void menu::Wood()
{
    show::WoodMenu();
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