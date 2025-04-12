#pragma once
#include <functional>
#include <string>
#include <vector>

enum Profession {
    WOOD          = 0,
    FARMER        = 1,
    MINERAL       = 2,
    ALCHEMIST     = 3,
    FISHER        = 4,
    LOWERING_PODS = 5,
    TRAIN         = 6,
    GHOST         = 7
};

class Roadmap {
    public:
        Roadmap();
        Roadmap(Profession profession, std::string zaap, 
            std::function<bool()> callbackCheckInitialMap, std::function<bool()> callbackCheckInitialZaap,
            std::vector<std::string> roadmapFiles);
        ~Roadmap();

        int Start();


    private:

        Profession _profession;
        std::string _zaap;
        std::function<bool()> _callbackCheckInitialMap;
        std::function<bool()> _callbackCheckInitialZaap;
        std::vector<std::string> _roadmapFiles;

        enum RoadmapState {
            SET_PODS_SET                = 0,
            CONVERT_RESOURCES           = 1,
            SET_PRIVATE_MODE            = 2,
            CHECK_INITIAL_POSITION      = 3,
            CHECK_ZAAP_POSITION         = 4,
            GO_TO_ZAAP                  = 5,
            GO_TO_INITIAL_MAP           = 6,
            EXECUTE_ROADMAP             = 7,
            TRAIN_MODE                  = 8,
            END_ROADMAP_OK              = 9
        };

        /*
        * Go from map to map following the route. With sleeps.
        *
        * For every map:
        *   - Click all the identities. (hardcoded)
        *   - Move to the another map.
        * 
        * in: name, the file name (.csv) where to pull the telemetry.
        */
        int ExecuteRoadMap(std::string name);

        /*
        * Chop all the identities.
        *
        * Get the all the coordenates (identities location), avoiding the last one (next map move).
        * - Click the first identity, do a small sleep.
        * - Click quickly all the other identities or put a delay between them (DELAY_BETWEEN_CHOPPS).
        *
        * in: map, the vector of Coordenates extracted from telemetry. 
        */
        int ClickIdentities(const std::vector<std::pair<int, int> > map);
        void ChangeObjectsMenu();
        void ChangeSpellsMenu();
        void SetPodsSet();
        void ConvertResources();

        // Go to default zaap (Astrub), and then, transport to the desired zaap.
        void GoToZaap();
};