#pragma once
#include "utils.hpp"
//#include "Config.h"
//#include "Logs.h"
#include <windows.h>

/**
 * @file basicOperations.hpp
 * @brief Low-level screen and input helper functions used across the project.
 *
 * Contains helpers for reading screen pixels and generating random values.
 */

namespace basicOperations {

    /**
     * @brief Generate a pseudo-random integer in the inclusive range [min, max].
     *
     * This helper is used by menus and non-critical codepaths that need a
     * bounded random value.
     *
     * @param min Minimum value in the range.
     * @param max Maximum value in the range.
     * @return int Random value between min and max inclusive.
     */
    int RuletaInput(int min, int max);

    /**
     * @brief Read the color of the pixel at screen coordinates (x, y).
     *
     * @param x X coordinate in screen space.
     * @param y Y coordinate in screen space.
     * @param printRGB If true, print the RGB value to stdout for debugging.
     * @return COLORREF The RGB color of the pixel packed in a COLORREF.
     */
    COLORREF GetColor(int x, int y, bool printRGB);

}