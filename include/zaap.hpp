#pragma once

#include "system/inputs.hpp"

/**
 * @file zaap.hpp
 * @brief Helpers to interact with the Zaap teleportation interface.
 *
 * The zaap namespace provides functions to click the zaap UI and to detect
 * whether the player is currently in specific zaap interfaces.
 */

namespace zaap {

    /**
     * @brief Click the current zaap and write the destination zaap name.
     *
     * @param zaapName Name of the destination zaap to type into the UI.
     */
    void TeleportZaap(std::string zaapName);

    /** @brief True if the zaap interface is currently shown. */
    bool CheckZaapInterface();

    /** @brief True if the player is in Astrub zaap. */
    bool CheckZaapAstrub();

    /** @brief True if the player is in Linde zaap. */
    bool CheckZaapLinde();

    /** @brief True if the player is in Puerkazos (Cania) zaap. */
    bool CheckZaapPuerkazos();

    /** @brief True if the player is in Otomai coast zaap. */
    bool CheckZaapOtoCoast();

    /** @brief True if the player is in Koalak zaap. */
    bool CheckZaapKoalak();

    /** @brief True if the player is in Burgo (Frigost) zaap. */
    bool CheckZaapBurgo();

    /** @brief True if the player is in Sepultados (Frigost) zaap. */
    bool CheckZaapSeputados();

    /** @brief True if the player is in Golfo (Sufokia) zaap. */
    bool CheckZaapGolfo();

    /** @brief True if the player is in Sufokia zaap. */
    bool CheckZaapSufokia();

    /** @brief True if the player is in Golfo Sufokia zaap. */
    bool CheckZaapGolfo();

    /** @brief True if the player is in Moon island zaap. */
    bool CheckZaapMoon();

    /** @brief True if the player is in Llanuras Rocosas zaap. */
    bool CheckZaapRocosas();

    /** @brief True if the player is in Rincon zaap. */
    bool CheckZaapRincon();

    /** @brief True if the player is in Kani zaap. */
    bool CheckZaapKani();

}