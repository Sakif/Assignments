#pragma once
#include <ctime>
#include <float.h>
#include <iostream>
#include <string>

int days_to_simulate = 1;

auto daily_average_minimum = DBL_MAX;
auto daily_average_maximum = DBL_MIN;
auto daily_std_dev_minimum = DBL_MAX;
auto daily_std_dev_maximum = DBL_MIN;

void print_daily_stats(struct mean_dev d[], int size);
