cmake_minimum_required(VERSION 3.15)
project(Vroomvroom)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vroomvroom main.cpp core/Screen.cpp core/Screen.h core/Controls.h core/Controls.cpp road.cpp road.h PlayerCar.cpp PlayerCar.h entities/Entity.cpp entities/Entity.h entities/Nail.cpp entities/Nail.h core/EntityManager.cpp core/EntityManager.h core/globals.cpp core/globals.h entities/FuelTank.cpp entities/FuelTank.h)

include_directories(${PROJECT_SOURCE_DIR}/entities)
include_directories(${PROJECT_SOURCE_DIR}/core)
