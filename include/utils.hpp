#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>
#include <TlHelp32.h> 

#define SECONDS (1000)

#define LIMIT_CELL_Y_MIN                                (80)
#define LIMIT_CELL_Y_MAX                                (880)
#define LIMIT_CELL_X_MIN                                (400)
#define LIMIT_CELL_X_MAX                                (1515)

#define UP                                              (0)
#define DOWN                                            (1)
#define LEFT                                            (2)
#define RIGHT                                           (3)

#define UP_X                                            (800)
#define UP_Y                                            (30)
#define DOWN_X                                          (989)
#define DOWN_Y                                          (908)
#define LEFT_X                                          (346)
#define LEFT_Y                                          (531)
#define RIGHT_X                                         (1575)
#define RIGHT_Y                                         (511)


///////////////////////////////////////////////////////////
// SCREEN POSITIONS
///////////////////////////////////////////////////////////

#define DOFUS_EXE_POS_X_1                                  (130)
#define DOFUS_EXE_POS_Y_1                                  (1064)
#define DOFUS_EXE_POS_COLOR_RED_1                          (241)
#define DOFUS_EXE_POS_COLOR_GREEN_1                        (247)
#define DOFUS_EXE_POS_COLOR_BLUE_1                         (120)
#define DOFUS_EXE_POS_COLOR_RED_2                          (222)
#define DOFUS_EXE_POS_COLOR_GREEN_2                        (255)
#define DOFUS_EXE_POS_COLOR_BLUE_2                         (123)

#define BLACK_SCREEN_POS_X_1                               (850)
#define BLACK_SCREEN_POS_Y_1                               (850)
#define BLACK_SCREEN_POS_X_2                               (1200)
#define BLACK_SCREEN_POS_Y_2                               (350)
#define BLACK_SCREEN_POS_X_3                               (700)
#define BLACK_SCREEN_POS_Y_3                               (700)
#define BLACK_SCREEN_POS_X_4                               (1200)
#define BLACK_SCREEN_POS_Y_4                               (725)
#define BLACK_SCREEN_POS_X_5                               (800)
#define BLACK_SCREEN_POS_Y_5                               (500)
#define BLACK_SCREEN_POS_X_6                               (1000)
#define BLACK_SCREEN_POS_Y_6                               (400)
#define BLACK_SCREEN_POS_X_7                               (1100)
#define BLACK_SCREEN_POS_Y_7                               (550)
#define BLACK_SCREEN_POS_X_8                               (1200)
#define BLACK_SCREEN_POS_Y_8                               (560)

///////////////////////////////////
// BOTTOM MENU
///////////////////////////////////

#define IS_ORANGE_CAC_WEAPON_POS_X_1                              (1129)
#define IS_ORANGE_CAC_WEAPON_POS_Y_1                              (1003)
#define IS_ORANGE_CAC_WEAPON_POS_X_2                              (1127)
#define IS_ORANGE_CAC_WEAPON_POS_Y_2                              (1013)
#define IS_ORANGE_CAC_WEAPON_POS_X_3                              (1158)
#define IS_ORANGE_CAC_WEAPON_POS_Y_3                              (1031)
#define IS_ORANGE_CAC_WEAPON_COLOR_RED                            (252) //exact
#define IS_ORANGE_CAC_WEAPON_COLOR_GREEN                          (140) // 128-150
#define IS_ORANGE_CAC_WEAPON_COLOR_BLUE                           (60)  // 46 - 68

#define SWITCH_BOTTOM_MENU_POS_X_1                                (1217)
#define SWITCH_BOTTOM_MENU_POS_Y_1                                (997)

///////////////////////////////////
// COLOR
///////////////////////////////////

#define BLACK_COLOR_RED                                    (0)
#define BLACK_COLOR_GREEN                                  (0)
#define BLACK_COLOR_BLUE                                   (0)


///////////////////////////////////
// FIGHT
///////////////////////////////////

#define IT_IS_MY_TURN_POS_X_1                              (1324)
#define IT_IS_MY_TURN_POS_Y_1                              (912)
#define IT_IS_MY_TURN_POS_X_2                              (1318)
#define IT_IS_MY_TURN_POS_Y_2                              (915)
#define IT_IS_MY_TURN_POS_X_3                              (1336)
#define IT_IS_MY_TURN_POS_Y_3                              (904)
#define IT_IS_MY_TURN_POS_X_4                              (1334)
#define IT_IS_MY_TURN_POS_Y_4                              (905)
#define IT_IS_MY_TURN_COLOR_RED                            (236)
#define IT_IS_MY_TURN_COLOR_GREEN                          (173)
#define IT_IS_MY_TURN_COLOR_BLUE                           (85)

#define ACCEPT_RETO_POS_X                                  (186)
#define ACCEPT_RETO_POS_Y                                  (363)

#define FIGTH_MENU_FRIEND_POS_X                            (750) // Depending of the enemies on a fight
#define FIGTH_MENU_FRIEND_POS_Y                            (60)

#define FIGTH_MENU_FRIEND_COLOR_RED                        (62)
#define FIGTH_MENU_FRIEND_COLOR_GREEN                      (102)
#define FIGTH_MENU_FRIEND_COLOR_BLUE                       (131)
#define FIGTH_MENU_FRIEND_TURN_COLOR_RED                   (129)
#define FIGTH_MENU_FRIEND_TURN_COLOR_GREEN                 (155)
#define FIGTH_MENU_FRIEND_TURN_COLOR_BLUE                  (174)

#define FIGTH_MENU_ENEMY_COLOR_RED                         (117)
#define FIGTH_MENU_ENEMY_COLOR_GREEN                       (80)
#define FIGTH_MENU_ENEMY_COLOR_BLUE                        (84)


///////////////////////////////////
// AFTER FIGHT
///////////////////////////////////

#define I_WON_THE_FIGHT_POS_X_1                         (1038)
#define I_WON_THE_FIGHT_POS_Y_1                         (491)
#define I_WON_THE_FIGHT_COLOR_RED_1                     (206)
#define I_WON_THE_FIGHT_COLOR_GREEN_1                   (147)
#define I_WON_THE_FIGHT_COLOR_BLUE_1                    (22)
#define I_WON_THE_FIGHT_POS_X_2                         (880)
#define I_WON_THE_FIGHT_POS_Y_2                         (494)
#define I_WON_THE_FIGHT_COLOR_RED_2                     (219)
#define I_WON_THE_FIGHT_COLOR_GREEN_2                   (168)
#define I_WON_THE_FIGHT_COLOR_BLUE_2                    (17)

#define I_LOST_THE_FIGHT_POS_X_1                        (1039)
#define I_LOST_THE_FIGHT_POS_Y_1                        (501)
#define I_LOST_THE_FIGHT_COLOR_RED_1                    (159)
#define I_LOST_THE_FIGHT_COLOR_GREEN_1                  (72)
#define I_LOST_THE_FIGHT_COLOR_BLUE_1                   (66)
#define I_LOST_THE_FIGHT_POS_X_2                        (879)
#define I_LOST_THE_FIGHT_POS_Y_2                        (505)
#define I_LOST_THE_FIGHT_COLOR_RED_2                    (165)
#define I_LOST_THE_FIGHT_COLOR_GREEN_2                  (81)
#define I_LOST_THE_FIGHT_COLOR_BLUE_2                   (68)

















//////////////////////////////////////////////////////////////
// ZAAPS CHECKS
//////////////////////////////////////////////////////////////

#define I_AM_IN_ASTRUB_ZAAP_POS_X_1                     (1101)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_1                     (318)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_1                 (127)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_1               (168)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_1                (115)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_2                     (1102)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_2                     (299)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_2                 (234)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_2               (210)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_2                (134)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_3                     (1029)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_3                     (274)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_3                 (167)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_3               (137)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_3                (58)

//////////////////////////////////////////////////////////////
// ROADMAPS CHECKS
//////////////////////////////////////////////////////////////

// 0, -18
#define I_AM_IN_WOOD_LV1_POS_X_1                     (1369)
#define I_AM_IN_WOOD_LV1_POS_Y_1                     (161)
#define I_AM_IN_WOOD_LV1_COLOR_RED_1                 (84)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_1               (134)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_1                (138)
#define I_AM_IN_WOOD_LV1_POS_X_2                     (625)
#define I_AM_IN_WOOD_LV1_POS_Y_2                     (99)
#define I_AM_IN_WOOD_LV1_COLOR_RED_2                 (114)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_2               (27)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_2                (23)
#define I_AM_IN_WOOD_LV1_POS_X_3                     (695)
#define I_AM_IN_WOOD_LV1_POS_Y_3                     (871)
#define I_AM_IN_WOOD_LV1_COLOR_RED_3                 (110)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_3               (104)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_3                (63)







//////////////////////////////////////////////////////////////
// INTERFACE WORLD CHECKS
//////////////////////////////////////////////////////////////

#define HEALTH_POS_X                                    (518)
#define HEALTH_POS_Y                                    (968)
#define HEALTH_COLOR_RED                                (166)
#define HEALTH_COLOR_GREEN                              (28)
#define HEALTH_COLOR_BLUE                               (47)

#define CHECK_PODS_POS_X                                (1856)
#define CHECK_PODS_POS_Y                                (1007)
#define CHECK_PODS_COLOR_RED                            (228)
#define CHECK_PODS_COLOR_GREEN                          (242)
#define CHECK_PODS_COLOR_BLUE                           (75)

#define PRIVATE_MODE_POS_X_1                            (18)
#define PRIVATE_MODE_POS_Y_1                            (1040)
#define PRIVATE_MODE_POS_X_2                            (100)
#define PRIVATE_MODE_POS_Y_2                            (1024)
#define PRIVATE_MODE_POS_X_3                            (188)
#define PRIVATE_MODE_POS_Y_3                            (1020)
#define PRIVATE_MODE_POS_COLOR_RED_1                    (212) // red dot
#define PRIVATE_MODE_POS_COLOR_GREEN_1                  (0)
#define PRIVATE_MODE_POS_COLOR_BLUE_1                   (0)





#define NPJ_TALKING_POS_X                               (1189)
#define NPJ_TALKING_POS_Y_1                             (750)
#define NPJ_TALKING_POS_Y_2                             (709)
#define NPJ_TALKING_POS_Y_3                             (726)

#define NPJ_TALKING_POS_X_2                             (477)
#define NPJ_TALKING_POS_Y_2_1                           (698)
#define NPJ_TALKING_POS_Y_2_2                           (726)
#define NPJ_TALKING_POS_Y_2_3                           (756)

#define I_AM_LEVEL_UP_POS_X_1                           (714)
#define I_AM_LEVEL_UP_POS_Y_1                           (713)
#define I_AM_LEVEL_UP_COLOR_RED_1                       (33)
#define I_AM_LEVEL_UP_COLOR_GREEN_1                     (32)
#define I_AM_LEVEL_UP_COLOR_BLUE_1                      (28)
#define I_AM_LEVEL_UP_POS_X_2                           (1202)
#define I_AM_LEVEL_UP_POS_Y_2                           (693)
#define I_AM_LEVEL_UP_COLOR_RED_2                       (31)
#define I_AM_LEVEL_UP_COLOR_GREEN_2                     (31)
#define I_AM_LEVEL_UP_COLOR_BLUE_2                      (26)
#define I_AM_LEVEL_UP_POS_X_3                           (1094)
#define I_AM_LEVEL_UP_POS_Y_3                           (571)
#define I_AM_LEVEL_UP_BIG_POS_X_3                       (1095)
#define I_AM_LEVEL_UP_BIG_POS_Y_3                       (423)
#define I_AM_LEVEL_UP_COLOR_RED_3                       (204)
#define I_AM_LEVEL_UP_COLOR_GREEN_3                     (146)
#define I_AM_LEVEL_UP_COLOR_BLUE_3                      (21)
#define I_AM_LEVEL_UP_POS_X_4                           (984) /* OK button */
#define I_AM_LEVEL_UP_POS_Y_4                           (793)
#define I_AM_LEVEL_UP_COLOR_RED_4                       (225)
#define I_AM_LEVEL_UP_COLOR_GREEN_4                     (247)
#define I_AM_LEVEL_UP_COLOR_BLUE_4                      (0)

#define I_AM_IN_EDGE_ZAAP_POS_X_1                       (869)
#define I_AM_IN_EDGE_ZAAP_POS_Y_1                       (424)
#define I_AM_IN_EDGE_ZAAP_COLOR_RED_1                   (63)
#define I_AM_IN_EDGE_ZAAP_COLOR_GREEN_1                 (100)
#define I_AM_IN_EDGE_ZAAP_COLOR_BLUE_1                  (63)
#define I_AM_IN_EDGE_ZAAP_POS_X_2                       (871)
#define I_AM_IN_EDGE_ZAAP_POS_Y_2                       (382)
#define I_AM_IN_EDGE_ZAAP_COLOR_RED_2                   (111)
#define I_AM_IN_EDGE_ZAAP_COLOR_GREEN_2                 (193)
#define I_AM_IN_EDGE_ZAAP_COLOR_BLUE_2                  (129)
#define I_AM_IN_EDGE_ZAAP_POS_X_3                       (881)
#define I_AM_IN_EDGE_ZAAP_POS_Y_3                       (384)
#define I_AM_IN_EDGE_ZAAP_COLOR_RED_3                   (255)
#define I_AM_IN_EDGE_ZAAP_COLOR_GREEN_3                 (219)
#define I_AM_IN_EDGE_ZAAP_COLOR_BLUE_3                  (122)



#define I_AM_IN_OTO_COAST_ZAAP_POS_X_1                  (900)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_1                  (328)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_1              (16)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_1            (171)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_1             (171)
#define I_AM_IN_OTO_COAST_ZAAP_POS_X_2                  (867)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_2                  (329)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_2              (192)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_2            (181)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_2             (124)
#define I_AM_IN_OTO_COAST_ZAAP_POS_X_3                  (735)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_3                  (60)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_3              (129)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_3            (27)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_3             (21)

#define I_AM_IN_KOALAK_ZAAP_POS_X_1                     (930)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_1                     (362)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_1                 (236)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_1               (221)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_1                (155)
#define I_AM_IN_KOALAK_ZAAP_POS_X_2                     (932)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_2                     (339)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_2                 (101)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_2               (127)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_2                (0)
#define I_AM_IN_KOALAK_ZAAP_POS_X_3                     (1265)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_3                     (126)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_3                 (111)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_3               (126)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_3                (0)

#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_X_1               (740)
#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_Y_1               (282)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_RED_1           (248)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_GREEN_1         (212)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_BLUE_1          (119)
#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_X_2               (1532)
#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_Y_2               (97)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_RED_2           (206)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_GREEN_2         (189)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_BLUE_2          (75)
#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_X_3               (458)
#define I_AM_IN_CANIA_PLAINS_ZAAP_POS_Y_3               (567)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_RED_3           (154)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_GREEN_3         (150)
#define I_AM_IN_CANIA_PLAINS_ZAAP_COLOR_BLUE_3          (21)

#define I_AM_IN_GOBBALL_ZAAP_POS_X_1                    (1129)
#define I_AM_IN_GOBBALL_ZAAP_POS_Y_1                    (323)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_RED_1                (255)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_1              (233)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_1               (155)
#define I_AM_IN_GOBBALL_ZAAP_POS_X_2                    (939)
#define I_AM_IN_GOBBALL_ZAAP_POS_Y_2                    (217)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_RED_2                (179)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_2              (200)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_2               (32)
#define I_AM_IN_GOBBALL_ZAAP_POS_X_3                    (933)
#define I_AM_IN_GOBBALL_ZAAP_POS_Y_3                    (230)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_RED_3                (179)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_3              (183)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_3               (32)
#define I_AM_IN_GOBBALL_ZAAP_POS_X_4                    (416)
#define I_AM_IN_GOBBALL_ZAAP_POS_Y_4                    (307)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_RED_4                (251)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_4              (83)
#define I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_4               (69)

#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_1               (1213)
#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_1               (289)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_1           (255)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_1         (233)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_1          (130)
#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_2               (1159)
#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_2               (287)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_2           (225)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_2         (202)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_2          (123)
#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_3               (372)
#define I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_3               (858)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_3           (132)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_3         (175)
#define I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_3          (42)

#define I_AM_IN_MOON_ZAAP_POS_X_1                       (583)
#define I_AM_IN_MOON_ZAAP_POS_Y_1                       (98)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_1                   (163)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_1                 (146)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_1                  (86)
#define I_AM_IN_MOON_ZAAP_POS_X_2                       (1304)
#define I_AM_IN_MOON_ZAAP_POS_Y_2                       (72)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_2                   (126)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_2                 (137)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_2                  (30)
#define I_AM_IN_MOON_ZAAP_POS_X_3                       (1471)
#define I_AM_IN_MOON_ZAAP_POS_Y_3                       (736)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_3                   (167)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_3                 (195)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_3                  (141)

#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_1         (1077)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_1         (314)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_1     (255)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_1   (233)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_1    (174)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_2         (726)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_2         (893)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_2     (84)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_2   (210)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_2    (191)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_3         (1211)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_3         (915)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_3     (84)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_3   (210)
#define I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_3    (191)

#define REST_POS_X			                    		(873)
#define REST_POS_Y		                    			(952)
#define REST_POS_COLOR_RED				                (200)
#define REST_POS_COLOR_GREEN                 			(200)
#define REST_POS_COLOR_BLUE 			            	(200)

#define INVO_SPELL_POS_7_X			                   	(1112)
#define INVO_SPELL_POS_7_Y		                    	(1002)
#define INVO_SPELL_POS_8_X			                   	(1158)
#define INVO_SPELL_POS_8_Y		                    	(1002)



#define IS_MERCANT_POS_X_1					            (693)
#define IS_MERCANT_POS_Y_1					            (111)
#define IS_MERCANT_COLOR_RED				            (105)
#define IS_MERCANT_COLOR_GREEN				            (105)
#define IS_MERCANT_COLOR_BLUE				            (105)
#define IS_MERCANT_POS_X_2					            (704)
#define IS_MERCANT_POS_Y_2					            (112)
#define IS_MERCANT_POS_X_3					            (1528)
#define IS_MERCANT_POS_Y_3					            (115)

#define IS_MERCANT_MODE_POS_X_1					        (723)
#define IS_MERCANT_MODE_POS_Y_1					        (465)
#define IS_MERCANT_MODE_COLOR_RED				        (46)
#define IS_MERCANT_MODE_COLOR_GREEN			            (52)
#define IS_MERCANT_MODE_COLOR_BLUE				        (36)
#define IS_MERCANT_MODE_POS_X_2					        (726)
#define IS_MERCANT_MODE_POS_Y_2					        (599)
#define IS_MERCANT_MODE_COLOR_RED_AUX			        (55)
#define IS_MERCANT_MODE_COLOR_GREEN_AUX		            (62)
#define IS_MERCANT_MODE_COLOR_BLUE_AUX	     	        (44)
#define IS_MERCANT_MODE_POS_X_3					        (1199)
#define IS_MERCANT_MODE_POS_Y_3					        (599)

#define IS_ERROR_WINDOW_POS_X_1					        (815)
#define IS_ERROR_WINDOW_POS_Y_1					        (492)
#define IS_ERROR_WINDOW_COLOR_RED				        (56)
#define IS_ERROR_WINDOW_COLOR_GREEN				        (58)
#define IS_ERROR_WINDOW_COLOR_BLUE				        (46)
#define IS_ERROR_WINDOW_POS_X_2					        (1084)
#define IS_ERROR_WINDOW_POS_Y_2					        (491)
#define IS_ERROR_WINDOW_POS_X_3					        (1083)
#define IS_ERROR_WINDOW_POS_Y_3					        (578)
#define IS_ERROR_WINDOW_POS_X_4					        (954) /* OK button, Caution */
#define IS_ERROR_WINDOW_POS_Y_4					        (580)

#define IS_MAIN_MENU_WINDOW_POS_X_1					    (1104)
#define IS_MAIN_MENU_WINDOW_POS_Y_1					    (630)
#define IS_MAIN_MENU_WINDOW_COLOR_RED_1				    (247)
#define IS_MAIN_MENU_WINDOW_COLOR_GREEN_1				(92)
#define IS_MAIN_MENU_WINDOW_COLOR_BLUE_1				(32)
#define IS_MAIN_MENU_WINDOW_POS_X_2					    (1097)
#define IS_MAIN_MENU_WINDOW_POS_Y_2					    (358)
#define IS_MAIN_MENU_WINDOW_COLOR_RED_2				    (111)
#define IS_MAIN_MENU_WINDOW_COLOR_GREEN_2				(111)
#define IS_MAIN_MENU_WINDOW_COLOR_BLUE_2				(111)
#define IS_MAIN_MENU_WINDOW_POS_X_3					    (790)
#define IS_MAIN_MENU_WINDOW_POS_Y_3					    (358)
#define IS_MAIN_MENU_WINDOW_COLOR_RED_3				    (95)
#define IS_MAIN_MENU_WINDOW_COLOR_GREEN_3				(96)
#define IS_MAIN_MENU_WINDOW_COLOR_BLUE_3				(94)
//#define IS_MAIN_MENU_WINDOW_POS_X_4					    (954) /* OK button, Caution */
//#define IS_MAIN_MENU_WINDOW_POS_Y_4					    (580)

#define AM_I_DEAD_POS_X_1					            (812)
#define AM_I_DEAD_POS_Y_1					            (516)
#define AM_I_DEAD_COLOR_RED_1			                (192)
#define AM_I_DEAD_COLOR_GREEN_1				            (170)
#define AM_I_DEAD_COLOR_BLUE_1			                (117)
#define AM_I_DEAD_POS_X_2					            (824)
#define AM_I_DEAD_POS_Y_2					            (460)
#define AM_I_DEAD_COLOR_RED_2			                (53)
#define AM_I_DEAD_COLOR_GREEN_2				            (53)
#define AM_I_DEAD_COLOR_BLUE_2			                (41)
#define AM_I_DEAD_POS_X_3					            (1194)
#define AM_I_DEAD_POS_Y_3					            (618)
#define AM_I_DEAD_COLOR_RED_3			                (45)
#define AM_I_DEAD_COLOR_GREEN_3				            (50)
#define AM_I_DEAD_COLOR_BLUE_3			                (36)
#define AM_I_DEAD_POS_X_4					            (920)
#define AM_I_DEAD_POS_Y_4					            (625)

#define CLOSE_POSTFIGHT_WINDOW_POS_X					(1252)
#define CLOSE_POSTFIGHT_WINDOW_POS_Y					(745)

#define ASTRUB_ZAAP_POS_X					            (1120)
#define ASTRUB_ZAAP_POS_Y					            (320)

#define INVENTARY_CONSUMABLES_TAB_POS_X_1                           (1421)
#define INVENTARY_CONSUMABLES_TAB_POS_Y_1                           (106)
#define INVENTARY_CONSUMABLES_TAB_POS_X_2                           (1700)
#define INVENTARY_CONSUMABLES_TAB_POS_Y_2                           (123)
#define INVENTARY_RESOURCES_TAB_POS_X_1                             (1473)
#define INVENTARY_RESOURCES_TAB_POS_Y_1                             (108)
#define INVENTARY_RESOURCES_TAB_POS_X_2                             (1757)
#define INVENTARY_RESOURCES_TAB_POS_Y_2                             (80)

#define INVENTARY_CONSUMABLES_FIRST_CONSUMABLE_POS_X_1              (1323)
#define INVENTARY_CONSUMABLES_FIRST_CONSUMABLE_POS_Y_1              (182)
#define INVENTARY_CONSUMABLES_FIRST_CONSUMABLE_POS_X_2              (1602)
#define INVENTARY_CONSUMABLES_FIRST_CONSUMABLE_POS_Y_2              (187)
#define INVENTARY_CONSUMABLES_SECOND_CONSUMABLE_POS_X_2             (1666)
#define INVENTARY_CONSUMABLES_SECOND_CONSUMABLE_POS_Y_2             (187)
#define INVENTARY_CONSUMABLES_THIRD_CONSUMABLE_POS_X_2              (1725)
#define INVENTARY_CONSUMABLES_THIRD_CONSUMABLE_POS_Y_2              (187)
#define INVENTARY_CONSUMABLES_FOURTH_CONSUMABLE_POS_X_2             (1786)
#define INVENTARY_CONSUMABLES_FOURTH_CONSUMABLE_POS_Y_2             (187)
#define INVENTARY_CONSUMABLES_MIMILK_COLOR_RED                      (226) //Mimilk
#define INVENTARY_CONSUMABLES_MIMILK_COLOR_GREEN                    (230)
#define INVENTARY_CONSUMABLES_MIMILK_COLOR_BLUE                     (233)
#define INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_RED                 (92)  //Recall Poti
#define INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_GREEN               (158)
#define INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_BLUE                (166)
#define INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_RED                   (142) //Brak Poti
#define INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_GREEN                 (70)
#define INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_BLUE                  (72)

#define POSIBLE_FIGHT_POSITIONS                                     (8)

///////////////////////////////////
// ERRORS VARIANCE
///////////////////////////////////
#define ERROR_GET_COLOUR_BIG                                        (50)
#define ERROR_GET_COLOUR                                            (25)
#define ERROR_GET_COLOUR_SOME                                       (20)
#define ERROR_GET_COLOUR_QUITE                                      (10)
#define ERROR_GET_COLOUR_SMALL                                      (5)
#define ERROR_GET_COLOUR_SMALLER                                    (1)

///////////////////////////////////
// RETURN ERRORS
///////////////////////////////////
#define E_OK                                                        (0)
#define E_KO                                                        (-1)