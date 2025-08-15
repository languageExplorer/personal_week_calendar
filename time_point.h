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
    TimePoint(day weekday, int hour, int minute);

    int getMinute() const;
    int getHour() const;
    day getWeekday() const;

    void setMinute(const int& minute);
    void setHour(const int& hour);
    void setWeekday(const day& weekday);

    TimePoint operator+ (TimePoint&);
    TimePoint operator- (TimePoint&);
};


#endif //PERSONAL_WEEK_CALENDAR_TIME_POINT_H
