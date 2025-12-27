#pragma once

/**
 * @file menusInterface.hpp
 * @brief Visual/CLI helpers to display the different menus and helper screens on the terminal.
 */

namespace show {

    /** @brief Display the main program menu. */
    void MainMenu();

    /** @brief Display debugging points / coordinates for telemetry recording. */
    void MenuDebugPoints();

    /** @brief Display the daily missions menu. */
    void DailyMissions();

    /** @brief Display the wood profession menu. */
    void WoodMenu();

    /** @brief Display the mineral profession menu. */
    void MineralMenu();

    /** @brief Display the farmer profession menu. */
    void FarmerMenu();

    /** @brief Display the alchemist profession menu. */
    void AlchemistMenu();

    /** @brief Display the fisherman profession menu. */
    void FishermanMenu();

    /** @brief Display the select pj menu. */
    void SelectPjMenu();

    /** @brief Display the find-enemies menu. */
    void FindEnemiesMenu();
}