#pragma once
#include <iostream>
#include <ctime>

/**
 * @file actualTime.hpp
 * @brief Small helpers to obtain and print the current system time.
 */

/**
 * @brief Print the current local time to stdout in a human friendly format.
 */
void PrintTime();

/**
 * @brief Get the current year (local time).
 * @return int Year (e.g. 2025).
 */
int GetYear();

/**
 * @brief Get the current month (1-12).
 * @return int Month number.
 */
int GetMonth();

/**
 * @brief Get the current day of month (1-31).
 * @return int Day of month.
 */
int GetDay();

/**
 * @brief Get the current hour (0-23).
 * @return int Hour.
 */
int GetHour();

/**
 * @brief Get the current minute (0-59).
 * @return int Minute.
 */
int GetMin();

/**
 * @brief Get the current second (0-59).
 * @return int Second.
 */
int GetSec();