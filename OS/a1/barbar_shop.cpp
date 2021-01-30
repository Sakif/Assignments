#include "barbar_shop.hpp"

int queue_size, queue_head, queue_tail, customers_served, walk_away;
int service_time_countdown, current_time;

void
init()
{
	queue_size = 3;
}
