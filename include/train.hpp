#pragma once

class Train {
    public:
        Train();
        ~Train();

        // Iterate between the four adjacent maps to let respawn the enemies.
        int IterateBetweenMaps();

        // In a map, iterate all the cells to find posible enemies.
        int IterateCells();

    private:

};