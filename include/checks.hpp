#include "utils.hpp"
//#include "config.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"

namespace check {
/*
 * Given the colour a specific position, see if it is the unique color to check.
 */

/*
 * Look if I entered in a fight.
 * Check the turn bar (Orange/Yellow).
 * Also, works if it is my turn.
 */
//bool AmIEnteringInAFight();

/*
* Find the red/green dot in the chat (private mode).
*/
//bool FindPrivateMode(COLORREF color);

/*
 * Check if the PODS bar it is almost full.
 */
//bool AmIFull();

/*
 * Given a color, Check if the Consumable is a Mimilk.
 *
 * in: color, the color of a given pixel.
 */
//bool IsMimilk(COLORREF color);

/*
 * Given a color, Check if the Consumable is a Recall Potion.
 *
 * in: color, the color of a given pixel.
 */
//bool IsRecallPoti(COLORREF color);

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

/*
 * Check if is the main menu window, which it appears when I press Escape.
 */
//bool IsMainMenuWindow();

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
 * Look if the fight it is already finished. If I won it.
 * Checking if it is visible the postFight success window.
 */
//bool IsTheFightFinished();

/*
 * Look if the fight it is already finished. If I lost it
 * Checking if it is visible the postFight defeated window.
 */
//bool AmIDefeated();

/*
 * Look if the fight it is already finished. If I won it
 * Checking if it is visible the postFight Victory window.
 */
//bool IWonTheFight();

// Is the screen black?
bool IsBlackScreen();

/*
 * Given a Coordenate, is that pixel Black ?
 *
 * in: x, Coordenate X.
 * in: Y, Coordenate Y.
 */
bool IsBlack(int x, int y);

/*
 * Check if it is showed the levelUp window.
 */
//bool AmILevelUp();

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
 * Check if I have at least 90% health.
 */
//bool HaveIHealth();

/*
 * Check if I am trying to go into merchant mode.
 */
//bool IsMercantMode();
}