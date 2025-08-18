cmake_minimum_required(VERSION 4.0)
project(personal_week_calendar)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(personal_week_calendar
        time_point.cpp
        time_point.h)
