//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_TIME_TOOL_H
#define UNTITLED1_TIME_TOOL_H

#include "iostream"
#include "string"
#include "ctime"
#include "IOTool.h"

using namespace std;

class TimeTool
{
public:
    //Tue Jan  1 10:17:40 2019
    static string get_current_desc();
    static time_t get_tick();
    static string get_day();
    static string get_us_day();
    static string get_date_second();
    static string get_date_full();
    static string transform_underline(string d);
    static string get_date_underline();
    //06/22/1983 or 06-22-1983
    static string read_us_day(string s, int &year, int &mon, int &day);
    //1983-06-22
    static string read_day(string s, int &year, int &mon, int &day);
};
#endif //UNTITLED1_TIME_TOOL_H
