#ifndef PERSONAL_WEEK_CALENDAR_TIME_POINT_H
#define PERSONAL_WEEK_CALENDAR_TIME_POINT_H


class TimePoint {
private:
    enum day {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    };

    day weekday;
    int hour = 0, minute = 0;


public:
    TimePoint(day& weekday,const int& hour, const int& minute);
};


#endif //PERSONAL_WEEK_CALENDAR_TIME_POINT_H
