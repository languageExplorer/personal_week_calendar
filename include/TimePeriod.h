#ifndef PERSONAL_WEEK_CALENDAR_TIMEPERIOD_H
#define PERSONAL_WEEK_CALENDAR_TIMEPERIOD_H

#include "TimePoint.h"

class TimePeriod {

    TimePoint start;
    TimePoint end;

    public:
    TimePeriod(TimePoint& start, TimePoint& end);
    explicit TimePeriod(TimePoint& start); // for events that have only starting point or fixed point in time
};

#endif //PERSONAL_WEEK_CALENDAR_TIMEPERIOD_H