cmake_minimum_required(VERSION 3.28)
project(Staff_Management___01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Staff_Management___01
        ManagerSystem.cpp
        workerManager.cpp
        workerManager.h
        worker.h
        employee.h
        employee.cpp
        manager.h
        manager.cpp
        boss.h
        boss.cpp)
