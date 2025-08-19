#include "../include/TimePeriod.h"

TimePeriod::TimePeriod(TimePoint &start, TimePoint &end)
    : start(start), end(end) {}

TimePeriod::TimePeriod(TimePoint &start)
    : start(start), end(start) {}
