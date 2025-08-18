cmake_minimum_required(VERSION 4.0)
project(personal_week_calendar)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(personal_week_calendar
        src/TimePoint.cpp
        include/TimePoint.h
        include/TimePeriod.h
        src/TimePeriod.cpp)
