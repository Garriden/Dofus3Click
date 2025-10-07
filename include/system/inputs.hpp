#pragma once
#include <iostream>
#include <vector>

/**
 * @file inputs.hpp
 * @brief Wrappers around OS input injection (keyboard/mouse) used by the bot.
 */

namespace inputs {

    /** @brief Gets Windows Version, useful to calculate the taskbar diff. */
    int GetWindowsVersion();

    /**
     * @brief Simulate pressing a single key.
     * @param keyParam Virtual-key code to press.
     */
    void PressKey(int keyParam);

    /**
     * @brief Simulate pressing a special key (page up/down etc.).
     * @param specialKey Virtual-key code.
     */
    void PressSpecialKey(int specialKey);

    /**
     * @brief Simulate pressing a key while holding Ctrl.
     * @param keyParam Virtual-key code.
     */
    void PressCtrlKey(int keyParam);

    /**
     * @brief Simulate pressing a key while holding Shift.
     * @param keyParam Virtual-key code.
     */
    void PressShiftKey(int keyParam);

    /** @brief Simulate pressing the space key. */
    void PressSpace();

    /** @brief Simulate pressing the Escape key. */
    void PressEscape();

    /** @brief Simulate pressing the Enter key. */
    void PressEnter();

    /**
     * @brief Type a string as a sequence of key presses.
     * @param s The string to type.
     */
    void KeyboardWrite(std::string s);

    /**
     * @brief Click near the Dofus executable bar to ensure the game has focus.
     * @return bool True on success.
     */
    bool ClickOnExe();

    /** @brief Start recording actual mouse clicks to build telemetry files. */
    void RecordTelemetry();

    /**
     * @brief Move the cursor to (x,y) and click.
     * @param x X screen coordinate.
     * @param y Y screen coordinate.
     */
    void Click(int x, int y);

    /** @brief Click while holding Shift modifier at (x,y). */
    void ShiftClick(int x, int y);

    /**
     * @brief Double-click at (x,y).
     */
    void DoubleClick(int x, int y);

    /**
     * @brief Change map in the given direction (RIGHT/LEFT/UP/DOWN macros).
     * @param position Direction constant.
     */
    void ChangeMap(int position);

    /**
     * @brief Change the objects menu bar by a number of page changes.
     * @param changes Number of page changes.
     * @param down If true move down (Av Pag), otherwise up.
     */
    void ChangeMenuBar(int changes, bool down);

    /** @brief Switch the bottom menu between spells and objects. */
    void ClickSwitchBottomMenu();

    /** @brief Print or collect debug coordinates for clicks. */
    void DebugPoints();

    /** 
     * @brief Toggle private chat mode by clicking the Green/Red dot in the chat UI. 
     * @return True if Clicked, false if already private.
    */
    bool ClickPrivateMode();

    ////////////////////
    // Fight related helpers
    ////////////////////

    /**
     * @brief Obtain the X coordinate of the player's position in the fight menu.
     * @return int X coordinate used by fight UI helpers.
     */
    int FindMyPosition();

    /**
     * @brief Obtain X coordinates of enemies in the fight menu.
     * @return std::vector<int> Vector of enemy X coordinates.
     */
    std::vector<int> FindEnemiesPositions();
}