cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "/usr/local/include/boost")
find_package(Boost 1.68.0 COMPONENTS log thread system regex date_time REQUIRED)

SET(SOURCE_FILES
        CSmartPtr.cpp
        history/main2.cpp
        history/main.cpp
        history/main9.cpp
        Book.cpp
        X.cpp
        tt.cpp
        MyString.cpp
        )
add_executable(untitled1 history/main.cpp history/main2.cpp Book.cpp Book.h X.cpp X.h Child.cpp Child.h tt.cpp tt.h MyString.cpp MyString.h history/main3.cpp history/main4.cpp history/main5.cpp history/main6.cpp tools/io_tool.h tools/sort.h tools/io_tool.cpp history/main7.cpp history/main8.cpp Test.cpp Test.h TestAdd.cpp TestAdd.h history/main9.cpp thread1.cpp)