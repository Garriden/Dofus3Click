#include "utils.hpp"
//#include "config.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"

namespace check {
/*
 * Given the colour a specific position, see if it is the unique color to check.
 */

// Look if I am in a fight (or if it is my turn). Check the turn hexa orange "bar".
bool IsFight();

// Look if I am in a fight (or if it is my turn). Check the turn hexa orange "bar" if it is already finished.
bool IsAlmostTheEndOfTheTurn();

// Check if the PODS bar its (almost) full.
bool AmIFull();

// The hearth (life) is (almost) full.
bool HaveIHealth();

//Find the red/green dot in the chat (private mode).
bool IsPrivateMode();

/*
 * Given a color, Check if the Consumable is a Mimilk.
 *
 * in: color, the color of a given pixel.
 */
//bool IsMimilk(COLORREF color);

// Check if the position ctrl + 8 is a recall poti.
bool IsRecallPoti();

/*
 * Given a color, Check if the Consumable is a Bark Potion.
 *
 * in: color, the color of a given pixel.
 */
//bool IsBrakPoti(COLORREF color);

/*
 * Check if I am viewing an error window.
 */
//bool IsErrorWindow();

// Check if is the menu principal box, which it appears when I press Escape.
bool IsMenuPrincipalBox();

/*
 * Given a color, Check if I am on a red cell when preparing the fight.
 *
 * in: color, the color of a given pixel.
 */
//bool IsRedCellPreFight(COLORREF color);

/*
 * Check if I see the rest or sit emote in the first cell of the bar ovjects.
 */
//bool IsTheObjectBarActive();

/*
 * Look if the fight it is already finished. If I lost it
 * Checking if it is visible the postFight defeated window.
 */
bool AmIDefeated();

// Check if after fight, I don't have enery and appears the fenix box.
bool IsFenixBox();

/*
 * Look if the fight it is already finished. If I won it
 * Checking if it is visible the postFight Victory window.
 */
bool IWonTheFight();

// If I won or I lost.
bool IsFightFinished();

// Is the screen black?
bool IsBlackScreen();

/*
 * Given a Coordenate, is that pixel Black ?
 *
 * in: x, Coordenate X.
 * in: Y, Coordenate Y.
 */
bool IsBlack(int x, int y);

// Check if the levelUp window its shown.
bool AmILevelUp();

/*
 * Check if it is showed the dead window.
 */
//bool AmIDead();

/*
 * Check if I am talking with an NPJ.
 */
//bool AmITalkingWithNPJ();

/*
 * Check if I pressed a merchant interface.
 */
//bool IsMercant();

/*
 * Check if I am trying to go into merchant mode.
 */
//bool IsMercantMode();

// Check if the bottom menu is spells menu.
//  I check if the bottom rightmost icon is orange (CaC weapon)
bool IsSpellsMenu();

// Check if the first position in the inventary is empty.
bool IsEmptyResource();

// Active check for some seconds if the blackScreen transition apprears when changing maps.
bool WaitMapToChange();

}