#include "time_point.h"

TimePoint::TimePoint(day &weekday, const int &hour, const int &minute)
    : weekday(weekday), hour(hour), minute(minute) {
}
