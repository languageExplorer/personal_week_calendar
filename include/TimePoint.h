#ifndef PERSONAL_WEEK_CALENDAR_TIME_POINT_H
#define PERSONAL_WEEK_CALENDAR_TIME_POINT_H
#include <iosfwd>


class TimePoint {
public:
    enum day {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    };

private:
    day weekday;
    int hour = 0, minute = 0;

public:
    TimePoint(day weekday, int hour, int minute);

    [[nodiscard]] int getMinute() const;
    [[nodiscard]] int getHour() const;
    [[nodiscard]] day getWeekday() const;

    void setMinute(int m);
    void setHour(int h);
    void setWeekday(day d);

    [[nodiscard]] TimePoint operator+ (const TimePoint&) const;
    [[nodiscard]] TimePoint operator- (const TimePoint&) const;

    static std::string dayToString(day d);
    friend std::ostream& operator<<(std::ostream& os, const TimePoint& tp);
};

#endif //PERSONAL_WEEK_CALENDAR_TIME_POINT_H
