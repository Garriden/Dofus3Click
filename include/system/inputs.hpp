#pragma once
#include <iostream>
#include <vector>
//#include "Utils.h"
//#include "Config.h"
//#include "BasicOperations.h"
//#include "Menus.h"

namespace inputs {
    /*
    * Simulates a key pressing.
    *
    * in: keyParam, key desired to press.
    */
    void PressKey(int keyParam);

    /*
    * Simulates a key pressing + Ctrl key pressing.
    *
    * in: keyParam, key desired to press, besides the Ctrl key.
    */
    void PressCtrlKey(int keyParam);

    /*
    * Simulates a key pressing, keeps it pressed.
    *
    * in: keyParam, key desired to press.
    */
    //void KeepKeyPressed(int keyParam);

    /*
    * Simulates a key release.
    *
    * in: keyParam, key desired to release.
    */
    //void ReleaseKeyPressed(int keyParam);

    /*
    * Simulates a space key pressing.
    */
    //void PressSpace();

    /*
    * Simulates an escape key pressing.
    */
    //void PressEscape();

    /*
    * Simulates an enter key pressing.
    */
    //void PressEnter();

    /*
    * Simulate an execution of different sequencial keys.
    * Useful to write things.
    *
    * in: s, string desired to write.
    */
    //void KeyboardWrite(std::string s);

    // Do a Click a little bit on the Dofus executable bar.
    bool ClickOnExe();

    /*
    * Get all the characters inside a .txt, given a file.
    *
    * in: file_name, the name of the desired file.
    */
    //std::string getTxt(std::string file_name);

    /*
    * Find the desired file .txt to extract his charactes.
    *
    * in: file_name, the name of the desired file.
    */
    //std::string GetTxtFile(std::string file_name);

    /*
    * Click the OK button in the levelUp window.
    */
    //void ClickLevelUpOk();

    /*
    * Click the OK button in the dead window.
    */
    //void ClickDeadOk();

    /*
    * Click the OK button in the error window.
    */
    //void ClickErrorWindowOk();

    /*
    * Start recording real Clicks. Check menu telemetry for more information.
    */
    void RecordTelemetry();

    /*
    * Set the cursor and click the position I want.
    *
    * in: x and y coordenates.
    */
    void Click(int x, int y);

    /*
    * Change the map in the desired direction.
    *
    * in: position, RIGHT, LEFT, UP, DOWN.
    */
   void ChangeMap(int position);

    /*
    * Give information of the coordenates of real clicks.
    */
    void DebugPoints();

    /*
    * Find the red/green dot in the chat (private mode).
    */
    //bool FindPrivateMode(COLORREF color);
}