#pragma once

/**
 * @file train.hpp
 * @brief Helpers used by the training logic to move around maps and search cells where the enemies are.
 */

class Train {
    public:
        /**
         * @brief Construct a Train helper.
         */
        Train();

        /**
         * @brief Destroy the Train helper.
         */
        ~Train();

        /**
         * @brief Move the character between four adjacent maps to allow enemy respawns.
         * @return int Status code.
         */
        int IterateBetweenMaps();

        /**
         * @brief Iterate the accessible cells within the current map to find enemies.
         * @return int Status code.
         */
        int IterateCells();

    private:

};