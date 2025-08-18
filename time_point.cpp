#include "time_point.h"
#include <iostream>

TimePoint::TimePoint(day weekday, int hour, int minute)
    : weekday(weekday), hour(hour), minute(minute) {
}

int TimePoint::getMinute() const { return minute; }
int TimePoint::getHour() const { return hour; }
TimePoint::day TimePoint::getWeekday() const { return weekday; }

void TimePoint::setMinute(int minute) {
    if (minute < 0 || minute >= 60) {
        std::cout << "Invalid minute: " << minute << std::endl;
        return;
    }
    this->minute = minute;
}

void TimePoint::setHour(int hour) {
    if (hour < 0 || hour >= 24) {
        std::cout << "Invalid hour: " << hour << std::endl;
        return;
    }
    this->hour = hour;
}

void TimePoint::setWeekday(day weekday) {
    this->weekday = weekday;
}


TimePoint TimePoint::operator+(TimePoint &other) {
    int new_minute = this->minute + other.minute;
    int new_hour = this->hour + other.hour;
    day new_weekday = this->weekday;

    if (new_minute >= 60) {
        new_minute = new_minute / 60;
        new_hour++;
    }

    if (new_hour >= 24) {
        new_hour = new_hour / 24;
        if (new_weekday == SUNDAY) {
            std::cout << "Cannot schedule past Sunday! Sunday 23:59 is to be returned";
            return {SUNDAY, 23, 59};
        }
        new_weekday = static_cast<day>(new_weekday + 1);
    }
    return {new_weekday, new_hour, new_minute};
}

TimePoint TimePoint::operator-(TimePoint &other) {
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