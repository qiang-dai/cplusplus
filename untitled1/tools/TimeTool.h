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

int main()
{
    cout << TimeTool::get_current_desc() << endl;
    cout << "tick: " << TimeTool::get_tick() << endl;
    cout << "day:  " << TimeTool::get_day() << endl;
    cout << "second: " << TimeTool::get_date_second() << endl;
    cout << "date full:" << TimeTool::get_date_full() << endl;
    cout << "day underline: " << TimeTool::get_date_underline() << endl;

    string s = TimeTool::get_day();
    int year;
    int mon;
    int day;
    TimeTool::read_day(s, year, mon, day);
    cout << "day: " << s << endl;
    cout << "read day: " << year << " " << mon << " " << day << endl;

    s = TimeTool::get_us_day();
    cout << "us day: " << s << endl;
    TimeTool::read_us_day(s, year, mon, day);
    cout << "read day: " << year << " " << mon << " " << day << endl;

    s = TimeTool::get_date_full();
    cout << "s: " << s << endl;
    string d = IOTool::replace(s, '-', ' ');
    cout << "d: " << d << endl;
    d = IOTool::replace(s, ':', ' ');
    cout << "d: " << d << endl;
    d = IOTool::replace(s, ' ', '_');
    cout << "d: " << d << endl;


    s = TimeTool::get_date_full();
    cout << "s: " << s << endl;
    d = IOTool::replace_first(s, '-', ' ');
    cout << "d: " << d << endl;
    d = IOTool::replace_first(s, ':', ' ');
    cout << "d: " << d << endl;
    d = IOTool::replace_first(s, ' ', '_');
    cout << "d: " << d << endl;
}
#endif //UNTITLED1_TIME_TOOL_H
