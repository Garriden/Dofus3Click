#pragma once

#include "utils.hpp"
//#include "config.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"

/**
 * @file checksRoadmap.hpp
 * @brief Helpers to detect if the player is on a known roadmap starting map.
 *
 * These functions detect specific maps used as starting points for
 * resource-gathering roadmaps so the Roadmap class can make decisions.
 */

namespace checkRoadmap {

    /** @brief True if the player is in the Wood level-1 starting roadmap [0,-18]. */
    bool CheckWoodLv1();

    /** @brief True if the player is in the Otomai coast starting roadmap [-48,-19]. */
    bool CheckOtomaiCoast();

    /** @brief True if the player is in the Koalak lake starting roadmap [-16,-3]. */
    bool CheckKoalaksLagos();

    /** @brief True if the player is in the Koalak wood starting roadmap [-11,1]. */
    bool CheckKoalaksWood();

    /** @brief True if the player is in the Tirith starting roadmap [-3,9]. */
    bool CheckTirith();

    /** @brief True if the player is in the Alamo (Frigost) starting roadmap [-75,-49]. */
    bool CheckAlamo();
}