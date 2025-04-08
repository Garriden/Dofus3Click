#include "roadmap.hpp"
#include "fight.hpp"
#include "utils.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "checksRoadmap.hpp"
#include "zaap.hpp"
#include "train.hpp"

Roadmap::Roadmap() :
    _profession{},
    _zaap{},
    _callbackCheckInitialMap{},
    _callbackCheckInitialZaap{},
    _roadmapFiles{}
{
    std::cout << "Roadmap constructor called" << std::endl;
}

Roadmap::Roadmap(Profession profession, 
                std::string zaap,
                std::function<bool()> callbackCheckInitialMap, 
                std::function<bool()> callbackCheckInitialZaap,
                std::vector<std::string> roadmapFiles) :
    _profession{profession},
    _zaap{zaap},
    _callbackCheckInitialMap{callbackCheckInitialMap},
    _callbackCheckInitialZaap{callbackCheckInitialZaap},
    _roadmapFiles{roadmapFiles}
{
    File::LogFile(("Roadmap started. Profession: " + std::to_string(_profession)).c_str(), true);

    if(_roadmapFiles.size() < 2) {
        File::LogFile("ERROR: _roadmapFiles < 2.  Firt roadmap must be: from zaap to initial position. \
                        And at least have a second roadmap where it does the proper roadmap.", true);
        //return;
    }
}

Roadmap::~Roadmap()
{
    File::LogFile("Roadmap ended!", true);
}

int Roadmap::Start()
{
    int step = RoadmapState::SET_PODS_SET;
    if(_profession == Profession::LOWERING_PODS) {
        step = RoadmapState::CONVERT_RESOURCES;
    }

    if(_callbackCheckInitialMap == nullptr && _callbackCheckInitialZaap == nullptr) {
        step = RoadmapState::EXECUTE_ROADMAP;
    }

    while(1) {
        switch(step) {
        case RoadmapState::SET_PODS_SET:
            SetPodsSet();
            step = RoadmapState::SET_PRIVATE_MODE;
            break;
        case RoadmapState::CONVERT_RESOURCES:
            ConvertResources();
            step = RoadmapState::SET_PRIVATE_MODE;
            break;
        case RoadmapState::SET_PRIVATE_MODE:
            if(!check::IsPrivateMode()) {
                inputs::ClickPrivateMode();
            }
            step = RoadmapState::CHECK_INITIAL_POSITION;
            break;
        case RoadmapState::CHECK_INITIAL_POSITION:
            if(_callbackCheckInitialMap == nullptr || _callbackCheckInitialMap() == _callbackCheckInitialZaap()) {
                step = RoadmapState::CHECK_ZAAP_POSITION;
            } else {
                if(_callbackCheckInitialMap != nullptr && _callbackCheckInitialMap() && _roadmapFiles[0] != "") {
                    step = RoadmapState::EXECUTE_ROADMAP;
                } else {
                    step = RoadmapState::CHECK_ZAAP_POSITION;
                }
            }
            break;
        case RoadmapState::CHECK_ZAAP_POSITION:
            if(_callbackCheckInitialZaap()) {
                step = RoadmapState::GO_TO_INITIAL_MAP;
            } else {
                step = RoadmapState::GO_TO_ZAAP;
            }
            break;
        case RoadmapState::GO_TO_ZAAP:
            GoToZaap();
            step = RoadmapState::GO_TO_INITIAL_MAP;
            break;
        case RoadmapState::GO_TO_INITIAL_MAP:
            if(_roadmapFiles[0] != "") {
                ExecuteRoadMap(_roadmapFiles[0]);
            }

            if(_profession == Profession::TRAIN) {
                step = RoadmapState::TRAIN_MODE;
            } else {
                step = RoadmapState::EXECUTE_ROADMAP;
            }
            break;
        case RoadmapState::EXECUTE_ROADMAP:
        {
            int roadmapExecution = E_KO;
            for(int roadmapIndex = 1; roadmapIndex < _roadmapFiles.size(); ++roadmapIndex) {
                roadmapExecution = ExecuteRoadMap(_roadmapFiles[roadmapIndex]);
                if(roadmapExecution == E_KO) {
                    step = SET_PODS_SET; //-1;
                    break;
                } else if(roadmapExecution == E_NEED_TO_RESTART) {
                    step = SET_PODS_SET;
                    break;
                }
                //step = RoadmapState::AFTER_FIGHT_SET;
            }

            if(roadmapExecution == E_OK) {
                if(Profession::LOWERING_PODS == _profession) {
                    return E_NEED_TO_RESTART;
                } else if(Profession::GHOST == _profession) {
                    step = RoadmapState::END_ROADMAP_OK;
                } else if(_callbackCheckInitialMap()) {
                    step = RoadmapState::EXECUTE_ROADMAP;
                } else if(_callbackCheckInitialZaap()) {
                    step = RoadmapState::GO_TO_INITIAL_MAP;
                }
            }

            break;
        }
        case RoadmapState::TRAIN_MODE:
        {
            Train train;
            if(train.IterateBetweenMaps() == E_IM_A_GHOST) {
                std::string ghostRoadmap = "../../Telemetry/Ghost/" + _zaap + ".csv";
                Roadmap roadmap(Profession::GHOST, _zaap, nullptr, nullptr, {ghostRoadmap, ghostRoadmap});
                roadmap.Start();

                step = RoadmapState::SET_PODS_SET;
            } else {
                step = RoadmapState::TRAIN_MODE;
            }
            break;
        }
        case RoadmapState::END_ROADMAP_OK:
        default:
            return E_KO;
            break;
        }
    }

}

int Roadmap::ExecuteRoadMap(std::string name)
{
    File::LogFile("ExecuteRoadMap: " + name, true);
    std::vector<std::vector<std::pair<int, int> > > roadmap = File::ReadFileAndBuildMap(name);

    for(int ii = 0; ii < static_cast<int>(roadmap.size()); ++ii) {
        File::LogFile("map: " + std::to_string(ii), true);
        int returnError = ClickIdentities(roadmap[ii]);
        if(E_OK != returnError) {
            return returnError;
        }
    }

    return E_OK;
}

int Roadmap::ClickIdentities(const std::vector<std::pair<int, int> > map)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    int ruletNumber = 1;
    int x = 0;
    int y = 0;

    for(int ii = 0; ii < map.size(); ++ii) {
        ruletNumber = basicOperations::RuletaInput(0, 9) + 1;

        if(ii == 0) { // Already changed map.
            //std::this_thread::sleep_for(std::chrono::seconds(1));
            std::this_thread::sleep_for(std::chrono::milliseconds(ruletNumber * 100));
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(8));
            std::this_thread::sleep_for(std::chrono::milliseconds(ruletNumber * 100));
        }

        if(check::IsFight()) {
            Fight fight;
            int fightReturn = fight.Start();

            if(E_KO == fightReturn) {
                File::LogFile("Fight LOST!", true);
                return E_KO;
            } else if(E_IM_A_GHOST == fightReturn) { // I'm a Ghost
                File::LogFile("I'm a Ghost... Starting roadmap to fenix", true);
                Roadmap roadmap(Profession::GHOST, _zaap, nullptr, nullptr, {"../../Telemetry/Ghost/astrub.csv", ""});
                roadmap.Start();
            }
        }

        if(_profession != Profession::LOWERING_PODS && check::AmIFull()) {
            Roadmap goToBank(Profession::LOWERING_PODS, "", &zaap::CheckZaapAstrub, &zaap::CheckZaapAstrub,
                {"", "../../Telemetry/ZaapToBank/astrubBankTransaction.csv", "../../Telemetry/ZaapToBank/fromAstrubZaapToBank.csv"});
            return goToBank.Start();
        }

        //std::cout << "cord: " <<  map.size() << "    " << map[ii].first << " . " << map[ii].second << std::endl;
        if(map[ii].first == INPUT_PATTERN_CHARACTER) {
            inputs::PressKey(map[ii].second);
        } else if(map[ii].first == INPUT_PATTERN_ESC) {
            inputs::PressEscape();
        } else if(map[ii].first == INPUT_PATTERN_CTRL) {
            inputs::PressCtrlKey(map[ii].second);
        } else { // normal coordenate value
            inputs::Click(map[ii].first, map[ii].second);
        }
    }

    // Change map
    // Sometimes it doesn't change propperly because of "Acción imposible" Dofus error...
    // Catch when screen goes black to detect the map change. Repeat last click if not changed properly.

    // Wait for Black Screen
    bool mapChanged = false;
    int retries = 0;
    while(!mapChanged && retries++ < 10) {
        mapChanged = check::WaitMapToChange();
        if(!mapChanged) {
            inputs::Click(map[map.size()-1].first, map[map.size()-1].second);
        }
    }

    if(retries >= 10) {
        File::LogFile("Stuck! So many retries for invalid action...", true);
        return E_KO;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    if(check::IsFight()) {
        Fight fight;
        int fightReturn = fight.Start();

        if(E_KO == fightReturn) {
            File::LogFile("Fight LOST!", true);
            return E_KO;
        } else if(E_IM_A_GHOST == fightReturn) { // I'm a Ghost
            File::LogFile("I'm a Ghost... Starting roadmap to fenix", true);
            Roadmap roadmap(Profession::GHOST, _zaap, nullptr, nullptr, {"../../Telemetry/Ghost/astrub.csv", ""});
            roadmap.Start();
        }
    }

    if(!mapChanged) { // Invalid action, try again.
        File::LogFile(" NO! mapChanged... Clicking again...", true);
        inputs::Click(map[map.size()-1].first, map[map.size()-1].second + retries);
        ++retries;
    }

    return E_OK;
}

// Todo: sned to inputs
void Roadmap::ChangeObjectsMenu()
{
    if(check::IsSpellsMenu()) {
        inputs::ClickSwitchBottomMenu();
    } else {
        //File::LogFile("Already Objects menu.", true);
    }
}

void Roadmap::ChangeSpellsMenu()
{
    if(check::IsSpellsMenu()) {
        //File::LogFile("Already Spells menu.", true);
    } else {
        inputs::ClickSwitchBottomMenu();
    }

}

void Roadmap::SetPodsSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Roadmap::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('3'); // Pods Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Roadmap::ConvertResources()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressKey('i');
    std::this_thread::sleep_for(std::chrono::seconds(1));

    inputs::Click(INVENTARY_CONVERT_RESOURCES_X_1, INVENTARY_CONVERT_RESOURCES_Y_1);
    inputs::Click(INVENTARY_CONVERT_RESOURCES_X_2, INVENTARY_CONVERT_RESOURCES_Y_2);
    inputs::Click(INVENTARY_CONVERT_RESOURCES_X_3, INVENTARY_CONVERT_RESOURCES_Y_3);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::KeyboardWrite("saco");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    while(!check::IsEmptyResource()) {
        inputs::DoubleClick(INVENTARY_CONVERT_RESOURCES_X_4, INVENTARY_CONVERT_RESOURCES_Y_4);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressEscape();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Roadmap::GoToZaap()
{
    File::LogFile("Going to initial Zaap ... ", true);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    if(!zaap::CheckZaapAstrub()) {
        inputs::PressCtrlKey('8'); // Recall Poti.
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));

    if(zaap::CheckZaapAstrub() && _zaap == "astrub") {
        return;
    } else if(zaap::CheckZaapAstrub() && _zaap != "astrub") {
        zaap::ClickZaap(_zaap);
    } else { // not in Astrub ?
        for(int ii = 0; !zaap::CheckZaapAstrub() && ii < 20; ++ii) {
            if(zaap::CheckZaapInterface()) {
                File::LogFile("I'm at Astrub zaap ZaapInterface ", true);
                inputs::PressEscape();
                break;
            } else {
                File::LogFile("Watch out! I'm not at Astrub zaap and I should be... ", true);
            
                std::this_thread::sleep_for(std::chrono::seconds(60));
            }
        }
        inputs::PressCtrlKey('8'); // Recall Poti.
        std::this_thread::sleep_for(std::chrono::seconds(10));
        zaap::ClickZaap(_zaap);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
}