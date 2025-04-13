#include "menus.hpp"
#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "roadmap.hpp"
#include "zaap.hpp"
#include "checksRoadmap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void menu::Farmer()
{
    show::FarmerMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("1  = lv.40  [WHE / BAR]    (rincon)", true);
            Roadmap roadmap(Profession::FARMER, "rincon", nullptr, &zaap::CheckZaapRincon,
                {"", "../../Telemetry/Farmer/gobball_lv40.csv"});
            roadmap.Start();
            break;
        }

    }
}

void menu::Wood()
{
    show::WoodMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("lv.1  [ASTRUB] . . . ", true);
            Roadmap roadmap(Profession::WOOD, "astrub", &checkRoadmap::CheckWoodLv1, &zaap::CheckZaapAstrub,
                {"../../Telemetry/Wood/fromAstrubZaapToWoodLv1.csv", "../../Telemetry/Wood/astrubAshLv1.csv"});
            roadmap.Start();
            break;
        }
        case 2:
        {
            File::LogFile("lv.20 [AMAKNA]        (linde) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "linde", &zaap::CheckZaapLinde, &zaap::CheckZaapLinde,
                {"", "../../Telemetry/Wood/fromLindeZaapToWoodLv20.csv", "../../Telemetry/Wood/amaknaCheLv20.csv", 
                 "../../Telemetry/Wood/amaknaWoodTaller.csv", "../../Telemetry/Wood/amaknaCheLv20FromTallerToFinish.csv",
                 "../../Telemetry/Wood/formAmaknaCheLv20FinishToStart.csv"});
            roadmap.Start();
            break;
        }
        case 4:
        {
            File::LogFile("lv.70 [BOMBU]        (llanura) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "puerka", &zaap::CheckZaapPuerkazos, &zaap::CheckZaapPuerkazos,
                {"", "../../Telemetry/Wood/bombu1.csv", "../../Telemetry/Wood/bombu2.csv",  "../../Telemetry/Wood/bombu3.csv",
                     "../../Telemetry/Wood/bombu4.csv", "../../Telemetry/Wood/bombu5.csv"});
            roadmap.Start();
            break;
        }
        case 8:
        {
            File::LogFile("[OTOMAI]         (coast) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "costero", &checkRoadmap::CheckOtomaiCoast, &zaap::CheckZaapOtoCoast,
                {"../../Telemetry/Wood/fromCoastToWoodOtomai.csv", "../../Telemetry/Wood/otomaiWoodCoast.csv", "../../Telemetry/Wood/fromOtomaiCenterToCoastInitial.csv"});
            roadmap.Start();
            break;
        }
        case 9:
        {
            File::LogFile("[OTOMAI]         (all) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "costero", &checkRoadmap::CheckOtomaiCoast, &zaap::CheckZaapOtoCoast,
                {"../../Telemetry/Wood/fromCoastToWoodOtomai.csv", "../../Telemetry/Wood/otomaiWood.csv"});
            roadmap.Start();
            break;
        }
        case 10:
        {
            File::LogFile("[KOALAKS]      (ganaderos) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "ganaderos", &zaap::CheckZaapKoalak, &zaap::CheckZaapKoalak,
                {"../../Telemetry/Wood/fromBreedToWoodKoalak.csv", "../../Telemetry/Wood/koalak.csv", 
                 "../../Telemetry/Wood/kaliptusMiddle.csv", "../../Telemetry/Wood/fromBreedToWoodKoalak.csv"});
            roadmap.Start();
            break;
        }
    }
}


void menu::Mineral()
{
    show::MineralMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("1  = lv.1  [TIRITH]          [-3,9]", true);
            Roadmap roadmap(Profession::MINERAL, "linde", &checkRoadmap::CheckTirith, &zaap::CheckZaapLinde,
                {"../../Telemetry/Mineral/FromEdgeZaapToTirith.csv", "../../Telemetry/Mineral/Tirith.csv", "../../Telemetry/Mineral/FromTirithToEdgeZaap.csv"});
            roadmap.Start();
            break;
        }

    }
}

void menu::Alchemist()
{
    show::AlchemistMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("1 = lv.1                   (Astrub)", true);
            Roadmap roadmap(Profession::ALCHEMIST, "astrub", &zaap::CheckZaapAstrub, &zaap::CheckZaapAstrub,
                {"", "../../Telemetry/Alch/AlchemistAstrub4_-11.csv", "../../Telemetry/Alch/AlchemistAstrubDownToZaap.csv"});
            roadmap.Start();
            break;
        }
        case 2:
        {
            File::LogFile("2 = lv.40                   (Linde)", true);
            Roadmap roadmap(Profession::ALCHEMIST, "linde", &zaap::CheckZaapLinde, &zaap::CheckZaapLinde,
                {"", "../../Telemetry/Alch/AlchemistEdgelv40.csv", /*"../../Telemetry/Alch/amaknaAlchTaller.csv",*/ "../../Telemetry/Alch/AlchemistEdgelv40AfterTaller.csv"});
            roadmap.Start();
            break;
        }
        case 22:
        {
            File::LogFile("22= lv.40                  (rincon)", true);
            Roadmap roadmap(Profession::ALCHEMIST, "rincon", &zaap::CheckZaapRincon, &zaap::CheckZaapRincon,
                {"", "../../Telemetry/Alch/rinconSalvias.csv"});
            roadmap.Start();
            break;
        }
        case 3:
        {
            File::LogFile("3 = lv.80               (Ganaderos)", true);
            Roadmap roadmap(Profession::ALCHEMIST, "ganaderos", &zaap::CheckZaapKoalak, &zaap::CheckZaapKoalak,
                {"", "../../Telemetry/Alch/AlchemistBreederlv80.csv"});
            roadmap.Start();
            break;
        }
        case 5:
        {
            File::LogFile("5 = lv.140                   (Moon)", true);
            Roadmap roadmap(Profession::ALCHEMIST, "moon", &zaap::CheckZaapMoon, &zaap::CheckZaapMoon,
                {"", "../../Telemetry/Alch/Alch/AlchemistMoonlv140.csv"});
            roadmap.Start();
            break;
        }

    }
}

void menu::Fisherman()
{
    show::FishermanMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            break;
        }
        case 2:
        {
            File::LogFile("2 = lv.20           (Golfo Sufokia)", true);
            Roadmap roadmap(Profession::FISHER, "golfo", &zaap::CheckZaapGolfo, &zaap::CheckZaapGolfo,
                {"", "../../Telemetry/Fisher/SufokianShorelinelv40_1.csv", "../../Telemetry/Fisher/SufokianShorelinelv40_2.csv",
                     "../../Telemetry/Fisher/SufokianShorelinelv40_3.csv", "../../Telemetry/Fisher/SufokianShorelinelv40_4.csv"});
            roadmap.Start();
            break;
        }
        case 4:
        {
            File::LogFile("4 = lv.80-120          (Ganaderos)", true);
            Roadmap roadmap(Profession::FISHER, "ganaderos", &checkRoadmap::CheckKoalaksLagos, &zaap::CheckZaapKoalak,
                {"../../Telemetry/Fisher/fromGanaderosTolv80Fish.csv", "../../Telemetry/Fisher/Ganaderoslv80_1.csv", "../../Telemetry/Fisher/Ganaderoslv80_2.csv"});
            roadmap.Start();
            break;
        }


    }
}

void menu::DailyMissions()
{
    show::DailyMissions();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            break;
        }
        case 10:
        {
            File::LogFile("10= [FRIGOST] Fight Club [16kk] (5min) (week)", true);
            Roadmap roadmap(Profession::MISSIONS, "burgo", &zaap::CheckZaapBurgo, &zaap::CheckZaapBurgo,
                {"", "../../Telemetry/Missions/Frigost/FightClub.csv", "../../Telemetry/Missions/Frigost/FightClubAfter.csv"});
            roadmap.Start();
            break;
        }
        case 50:
        {
            File::LogFile("10= [FRIGOST] Fight Club [16kk] (5min) (week)", true);
            Roadmap roadmap(Profession::MISSIONS, "sufokia", &zaap::CheckZaapBurgo, &zaap::CheckZaapBurgo,
                {"", "../../Telemetry/Missions/Frigost/FightClub.csv", "../../Telemetry/Missions/Frigost/FightClubAfter.csv"});
            roadmap.Start();
            break;
        }

        

    }
}

void menu::FindEnemiesMenu()
{
    show::FindEnemiesMenu();

    int in;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("1  = Jabatos               (Astrub)", true);
            Roadmap roadmap(Profession::TRAIN, "astrub", nullptr, &zaap::CheckZaapAstrub, {"../../Telemetry/Train/astrub.csv", ""});
            roadmap.Start();
            break;
        }
        case 2:
        {
            File::LogFile("2  = Abraknidos             (Linde)", true);
            Roadmap roadmap(Profession::TRAIN, "linde", nullptr, &zaap::CheckZaapLinde, {"../../Telemetry/Train/linde.csv", ""});
            roadmap.Start();
            break;
        }
        case 4:
        {
            File::LogFile("4  = Robocops              (Puerka)", true);
            Roadmap roadmap(Profession::TRAIN, "puerka", nullptr, &zaap::CheckZaapPuerkazos, {"../../Telemetry/Train/puerka.csv", ""});
            roadmap.Start();
            break;
        }
        case 6:
        {
            File::LogFile("6  = Cocodrilos         (Ganaderos)", true);
            Roadmap roadmap(Profession::TRAIN, "ganaderos", nullptr, &zaap::CheckZaapKoalak, {"../../Telemetry/Train/cocodrilos.csv", ""});
            roadmap.Start();
            break;
        }
        case 10:
        {
            File::LogFile("10 = Kokokos                 (Moon)", true);
            Roadmap roadmap(Profession::TRAIN, "moon", nullptr, &zaap::CheckZaapMoon, {"../../Telemetry/Train/moon.csv", ""});
            roadmap.Start();
            break;
        }
        case 15:
        {
            File::LogFile("15 = Trools               (Rocosas)", true);
            Roadmap roadmap(Profession::TRAIN, "rocosas", nullptr, &zaap::CheckZaapRocosas, {"../../Telemetry/Train/rocosas.csv", ""});
            roadmap.Start();
            break;
        }
        case 20:
        {
            File::LogFile("20 = Jalamuts               (Burgo)", true);
            Roadmap roadmap(Profession::TRAIN, "burgo", nullptr, &zaap::CheckZaapBurgo, {"../../Telemetry/Train/burgo.csv", ""});
            roadmap.Start();
            break;
        }

        

    }

}