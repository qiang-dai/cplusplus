cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "/usr/local/include/boost")
find_package(Boost 1.68.0 COMPONENTS log thread system regex date_time REQUIRED)

SET(SOURCE_FILES
        CSmartPtr.cpp
        main.cpp
        Book.cpp
        )
add_executable(untitled1 main.cpp Book.cpp Book.h)