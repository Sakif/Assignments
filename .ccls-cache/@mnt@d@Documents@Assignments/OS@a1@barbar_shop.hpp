#pragma once
#include <cmath>
#include <list>

#ifndef BARBAR_SHOP
#define BARBAR_SHOP

/* Bob calls it a day either when he has given 40 haircuts */
#define MAX_CUSTOMERS_SERVED 40

/* how many people can be seated at a time */
#define MAX_QUEUE_LENGTH 5

/* 8 h * 60 min = 480 */
#define END_OF_DAY 480

/* define cut time ranges */
#define MIN_CUT_TIME 10
#define MAX_CUT_TIME 20

extern std::list<int> served_customer_wait_times;
extern std::list<int> queued_customer_wait_times;

extern int queue_size, queue_head, queue_tail, customers_served, walk_away;
extern int service_time_countdown, current_time;

void
init();
#endif
