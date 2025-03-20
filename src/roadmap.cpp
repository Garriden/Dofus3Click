#include "roadmap.hpp"
#include "utils.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "basicOperations.hpp"

void roadmap::ExecuteRoadMap(std::string name)
{
    File::LogFile("  ExecuteRoadMap: " + name, true);
    std::vector<std::vector<std::pair<int, int> > > roadmap = File::ReadFileAndBuildMap(name);

    for(int ii = 0; ii < static_cast<int>(roadmap.size()); ++ii) {
        //File::LogFile("ii: " + std::to_string(ii), true);
        //if(restart_roadmap_) {
        //    return;
        //}
        ClickIdentities(roadmap[ii]);
        //if (restart_roadmap_) {
        //    return;
        //}
    }
}


void roadmap::ClickIdentities(const std::vector<std::pair<int, int> > map)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    int ruletNumber = 1;
    int x = 0;
    int y = 0;

    std::cout << "bbbbbbbb: " <<  map.size() << "    " << map[0].first << " . " << map[0].second << std::endl;
    for(int ii = 0; ii < map.size(); ++ii) {
        File::LogFile("ii: " + std::to_string(ii), true);
        //if(!restart_roadmap_) {
            ruletNumber = basicOperations::RuletaInput(0, 9) + 1;

            //if(DELAY_BETWEEN_CHOPPS_) {
            std::this_thread::sleep_for(std::chrono::seconds(7));
            std::this_thread::sleep_for(std::chrono::milliseconds(ruletNumber * 100));
            //}

            //CheckFight(); TODO

            x = map[ii].first - ruletNumber / 4;
            y = map[ii].second - ruletNumber / 4;

            std::this_thread::sleep_for(std::chrono::milliseconds(100 + ruletNumber) );
            SetCursorPos(x, y);
            mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
            std::this_thread::sleep_for( std::chrono::milliseconds(10 + ruletNumber) );
            mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
        //}
    }

    /**************************************************************
     * Move to the another map.
     *
     * Get the last coordenates from my hardcoded struct, to move to the next map.
     * - It has, in the input sleep variable. Waiting to finish chopping before moving.
     * - It has some other sleep, to wait to upload correctly the new map.
     *
     ***************************************************************/

    //CheckFight();

    //if(AmITalkingWithNPJ() || IsMercant() || IsErrorWindow()) {
    //    PressEscape();
    //    std::this_thread::sleep_for(std::chrono::seconds(7));
    //}

    //if(IsMainMenuWindow()) {
    //    PressEscape();
    //}
/*
    if(lowering_pods_ || (!CheckPods() && !restart_roadmap_)) {
        //LogFile("Change maaaaap");
        Sleep(17 * SECONDS + ruletNumber * 100);

        CheckFight();

        if (IsMercantMode()) {
            PressEscape();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        ruletNumber = Ruleta10();

        x = (map[map.size() - 1].first)  - (ruletNumber / 4);
        y = (map[map.size() - 1].second) - (ruletNumber / 2);

        // Don't hit treasure hunt window 
        if((x < 355) && ((y > 200) && (y < 250))) {
            y = 300;
        }

        // Don't hit office level up window 
        if((x < 355) && ((y > 570) && (y < 715))) {
            y = 750;
        }

        SetCursorPos(x, y);
        Sleep(ruletNumber * 10);

        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        Sleep(ruletNumber);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

        Sleep(3 * SECONDS + ruletNumber * 100);
        
    }
    */
}