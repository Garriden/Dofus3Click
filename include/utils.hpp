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

#define DOFUS_EXE_POS_X_1                               (130)
#define DOFUS_EXE_POS_Y_1                               (1064)
#define DOFUS_EXE_POS_COLOR_RED_1                       (241)
#define DOFUS_EXE_POS_COLOR_GREEN_1                     (247)
#define DOFUS_EXE_POS_COLOR_BLUE_1                      (120)
#define DOFUS_EXE_POS_COLOR_RED_2                       (222)
#define DOFUS_EXE_POS_COLOR_GREEN_2                     (255)
#define DOFUS_EXE_POS_COLOR_BLUE_2                      (123)

#define BLACK_SCREEN_POS_X_1                               (850)
#define BLACK_SCREEN_POS_Y_1                               (850)
#define BLACK_SCREEN_POS_X_2                               (1200)
#define BLACK_SCREEN_POS_Y_2                               (350)
#define BLACK_SCREEN_POS_X_3                               (700)
#define BLACK_SCREEN_POS_Y_3                               (700)
#define BLACK_SCREEN_POS_X_4                               (1200)
#define BLACK_SCREEN_POS_Y_4                               (725)


#define CHECK_PODS_POS_X								(1300)
#define CHECK_PODS_POS_Y								(1041)
#define CHECK_PODS_COLOR_RED							(96)
#define CHECK_PODS_COLOR_GREEN							(190)
#define CHECK_PODS_COLOR_BLUE							(53)

#define OBSERVER_MODE_POS_X								(1395)
#define OBSERVER_MODE_POS_Y								(1030)



#define PRIVATE_MODE_POS_X_1							(270)
#define PRIVATE_MODE_POS_Y_1							(1038)
#define PRIVATE_MODE_POS_X_2							(357)
#define PRIVATE_MODE_POS_Y_2							(1030)
#define PRIVATE_MODE_POS_COLOR_RED_1					(212)
#define PRIVATE_MODE_POS_COLOR_GREEN_1					(0)
#define PRIVATE_MODE_POS_COLOR_BLUE_1					(0)
#define PRIVATE_MODE_POS_COLOR_RED_2					(212)
#define PRIVATE_MODE_POS_COLOR_GREEN_2					(255)
#define PRIVATE_MODE_POS_COLOR_BLUE_2					(0)

#define RANDOM_X_LIMIT_MIN								(450)
#define RANDOM_X_LIMIT_MAX								(1350)
#define RANDOM_Y_LIMIT_MIN								(90)
#define RANDOM_Y_LIMIT_MAX								(750)

#define HEALTH_POS_X    								(803)
#define HEALTH_POS_Y    								(934)
#define HEALTH_COLOR_RED   								(200)

#define MENU_BAR_ARROW_UP_POS_X							(1281)
#define MENU_BAR_ARROW_UP_POS_Y							(962)
#define MENU_BAR_ARROW_DOWN_POS_X						(1281)
#define MENU_BAR_ARROW_DOWN_POS_Y						(1004)

#define FIGTH_MENU_POS_X_0								(1850) // Most right one
#define FIGTH_MENU_POS_Y_0								(858)
#define FIGTH_MENU_POS_X_1								(1788)
#define FIGTH_MENU_POS_Y_1								(858)
#define FIGTH_MENU_POS_X_2								(1726)
#define FIGTH_MENU_POS_Y_2								(858)
#define FIGTH_MENU_POS_X_3								(1664)
#define FIGTH_MENU_POS_Y_3								(858)
#define FIGTH_MENU_POS_X_4								(1602)
#define FIGTH_MENU_POS_Y_4								(858)
#define FIGTH_MENU_POS_X_5								(1540)
#define FIGTH_MENU_POS_Y_5								(858)
#define FIGTH_MENU_POS_X_6								(1478)
#define FIGTH_MENU_POS_Y_6								(858)
#define FIGTH_MENU_POS_X_7								(1416)
#define FIGTH_MENU_POS_Y_7								(858)
#define FIGTH_MENU_POS_X_8								(1354)
#define FIGTH_MENU_POS_Y_8								(858)
#define FIGTH_MENU_POS_X_9								(1292)
#define FIGTH_MENU_POS_Y_9								(858)
#define FIGTH_MENU_POS_X_10								(1230)
#define FIGTH_MENU_POS_Y_10								(858)
#define FIGTH_MENU_POS_X_11								(1168)
#define FIGTH_MENU_POS_Y_11								(858)
#define FIGTH_MENU_POS_X_12								(1106)
#define FIGTH_MENU_POS_Y_12								(858)
#define FIGTH_MENU_POS_X_13								(1044)
#define FIGTH_MENU_POS_Y_13								(858)
#define FIGTH_MENU_POS_X_14								(982)
#define FIGTH_MENU_POS_Y_14								(858)

#define FIGTH_MENU_ENEMY_COLOR_RED					    (65)
#define FIGTH_MENU_ENEMY_COLOR_GREEN					(145)
#define FIGTH_MENU_ENEMY_COLOR_BLUE						(175)
#define FIGTH_MENU_FRIEND_COLOR_RED                     (100)
#define FIGTH_MENU_FRIEND_COLOR_GREEN			     	(50)
#define FIGTH_MENU_FRIEND_COLOR_BLUE				    (50)
#define BLACK_COLOR_RED                                 (0)
#define BLACK_COLOR_GREEN			                	(0)
#define BLACK_COLOR_BLUE				                (0)
#define GREY_COLOR_RED                                  (48)
#define GREY_COLOR_GREEN			                	(48)
#define GREY_COLOR_BLUE				                    (44)
#define GREEN_COLOR_RED                                 (0)
#define GREEN_COLOR_GREEN			                	(102)
#define GREEN_COLOR_BLUE				                (0)

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

#define I_AM_IN_ASTRUB_ZAAP_POS_X_1                     (1101)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_1                     (318)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_1                 (124)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_1               (181)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_1                (140)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_2                     (1102)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_2                     (299)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_2                 (238)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_2               (216)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_2                (132)
#define I_AM_IN_ASTRUB_ZAAP_POS_X_3                     (1029)
#define I_AM_IN_ASTRUB_ZAAP_POS_Y_3                     (274)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_RED_3                 (168)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_3               (135)
#define I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_3                (60)

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

#define I_AM_ENTERING_IN_A_FIGHT_POS_X					(1010)
#define I_AM_ENTERING_IN_A_FIGHT_POS_Y					(1035)
#define I_AM_ENTERING_IN_A_FIGHT_COLOR_RED				(252)
#define I_AM_ENTERING_IN_A_FIGHT_COLOR_GREEN			(200)
#define I_AM_ENTERING_IN_A_FIGHT_COLOR_BLUE				(0)

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

#define I_AM_DEFEATED_POS_X_1                           (814)
#define I_AM_DEFEATED_POS_Y_1                           (780)
#define I_AM_DEFEATED_COLOR_RED_1                       (58)
#define I_AM_DEFEATED_COLOR_GREEN_1                     (60)
#define I_AM_DEFEATED_COLOR_BLUE_1                      (50)
#define I_AM_DEFEATED_POS_X_2                           (1116)
#define I_AM_DEFEATED_POS_Y_2                           (783)
#define I_AM_DEFEATED_COLOR_RED_2                       (46)
#define I_AM_DEFEATED_COLOR_GREEN_2                     (53)
#define I_AM_DEFEATED_COLOR_BLUE_2                      (40)
#define I_AM_DEFEATED_POS_X_3                           (1021)
#define I_AM_DEFEATED_POS_Y_3                           (742)
#define I_AM_DEFEATED_COLOR_RED_3                       (160)
#define I_AM_DEFEATED_COLOR_GREEN_3                     (75)
#define I_AM_DEFEATED_COLOR_BLUE_3                      (67)

#define I_WON_THE_FIGHT_POS_X_1                         (1025)
#define I_WON_THE_FIGHT_POS_Y_1                         (735)
#define I_WON_THE_FIGHT_COLOR_RED_1                     (204)
#define I_WON_THE_FIGHT_COLOR_GREEN_1                   (146)
#define I_WON_THE_FIGHT_COLOR_BLUE_1                    (21)
#define I_WON_THE_FIGHT_POS_X_2                         (886)
#define I_WON_THE_FIGHT_POS_Y_2                         (739)
#define I_WON_THE_FIGHT_COLOR_RED_2                     (214)
#define I_WON_THE_FIGHT_COLOR_GREEN_2                   (161)
#define I_WON_THE_FIGHT_COLOR_BLUE_2                    (19)
#define I_WON_THE_FIGHT_POS_X_3                         (1021)
#define I_WON_THE_FIGHT_POS_Y_3                         (765)
#define I_WON_THE_FIGHT_COLOR_RED_3                     (54)
#define I_WON_THE_FIGHT_COLOR_GREEN_3                   (56)
#define I_WON_THE_FIGHT_COLOR_BLUE_3                    (45)

#define PRE_FIGHT_RED_POSITION_COLOR_RED				(221)
#define PRE_FIGHT_RED_POSITION_COLOR_GREEN				(34)
#define PRE_FIGHT_RED_POSITION_COLOR_BLUE				(0)

#define IS_THE_FIGHT_FINISHED_POS_X_1					(910)
#define IS_THE_FIGHT_FINISHED_POS_Y_1					(738)
#define IS_THE_FIGHT_FINISHED_COLOR_RED_1				(244)
#define IS_THE_FIGHT_FINISHED_COLOR_GREEN_1				(227)
#define IS_THE_FIGHT_FINISHED_COLOR_BLUE_1				(49)
#define IS_THE_FIGHT_FINISHED_POS_X_2					(904)
#define IS_THE_FIGHT_FINISHED_POS_Y_2					(769)
#define IS_THE_FIGHT_FINISHED_COLOR_RED_2				(53)
#define IS_THE_FIGHT_FINISHED_COLOR_GREEN_2				(55)
#define IS_THE_FIGHT_FINISHED_COLOR_BLUE_2				(44)
#define IS_THE_FIGHT_FINISHED_POS_X_3					(1017)
#define IS_THE_FIGHT_FINISHED_POS_Y_3					(746)
#define IS_THE_FIGHT_FINISHED_COLOR_RED_3				(214)
#define IS_THE_FIGHT_FINISHED_COLOR_GREEN_3				(162)
#define IS_THE_FIGHT_FINISHED_COLOR_BLUE_3				(19)

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

#define ERROR_GET_COLOUR_BIG										(50)
#define ERROR_GET_COLOUR											(25)
#define ERROR_GET_COLOUR_SOME										(20)
#define ERROR_GET_COLOUR_QUITE										(10)
#define ERROR_GET_COLOUR_SMALL										(5)
#define ERROR_GET_COLOUR_SMALLER									(1)
#define POSIBLE_FIGHT_POSITIONS										(8)




/**************************
 * GLOBAL VARIABLES
 **************************/
#ifdef DEFINE_VARIABLES
#define EXTERN /* nothing */
#else
#define EXTERN extern
#endif /* DEFINE_VARIABLES */

EXTERN std::string current_pj_;

/* Roadmap */
EXTERN bool restart_roadmap_;
EXTERN bool first_time_go_to_initial_map_;
EXTERN bool lowering_pods_;
EXTERN bool use_zaap_;
EXTERN std::string zaap_file_;

EXTERN int x_roadmap_;
EXTERN int y_roadmap_;

/* Fight */;
EXTERN int myselfFightMenuPosition_;
EXTERN int black_position_;

EXTERN int turnNumber_;
EXTERN int bastionRemainingTurns_;

EXTERN bool sequential_;
EXTERN bool hunting_;
EXTERN bool invos_;
EXTERN bool heal_;

EXTERN std::vector<void(*)()> GoKillMonsters_funcs_;
EXTERN int go_kill_monsters_;
EXTERN std::pair<int, int> myself_in_the_arena_pos_;

/* Checks */;
EXTERN bool talking_with_npj_disable_check_;