#include "time_point.h"
#include <iostream>
#include <format>
#include <string>

TimePoint::TimePoint(day weekday, int hour, int minute)
    : weekday(weekday), hour(hour), minute(minute) {
}

int TimePoint::getMinute() const { return minute; }
int TimePoint::getHour() const { return hour; }
TimePoint::day TimePoint::getWeekday() const { return weekday; }

void TimePoint::setMinute(int m) {
    if (m < 0 || m >= 60) {
        std::cout << "Invalid minute: " << m << std::endl;
        return;
    }
    this->minute = m;
}

void TimePoint::setHour(int h) {
    if (h < 0 || h >= 24) {
        std::cout << "Invalid hour: " << h << std::endl;
        return;
    }
    this->hour = h;
}

void TimePoint::setWeekday(day d) {
    this->weekday = d;
}


TimePoint TimePoint::operator+(const TimePoint &other) const {
    int new_minute = this->minute + other.minute;
    int new_hour = this->hour + other.hour;
    day new_weekday = this->weekday;

    if (new_minute >= 60) {
        new_minute = new_minute - 60;
        new_hour++;
    }

    if (new_hour >= 24) {
        new_hour = new_hour - 24;
        if (new_weekday == SUNDAY) {
            std::cout << "Cannot schedule past Sunday! Sunday 23:59 is to be returned";
            return {SUNDAY, 23, 59};
        }
        new_weekday = static_cast<day>(new_weekday + 1);
    }
    return {new_weekday, new_hour, new_minute};
}

TimePoint TimePoint::operator-(const TimePoint &other) const {
    int new_minute = this->minute - other.minute;
    int new_hour = this->hour - other.hour;
    day new_weekday = this->weekday;

    if (new_minute < 0) {
        new_minute = new_minute + 60;
        new_hour--;
    }

    if (new_hour < 0) {
        new_hour = new_hour + 24;
        if (new_weekday == MONDAY) {
            std::cout << "Cannot schedule before Monday! Monday 00:00 is to be returned";
            return {MONDAY, 0, 0};
        }
        new_weekday = static_cast<day>(new_weekday - 1);
    }
    return {new_weekday, new_hour, new_minute};
}

std::string TimePoint::dayToString(day d) {
    switch (d) {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
        default: return "Invalid day";
    }
}

std::ostream& operator<<(std::ostream& os, const TimePoint& tp) {
    os << TimePoint::dayToString(tp.getWeekday()) <<
        std::format(" {:02}:{:02}", tp.getHour(), tp.getMinute());
    return os;
}