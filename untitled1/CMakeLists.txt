cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_ROOT "/usr/local/include/boost")
find_package(Boost 1.68.0 COMPONENTS log thread system regex date_time REQUIRED)

#add_subdirectory(googletest/googletest)
#include_directories(googletest/googletest/include)
#link_directories(googletest/googletest)

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
add_executable(untitled1 history/main.cpp history/main2.cpp Book.cpp Book.h X.cpp X.h Child.cpp Child.h tt.cpp tt.h MyString.cpp MyString.h history/main3.cpp history/main4.cpp history/main5.cpp history/main6.cpp history/main7.cpp history/main8.cpp Test.cpp Test.h TestAdd.cpp TestAdd.h history/main9.cpp thread/thread1.cpp thread/thread2.cpp thread/thread3.cpp thread/thread4.cpp tools/TimeTool.cpp tools/TimeTool.h tools/IOTool.cpp tools/IOTool.h tools/FileTool.cpp tools/FileTool.h tools/ShellTool.cpp tools/ShellTool.h tools/SortTool.cpp tools/SortTool.h mian.cpp test/ShellToolTest.cpp)
target_link_libraries(${PROJECT_NAME} gtest)