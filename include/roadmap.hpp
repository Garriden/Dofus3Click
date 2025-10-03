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
    GHOST         = 7,
    MISSIONS      = 8
};

class Roadmap {
    public:
        /** @brief Default constructor. */
        Roadmap();

        /**
         * @brief Construct a Roadmap controller.
         * @param profession Profession enum for which the roadmap will run.
         * @param zaap Name of the zaap to use for transport.
         * @param callbackCheckInitialMap Function used to validate initial map.
         * @param callbackCheckInitialZaap Function used to validate initial zaap.
         * @param roadmapFiles Vector of roadmap file names (CSV) to execute.
         */
        Roadmap(Profession profession, std::string zaap, 
            std::function<bool()> callbackCheckInitialMap, std::function<bool()> callbackCheckInitialZaap,
            std::vector<std::string> roadmapFiles);

        /** @brief Destructor. */
        ~Roadmap();

        /**
         * @brief Start executing the roadmap flow.
         * @return int Status code (E_OK on success).
         */
        int Start();


    private:

        Profession _profession;
        std::string _zaap;
        std::function<bool()> _callbackCheckInitialMap;
        std::function<bool()> _callbackCheckInitialZaap;
        std::vector<std::string> _roadmapFiles;

        /**
         * @enum RoadmapState
         * @brief Internal states used while executing a roadmap.
         */
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

        /**
        * @brief Execute a single roadmap file (.csv) by visiting every map,
        *        clicking the recorded identities, and change map.
        *
        * @param name File name of the csv telemetry for the roadmap.
        * @return int Status code.
        */
        int ExecuteRoadMap(std::string name);

        /**
        * @brief Click all resource identities in a map (except last which is the
        *        next-map transition point).
        *
        * @param map Vector of (x,y) coordinates representing identities.
        * @return int Status code.
        */
        int ClickIdentities(const std::vector<std::pair<int, int> > map);

        /** @brief If it is the spells menu, change it to the objects menu. */
        void ChangeObjectsMenu();

        /** @brief If it is the objects menu, change it to the spells menu. */
        void ChangeSpellsMenu();

        /** @brief Click the Pods set. (The predefined hardcoded set to carry more load while doing the roadmap). */
        void SetPodsSet();

        /** @brief Enter the inventary and convert all the consumables into resources. */
        void ConvertResources();

        /** @brief Go to the default zaap (Astrub) then teleport to the configured zaap. */
        void GoToZaap();
};