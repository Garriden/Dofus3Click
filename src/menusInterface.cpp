#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"
#include <iostream>

void show::MainMenu()
{
    system("TITLE Click Bot");
    File::LogFile("===================================", true);
    std::cout << "1  = DEBUG points" << std::endl;
    std::cout << "2  = FARMER" << std::endl;
    std::cout << "3  = WOOD" << std::endl;
    std::cout << "4  = MINERAL" << std::endl;
    std::cout << "5  = ALCHEMIST" << std::endl;
    std::cout << "6  = FISHERMAN" << std::endl;
    std::cout << "9  = Daily missions" << std::endl;
    std::cout << "10 = Find enemies" << std::endl;
    std::cout << "11 = Find enemies here" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "99= DEBUG" << std::endl;
    std::cout << "0 = EXIT" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::MenuDebugPoints()
{
    system("TITLE Debug points");
    std::cout << "===================================" << std::endl;
    std::cout << "press CTRL  to get a point" << std::endl;
    std::cout << "press SHIFT to record telemetry" << std::endl;
    std::cout << "  - Click to save the point" << std::endl;
    std::cout << "  - SPACE to change map (subvector)" << std::endl;
    std::cout << "  - ESC   to end the telemetry" << std::endl;
    std::cout << "  - You can put numpads numbers" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::DailyMissions()
{
    system("TITLE Daily missions");
    std::cout << "==============================================" << std::endl;
    std::cout << "0 = All of them" << std::endl;
    std::cout << "1 = All of them + week" << std::endl;
    std::cout << "5 = [ANKAMA]  Capitan    [0kk]  (5min) (daily)" << std::endl;
    std::cout << "10= [FRIGOST] Fight Club [16kk] (5min) (week) " << std::endl;
    std::cout << "50= [SUFOKIA] Fight Club [16kk] (5min) (week) " << std::endl;
    std::cout << "==============================================" << std::endl;
}

void show::WoodMenu()
{
    system("TITLE Wood menu");
    std::cout << "===================================" << std::endl;
    std::cout << "1  = lv.1  [ASTRUB]        (Astrub)" << std::endl;
    std::cout << "2  = lv.20 [AMAKNA]         (Linde)" << std::endl;
    std::cout << "4  = lv.70 [BOMBU]        (Llanura)" << std::endl;
    std::cout << "8  = [OTOMAI | Coast]     (Costero)" << std::endl;
    std::cout << "9  = [OTOMAI | ALL]       (Costero)" << std::endl;
    std::cout << "10 = [KOALAK]           (Ganaderos)" << std::endl;
    std::cout << "20 = [FRIGOST]              (Burgo)" << std::endl;
    std::cout << "25 = [FRIGOST]         (Sepultados)" << std::endl;
    std::cout << "0  = Back to main menu"              << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::MineralMenu()
{
    system("TITLE Mineral menu");
    std::cout << "===================================" << std::endl;
    std::cout << "1  = lv.1  [TIRITH]          [-3,9]" << std::endl;
    std::cout << "0  = Back to main menu" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::FarmerMenu()
{
    system("TITLE Farmer menu");
    std::cout << "===================================" << std::endl;
    std::cout << "1  = lv.40  [WHE / BAR]    (rincon)" << std::endl;
    std::cout << "8  = lv.200 [FROSTIZZ]      (burgo)" << std::endl;
    std::cout << "0  = Back to main menu" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::AlchemistMenu()
{
    system("TITLE Alchemist menu");
    std::cout << "===================================" << std::endl;
    std::cout << "1 = lv.1                   (Astrub)" << std::endl;
    std::cout << "2 = lv.40                   (Linde)" << std::endl;
    std::cout << "22= lv.40                  (rincon)" << std::endl;
    std::cout << "3 = lv.80               (Ganaderos)" << std::endl;
    //std::cout << "4 = lv.120                [PANDALA]" << std::endl;
    std::cout << "5 = lv.140                  X(Moon)" << std::endl;
    std::cout << "0 = Back to main menu" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::FishermanMenu()
{
    system("TITLE Fisherman menu");
    std::cout << "===================================" << std::endl;
    //std::cout << "1 = lv.1                   [ASTRUB]" << std::endl;
    std::cout << "2 = lv.20           (Golfo Sufokia)" << std::endl;
    std::cout << "4 = lv.80-120           (Ganaderos)" << std::endl;
    //std::cout << "4 = lv.120                [PANDALA]" << std::endl;
    std::cout << "0 = Back to main menu" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::FindEnemiesMenu()
{
    system("TITLE Find enemies menu");
    std::cout << "===================================" << std::endl;
    std::cout << "1  = Jabatos               (Astrub)" << std::endl;
    std::cout << "2  = Abraknidos             (Linde)" << std::endl;
    std::cout << "4  = Robocops              (Puerka)" << std::endl;
    std::cout << "6  = Cocodrilos         (Ganaderos)" << std::endl;
    std::cout << "10 = Kokokos                X(Moon)" << std::endl;
    std::cout << "15 = Trools              X(Rocosas)" << std::endl;
    std::cout << "20 = Jalamuts               (Burgo)" << std::endl;
    std::cout << "===================================" << std::endl;
}

void show::AskPj()
{/*
    int x;

    system("TITLE Click Bot");
    std::cout << "===================================" << std::endl;
    std::cout << "Which Pj are you playing" << std::endl;
    std::cout << "1 = FECA" << std::endl;
    std::cout << "2 = ENU" << std::endl;
    std::cout << "3 = CRA" << std::endl;
    std::cout << "===================================" << std::endl;

    std::cin >> x;

    if (x == 2) {
        current_pj_ = "ENU";
    }
    else if (x == 3) {
        current_pj_ = "CRA";
    }
*/
}

void show::Heal()
{/*
    system("TITLE Heal?");
    std::cout << "Do you want to heal \n";
    std::cout << "between fights?\n";
    std::cout << "(1/0)\n";
    int x;
    std::cin >> x;
    if (x != 0) {
        heal_ = true;
    }*/
}

void show::WhereAreYouUbicated()
{/*
    system("TITLE Where are you?");

    std::cout << "------------------ \n";
    std::cout << "Where are you? \n";
    std::cout << "0 = Astrub \n";
    std::cout << "1 = Gobball \n";
    std::cout << "2 = Champs \n";
    std::cout << "3 = Cania Massif Robots \n";
    std::cout << "4 = Dune \n";
    std::cout << "xx= Otomai \n";

    int x;
    std::cin >> x;
    if(x == 1) {
        zaap_file_ = "ZaapToZaap/gobball";
    } else if(x == 2) {
        zaap_file_ = "ZaapToZaap/gobball";
    } else if(x == 3) {
        zaap_file_ = "ZaapToZaap/CaniaMassif";
    } else if(x == 4) {
        zaap_file_ = "ZaapToZaap/Dune";
    } else if(x == 88) {
        zaap_file_ = "ZaapToZaap/coastOto";
    }

    go_kill_monsters_ = x;*/
}

void show::FindEnemiesMenuGetRoadmap()
{/*
    system("TITLE Find enemies menu");
    std::cout << "Give me the number of \n";
    std::cout << "rows and columns that you\n";
    std::cout << "want to follow.\n";
    std::cout << "From right to left.\n";
    std::cout << "From down to up\n";
    std::cout << "x: ";
    std::cin >> x_roadmap_;
    std::cout << "y: ";
    std::cin >> y_roadmap_;*/
}
