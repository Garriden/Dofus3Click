#pragma once

/**
 * @file menus.hpp
 * @brief Top-level menu rendering helpers used by the interactive UI (terminal).
 */

namespace menu {

    /** @brief Show the Farmer menu and handle user selections. */
    void Farmer();

    /** @brief Show the Wood gathering menu and handle selections. */
    void Wood();

    /** @brief Show the Mineral gathering menu and handle selections. */
    void Mineral();

    /** @brief Show the Alchemist menu and handle selections. */
    void Alchemist();

    /** @brief Show the Fisherman menu and handle selections. */
    void Fisherman();

    /** @brief Show the Daily Missions menu screen. */
    void DailyMissions();

    /** @brief Show the Find Enemies / Roadmap menu and handle selections. */
    void FindEnemiesMenu();
}