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

#define LIMIT_CELL_Y_MIN                                (80)
#define LIMIT_CELL_Y_MAX                                (850)
#define LIMIT_CELL_X_MIN                                (405)
#define LIMIT_CELL_X_MAX                                (1470)

#define RIGHT                                           (0)
#define DOWN                                            (1)
#define LEFT                                            (2)
#define UP                                              (3)

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

#define IS_ORANGE_CAC_WEAPON_POS_X_1                       (1129)
#define IS_ORANGE_CAC_WEAPON_POS_Y_1                       (1003)
#define IS_ORANGE_CAC_WEAPON_POS_X_2                       (1127)
#define IS_ORANGE_CAC_WEAPON_POS_Y_2                       (1013)
#define IS_ORANGE_CAC_WEAPON_POS_X_3                       (1158)
#define IS_ORANGE_CAC_WEAPON_POS_Y_3                       (1031)
#define IS_ORANGE_CAC_WEAPON_COLOR_RED                     (252) //exact
#define IS_ORANGE_CAC_WEAPON_COLOR_GREEN                   (140) // 128-150
#define IS_ORANGE_CAC_WEAPON_COLOR_BLUE                    (60)  // 46 - 68

#define IS_SIT_POS_X_1                                     (733)
#define IS_SIT_POS_Y_1                                     (1008)
#define IS_SIT_COLOR_RED_1                                 (105)
#define IS_SIT_COLOR_GREEN_1                               (66)
#define IS_SIT_COLOR_BLUE_1                                (41)
#define IS_SIT_POS_X_2                                     (727)
#define IS_SIT_POS_Y_2                                     (1012)
#define IS_SIT_COLOR_RED_2                                 (180)
#define IS_SIT_COLOR_GREEN_2                               (114)
#define IS_SIT_COLOR_BLUE_2                                (69)

#define SWITCH_BOTTOM_MENU_POS_X_1                         (1217)
#define SWITCH_BOTTOM_MENU_POS_Y_1                         (997)

///////////////////////////////////
// COLOR
///////////////////////////////////

#define BLACK_COLOR_RED                                    (0)
#define BLACK_COLOR_GREEN                                  (0)
#define BLACK_COLOR_BLUE                                   (0)


///////////////////////////////////
// FIGHT
///////////////////////////////////

#define IT_IS_MY_TURN_POS_X_1                              (1315)
#define IT_IS_MY_TURN_POS_Y_1                              (917)
#define IT_IS_MY_TURN_POS_X_2                              (1318)
#define IT_IS_MY_TURN_POS_Y_2                              (915)
#define IT_IS_MY_TURN_POS_X_3                              (1336)
#define IT_IS_MY_TURN_POS_Y_3                              (904)
#define IT_IS_MY_TURN_POS_X_4                              (1334)
#define IT_IS_MY_TURN_POS_Y_4                              (905)
#define IT_IS_MY_TURN_BOTTOM_POS_X_1                       (1328)
#define IT_IS_MY_TURN_BOTTOM_POS_Y_1                       (994)
#define IT_IS_MY_TURN_BOTTOM_POS_X_2                       (1336)
#define IT_IS_MY_TURN_BOTTOM_POS_Y_2                       (999)
#define IT_IS_MY_TURN_COLOR_RED                            (236)
#define IT_IS_MY_TURN_COLOR_GREEN                          (173)
#define IT_IS_MY_TURN_COLOR_BLUE                           (85)

#define ACCEPT_RETO_POS_X                                  (186)
#define ACCEPT_RETO_POS_Y                                  (363)

#define FIGTH_MENU_FRIEND_POS_X                            (750) // Depending of the enemies on a fight
#define FIGTH_MENU_FRIEND_POS_Y                            (59)

#define FIGTH_MENU_FRIEND_COLOR_RED                        (62)
#define FIGTH_MENU_FRIEND_COLOR_GREEN                      (102)
#define FIGTH_MENU_FRIEND_COLOR_BLUE                       (131)
#define FIGTH_MENU_FRIEND_TURN_COLOR_RED                   (129)
#define FIGTH_MENU_FRIEND_TURN_COLOR_GREEN                 (155)
#define FIGTH_MENU_FRIEND_TURN_COLOR_BLUE                  (174)

#define FIGTH_MENU_ENEMY_COLOR_RED                         (117)
#define FIGTH_MENU_ENEMY_COLOR_GREEN                       (80)
#define FIGTH_MENU_ENEMY_COLOR_BLUE                        (84)

#define FIGHT_X_LIMIT_MIN                                  (600)
#define FIGHT_X_LIMIT_MAX                                  (1300)
#define FIGHT_Y_LIMIT_MIN                                  (250)
#define FIGHT_Y_LIMIT_MAX                                  (700)


///////////////////////////////////
// AFTER FIGHT
///////////////////////////////////

#define I_WON_THE_FIGHT_POS_X_1                            (1038)
#define I_WON_THE_FIGHT_POS_Y_1                            (491)
#define I_WON_THE_FIGHT_COLOR_RED_1                        (206)
#define I_WON_THE_FIGHT_COLOR_GREEN_1                      (147)
#define I_WON_THE_FIGHT_COLOR_BLUE_1                       (22)
#define I_WON_THE_FIGHT_POS_X_2                            (880)
#define I_WON_THE_FIGHT_POS_Y_2                            (494)
#define I_WON_THE_FIGHT_COLOR_RED_2                        (214)
#define I_WON_THE_FIGHT_COLOR_GREEN_2                      (163)
#define I_WON_THE_FIGHT_COLOR_BLUE_2                       (17)
#define I_WON_THE_FIGHT_POS_X_3                            (1048)
#define I_WON_THE_FIGHT_POS_Y_3                            (495)
#define I_WON_THE_FIGHT_COLOR_RED_3                        (210)
#define I_WON_THE_FIGHT_COLOR_GREEN_3                      (157)
#define I_WON_THE_FIGHT_COLOR_BLUE_3                       (16)

#define I_LOST_THE_FIGHT_POS_X_1                           (1039)
#define I_LOST_THE_FIGHT_POS_Y_1                           (501)
#define I_LOST_THE_FIGHT_COLOR_RED_1                       (159)
#define I_LOST_THE_FIGHT_COLOR_GREEN_1                     (72)
#define I_LOST_THE_FIGHT_COLOR_BLUE_1                      (66)
#define I_LOST_THE_FIGHT_POS_X_2                           (879)
#define I_LOST_THE_FIGHT_POS_Y_2                           (505)
#define I_LOST_THE_FIGHT_COLOR_RED_2                       (165)
#define I_LOST_THE_FIGHT_COLOR_GREEN_2                     (81)
#define I_LOST_THE_FIGHT_COLOR_BLUE_2                      (68)

#define LOW_ENERGY_BOX_POS_X_1                             (1045)
#define LOW_ENERGY_BOX_POS_Y_1                             (480)
#define LOW_ENERGY_BOX_COLOR_RED_1                         (82)
#define LOW_ENERGY_BOX_COLOR_GREEN_1                       (82)
#define LOW_ENERGY_BOX_COLOR_BLUE_1                        (114)
#define LOW_ENERGY_BOX_POS_X_2                             (1037)
#define LOW_ENERGY_BOX_POS_Y_2                             (509)
#define LOW_ENERGY_BOX_COLOR_RED_2                         (27)
#define LOW_ENERGY_BOX_COLOR_GREEN_2                       (29)
#define LOW_ENERGY_BOX_COLOR_BLUE_2                        (50)

#define FENIX_BOX_POS_X_1                                  (1115)
#define FENIX_BOX_POS_Y_1                                  (425)
#define FENIX_BOX_COLOR_RED_1                              (82)
#define FENIX_BOX_COLOR_GREEN_1                            (82)
#define FENIX_BOX_COLOR_BLUE_1                             (114)
#define FENIX_BOX_POS_X_2                                  (1157)
#define FENIX_BOX_POS_Y_2                                  (469)
#define FENIX_BOX_COLOR_RED_2                              (27)
#define FENIX_BOX_COLOR_GREEN_2                            (29)
#define FENIX_BOX_COLOR_BLUE_2                             (50)
#define FENIX_BOX_POS_X_3                                  (811)
#define FENIX_BOX_POS_Y_3                                  (510)
#define FENIX_BOX_COLOR_RED_3                              (187)
#define FENIX_BOX_COLOR_GREEN_3                            (86)
#define FENIX_BOX_COLOR_BLUE_3                             (29)
#define FENIX_BOX_CLICK_POS_X_1                            (971)
#define FENIX_BOX_CLICK_POS_Y_1                            (636)
#define FENIX_BOX_CLICK_POS_X_2                            (985)
#define FENIX_BOX_CLICK_POS_Y_2                            (605)

//////////////////////////////////////////////////////////////
// ZAAPS CHECKS
//////////////////////////////////////////////////////////////

#define ZAAP_INTERFACE_POS_X                               (864)
#define ZAAP_INTERFACE_POS_Y                               (299)
#define ZAAP_INTERFACE_COLOR_RED_1                         (58)
#define ZAAP_INTERFACE_COLOR_GREEN_1                       (61)
#define ZAAP_INTERFACE_COLOR_BLUE_1                        (88)

#define ZAAP_INTERFACE_WRITE_POS_X                         (600)
#define ZAAP_INTERFACE_WRITE_POS_Y                         (360)

#define ASTRUB_ZAAP_POS_X                                  (1103)
#define ASTRUB_ZAAP_POS_Y                                  (299)

#define I_AM_IN_ASTRUB_ZAAP_POS_X_1                        (635)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_1                        (57)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_1                    (163)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_1                  (168)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_1                   (149)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_2                        (1478)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_2                        (89)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_2                    (105)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_2                  (100)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_2                   (66)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_3                        (555)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_3                        (888)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_3                    (127)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_3                  (103)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_3                   (37)

#define I_AM_IN_LINDE_ZAAP_POS_X_1                         (869)
#define I_AM_IN_LINDE_ZAAP_POS_Y_1                         (424)
#define I_AM_IN_LINDE_ZAAP_COLOR_RED_1                     (85)
#define I_AM_IN_LINDE_ZAAP_COLOR_GREEN_1                   (130)
#define I_AM_IN_LINDE_ZAAP_COLOR_BLUE_1                    (104)
#define I_AM_IN_LINDE_ZAAP_POS_X_2                         (871)
#define I_AM_IN_LINDE_ZAAP_POS_Y_2                         (382)
#define I_AM_IN_LINDE_ZAAP_COLOR_RED_2                     (109)
#define I_AM_IN_LINDE_ZAAP_COLOR_GREEN_2                   (189)
#define I_AM_IN_LINDE_ZAAP_COLOR_BLUE_2                    (127)
#define I_AM_IN_LINDE_ZAAP_POS_X_3                         (881)
#define I_AM_IN_LINDE_ZAAP_POS_Y_3                         (384)
#define I_AM_IN_LINDE_ZAAP_COLOR_RED_3                     (226)
#define I_AM_IN_LINDE_ZAAP_COLOR_GREEN_3                   (194)
#define I_AM_IN_LINDE_ZAAP_COLOR_BLUE_3                    (109)

#define I_AM_IN_PUERKAZOS_ZAAP_POS_X_1                     (740)
#define I_AM_IN_PUERKAZOS_ZAAP_POS_Y_1                     (282)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_1                 (211)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_1               (182)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_1                (63)
#define I_AM_IN_PUERKAZOS_ZAAP_POS_X_2                     (1532)
#define I_AM_IN_PUERKAZOS_ZAAP_POS_Y_2                     (97)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_2                 (149)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_2               (146)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_2                (28)
#define I_AM_IN_PUERKAZOS_ZAAP_POS_X_3                     (458)
#define I_AM_IN_PUERKAZOS_ZAAP_POS_Y_3                     (567)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_3                 (147)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_3               (167)
#define I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_3                (21)

#define I_AM_IN_OTO_COAST_ZAAP_POS_X_1                     (900)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_1                     (328)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_1                 (16)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_1               (171)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_1                (171)
#define I_AM_IN_OTO_COAST_ZAAP_POS_X_2                     (867)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_2                     (329)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_2                 (192)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_2               (181)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_2                (124)
#define I_AM_IN_OTO_COAST_ZAAP_POS_X_3                     (735)
#define I_AM_IN_OTO_COAST_ZAAP_POS_Y_3                     (60)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_3                 (129)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_3               (27)
#define I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_3                (21)

#define I_AM_IN_KOALAK_ZAAP_POS_X_1                        (930)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_1                        (362)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_1                    (246)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_1                  (231)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_1                   (164)
#define I_AM_IN_KOALAK_ZAAP_POS_X_2                        (932)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_2                        (339)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_2                    (101)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_2                  (127)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_2                   (0)
#define I_AM_IN_KOALAK_ZAAP_POS_X_3                        (1265)
#define I_AM_IN_KOALAK_ZAAP_POS_Y_3                        (126)
#define I_AM_IN_KOALAK_ZAAP_COLOR_RED_3                    (118)
#define I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_3                  (131)
#define I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_3                   (0)

#define I_AM_IN_MOON_ZAAP_POS_X_1                          (1700)
#define I_AM_IN_MOON_ZAAP_POS_Y_1                          (171)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_1                      (93)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_1                    (141)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_1                     (112)
#define I_AM_IN_MOON_ZAAP_POS_X_2                          (1239)
#define I_AM_IN_MOON_ZAAP_POS_Y_2                          (850)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_2                      (83)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_2                    (181)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_2                     (161)
#define I_AM_IN_MOON_ZAAP_POS_X_3                          (366)
#define I_AM_IN_MOON_ZAAP_POS_Y_3                          (40)
#define I_AM_IN_MOON_ZAAP_COLOR_RED_3                      (156)
#define I_AM_IN_MOON_ZAAP_COLOR_GREEN_3                    (165)
#define I_AM_IN_MOON_ZAAP_COLOR_BLUE_3                     (32)

#define I_AM_IN_ROCOSAS_ZAAP_POS_X_1                       (655)
#define I_AM_IN_ROCOSAS_ZAAP_POS_Y_1                       (64)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_RED_1                   (254)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_GREEN_1                 (248)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_BLUE_1                  (100)
#define I_AM_IN_ROCOSAS_ZAAP_POS_X_2                       (653)
#define I_AM_IN_ROCOSAS_ZAAP_POS_Y_2                       (91)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_RED_2                   (254)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_GREEN_2                 (252)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_BLUE_2                  (95)
#define I_AM_IN_ROCOSAS_ZAAP_POS_X_3                       (635)
#define I_AM_IN_ROCOSAS_ZAAP_POS_Y_3                       (129)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_RED_3                   (201)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_GREEN_3                 (183)
#define I_AM_IN_ROCOSAS_ZAAP_COLOR_BLUE_3                  (55)

#define I_AM_IN_BURGO_ZAAP_POS_X_1                         (1526)
#define I_AM_IN_BURGO_ZAAP_POS_Y_1                         (245)
#define I_AM_IN_BURGO_ZAAP_COLOR_RED_1                     (211)
#define I_AM_IN_BURGO_ZAAP_COLOR_GREEN_1                   (230)
#define I_AM_IN_BURGO_ZAAP_COLOR_BLUE_1                    (234)
#define I_AM_IN_BURGO_ZAAP_POS_X_2                         (1523)
#define I_AM_IN_BURGO_ZAAP_POS_Y_2                         (200)
#define I_AM_IN_BURGO_ZAAP_COLOR_RED_2                     (245)
#define I_AM_IN_BURGO_ZAAP_COLOR_GREEN_2                   (247)
#define I_AM_IN_BURGO_ZAAP_COLOR_BLUE_2                    (250)
#define I_AM_IN_BURGO_ZAAP_POS_X_3                         (504)
#define I_AM_IN_BURGO_ZAAP_POS_Y_3                         (93)
#define I_AM_IN_BURGO_ZAAP_COLOR_RED_3                     (111)
#define I_AM_IN_BURGO_ZAAP_COLOR_GREEN_3                   (134)
#define I_AM_IN_BURGO_ZAAP_COLOR_BLUE_3                    (101)

//////////////////////////////////////////////////////////////
// ROADMAPS CHECKS
//////////////////////////////////////////////////////////////

// 0, -18
#define I_AM_IN_WOOD_LV1_POS_X_1                           (1369)
#define I_AM_IN_WOOD_LV1_POS_Y_1                           (161)
#define I_AM_IN_WOOD_LV1_COLOR_RED_1                       (84)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_1                     (134)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_1                      (138)
#define I_AM_IN_WOOD_LV1_POS_X_2                           (625)
#define I_AM_IN_WOOD_LV1_POS_Y_2                           (99)
#define I_AM_IN_WOOD_LV1_COLOR_RED_2                       (114)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_2                     (27)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_2                      (23)
#define I_AM_IN_WOOD_LV1_POS_X_3                           (695)
#define I_AM_IN_WOOD_LV1_POS_Y_3                           (871)
#define I_AM_IN_WOOD_LV1_COLOR_RED_3                       (110)
#define I_AM_IN_WOOD_LV1_COLOR_GREEN_3                     (104)
#define I_AM_IN_WOOD_LV1_COLOR_BLUE_3                      (63)

#define I_AM_IN_WOOD_OTO_COAST_POS_X_1                     (1183)
#define I_AM_IN_WOOD_OTO_COAST_POS_Y_1                     (207)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_RED_1                 (145)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_1               (27)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_1                (24)
#define I_AM_IN_WOOD_OTO_COAST_POS_X_2                     (676)
#define I_AM_IN_WOOD_OTO_COAST_POS_Y_2                     (532)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_RED_2                 (254)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_2               (185)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_2                (70)
#define I_AM_IN_WOOD_OTO_COAST_POS_X_3                     (667)
#define I_AM_IN_WOOD_OTO_COAST_POS_Y_3                     (532)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_RED_3                 (228)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_3               (209)
#define I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_3                (129)



//////////////////////////////////////////////////////////////
// INTERFACE WORLD CHECKS
//////////////////////////////////////////////////////////////

#define HEALTH_POS_X                                       (518)
#define HEALTH_POS_Y                                       (968)
#define HEALTH_COLOR_RED                                   (166)
#define HEALTH_COLOR_GREEN                                 (28)
#define HEALTH_COLOR_BLUE                                  (47)
#define HEALTH_POS_X_2                                     (537)
#define HEALTH_POS_Y_2                                     (969)
#define HEALTH_COLOR_RED_2                                 (179)
#define HEALTH_COLOR_GREEN_2                               (50)
#define HEALTH_COLOR_BLUE_2                                (72)

#define CHECK_PODS_POS_X_1                                 (1856)
#define CHECK_PODS_POS_Y_1                                 (1007)
#define CHECK_PODS_POS_X_2                                 (1860)
#define CHECK_PODS_POS_Y_2                                 (1008)
#define CHECK_PODS_COLOR_RED                               (232)
#define CHECK_PODS_COLOR_GREEN                             (250)
#define CHECK_PODS_COLOR_BLUE                              (75)

#define PRIVATE_MODE_POS_X_1                               (18)
#define PRIVATE_MODE_POS_Y_1                               (1040)
#define PRIVATE_MODE_POS_X_2                               (100)
#define PRIVATE_MODE_POS_Y_2                               (1024)
#define PRIVATE_MODE_POS_X_3                               (188)
#define PRIVATE_MODE_POS_Y_3                               (1020)
#define PRIVATE_MODE_POS_COLOR_RED_1                       (212) // red dot
#define PRIVATE_MODE_POS_COLOR_GREEN_1                     (0)
#define PRIVATE_MODE_POS_COLOR_BLUE_1                      (0)

#define I_AM_LEVEL_UP_POS_X_1                              (714)
#define I_AM_LEVEL_UP_POS_Y_1                              (713)
#define I_AM_LEVEL_UP_COLOR_RED_1                          (33)
#define I_AM_LEVEL_UP_COLOR_GREEN_1                        (32)
#define I_AM_LEVEL_UP_COLOR_BLUE_1                         (28)
#define I_AM_LEVEL_UP_POS_X_2                              (1202)
#define I_AM_LEVEL_UP_POS_Y_2                              (693)
#define I_AM_LEVEL_UP_COLOR_RED_2                          (31)
#define I_AM_LEVEL_UP_COLOR_GREEN_2                        (31)
#define I_AM_LEVEL_UP_COLOR_BLUE_2                         (26)
#define I_AM_LEVEL_UP_POS_X_3                              (1094)
#define I_AM_LEVEL_UP_POS_Y_3                              (571)
#define I_AM_LEVEL_UP_BIG_POS_X_3                          (1095)
#define I_AM_LEVEL_UP_BIG_POS_Y_3                          (423)
#define I_AM_LEVEL_UP_COLOR_RED_3                          (204)
#define I_AM_LEVEL_UP_COLOR_GREEN_3                        (146)
#define I_AM_LEVEL_UP_COLOR_BLUE_3                         (21)
#define I_AM_LEVEL_UP_POS_X_4                              (984) /* OK button */
#define I_AM_LEVEL_UP_POS_Y_4                              (793)
#define I_AM_LEVEL_UP_COLOR_RED_4                          (225)
#define I_AM_LEVEL_UP_COLOR_GREEN_4                        (247)
#define I_AM_LEVEL_UP_COLOR_BLUE_4                         (0)

#define IS_MENU_PRINCIPAL_POS_X_1                          (1062)
#define IS_MENU_PRINCIPAL_POS_Y_1                          (343)
#define IS_MENU_PRINCIPAL_RED_1                            (82)
#define IS_MENU_PRINCIPAL_GREEN_1                          (82)
#define IS_MENU_PRINCIPAL_BLUE_1                           (114)
#define IS_MENU_PRINCIPAL_POS_X_2                          (1107)
#define IS_MENU_PRINCIPAL_POS_Y_2                          (566)
#define IS_MENU_PRINCIPAL_RED_2                            (27)
#define IS_MENU_PRINCIPAL_GREEN_2                          (29)
#define IS_MENU_PRINCIPAL_BLUE_2                           (50)
#define IS_MENU_PRINCIPAL_POS_X_3                          (1095)
#define IS_MENU_PRINCIPAL_POS_Y_3                          (714)
#define IS_MENU_PRINCIPAL_RED_3                            (58)
#define IS_MENU_PRINCIPAL_GREEN_3                          (61)
#define IS_MENU_PRINCIPAL_BLUE_3                           (88)


///////////////////////////////////
// RESOURCES
///////////////////////////////////

#define RECALL_POTI_POS_X_1                                (989)
#define RECALL_POTI_POS_Y_1                                (1024)
#define RECALL_POTI_COLOR_RED_1                            (121)
#define RECALL_POTI_COLOR_GREEN_1                          (109)
#define RECALL_POTI_COLOR_BLUE_1                           (165)
#define RECALL_POTI_POS_X_2                                (996)
#define RECALL_POTI_POS_Y_2                                (1025)
#define RECALL_POTI_COLOR_RED_2                            (94)
#define RECALL_POTI_COLOR_GREEN_2                          (66)
#define RECALL_POTI_COLOR_BLUE_2                           (146)

#define INVENTARY_CONVERT_RESOURCES_X_1                    (1001)
#define INVENTARY_CONVERT_RESOURCES_Y_1                    (317)
#define INVENTARY_CONVERT_RESOURCES_X_2                    (1187)
#define INVENTARY_CONVERT_RESOURCES_Y_2                    (223)
#define INVENTARY_CONVERT_RESOURCES_X_3                    (1086)
#define INVENTARY_CONVERT_RESOURCES_Y_3                    (221)
#define INVENTARY_CONVERT_RESOURCES_X_4                    (1082)
#define INVENTARY_CONVERT_RESOURCES_Y_4                    (333)
#define INVENTARY_NO_RESOURCES_COLOR_RED                   (17)
#define INVENTARY_NO_RESOURCES_COLOR_GREEN                 (19)
#define INVENTARY_NO_RESOURCES_COLOR_BLUE                  (32)


///////////////////////////////////
// ERRORS VARIANCE
///////////////////////////////////

#define ERROR_GET_COLOUR_BIG                               (50)
#define ERROR_GET_COLOUR                                   (25)
#define ERROR_GET_COLOUR_SOME                              (20)
#define ERROR_GET_COLOUR_QUITE                             (10)
#define ERROR_GET_COLOUR_SMALL                             (5)
#define ERROR_GET_COLOUR_SMALLER                           (1)

///////////////////////////////////
// RETURN ERRORS
///////////////////////////////////

#define E_OK                                               (0)
#define E_KO                                               (-1)
#define E_NEED_TO_RESTART                                  (-10)
#define E_IM_A_GHOST                                       (-1)