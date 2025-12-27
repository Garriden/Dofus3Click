#pragma once

#include "utils.hpp"
//#include "config.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"

/**
 * @file checks.hpp
 * @brief Collection of screen-state checks used to infer game UI state.
 *
 * Each function inspects one or more screen pixels and returns a boolean
 * describing whether a particular UI box or state is visible.
 */

namespace check {

/** @brief True if the player is currently in a fight UI. (or if it is my turn and the bar is green). */
bool IsFight();

/** @brief True if the player's turn is almost finished (turn bar near end, bar orange or red). */
bool IsAlmostTheEndOfTheTurn();

/** @brief True if the player's turn is super mostly finished (turn bar near end, red). */
bool IsTheEndOfTheTurn();

/** @brief True if the PODS (inventory weight) bar is (almost) full. */
bool AmIFull();

/** @brief True when the player's health is (almost) full. */
bool HaveIHealth();

/** @brief True if chat is in private mode (red/green indicator visible). */
bool IsPrivateMode();

/** @brief True when the recall potion icon (ctrl+8 position) is present. */
bool IsRecallPoti();

/** @brief True when the attention dialog/window is visible. */
bool IsAttentionBox();

/** @brief True when the main menu (Esc) dialog is visible. */
bool IsMenuPrincipalBox();

/** @brief True if the post-fight defeat window is visible. */
bool AmIDefeated();

/** @brief True if the post-fight fenix/energy dialog is shown. */
bool IsFenixBox();

/** @brief True if the victory window is visible (player won the fight). */
bool IWonTheFight();

/** @brief True if the fight has finished (won or lost). */
bool IsFightFinished();

/** @brief True if the screen is currently black (transition state). */
bool IsBlackScreen();

/**
 * @brief Check whether the pixel at (x,y) is black within tolerances.
 * @param x X coordinate.
 * @param y Y coordinate.
 * @return bool True if pixel is considered black.
 */
bool IsBlack(int x, int y);

/** @brief True if a level up dialog is visible. */
bool AmILevelUp();

/** @brief True if the bottom menu currently shows spells (not objects). */
bool IsSpellsMenu();

/** @brief True if the first inventory slot is empty. */
bool IsEmptyResource();

/**
 * @brief Wait for a short period watching for the black screen transition
 *        that indicates a map change. Returns true if transition observed.
 */
bool WaitMapToChange();


/** @brief True if bubble information mob. */
bool IsBubble(int x, int y);

/** @brief True if bubble information mob. */
bool IsBubbleBottom(int x, int y);

/** @brief True if bubble information mob. */
bool IsBubbleMiddle(int x, int y);

/** @brief True if bubble information mob. */
bool IsBubbleTop(int x, int y);

}