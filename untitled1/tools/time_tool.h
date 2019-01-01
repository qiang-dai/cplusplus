//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_TIME_TOOL_H
#define UNTITLED1_TIME_TOOL_H

#include "iostream"
#include "string"
#include "ctime"
#include "io_tool.h"

using namespace std;

class time_tool
{
public:
    //Tue Jan  1 10:17:40 2019
    static string get_current_desc()
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        return dt;
    }
    static time_t get_tick()
    {
        time_t now = time(0);
        return now;
    }
    static string get_day()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char s[256];
        sprintf(s, "%02d-%02d-%02d",
                1900+ltm->tm_year,
                1 + ltm->tm_mon,
                ltm->tm_mday);
        string str(s);
        return str;
    }
    static string get_us_day()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char s[256];
        sprintf(s, "%02d-%02d-%02d",
                1 + ltm->tm_mon,
                ltm->tm_mday,
                1900+ltm->tm_year);
        string str(s);
        return str;
    }

    static string get_date_second()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char s[256];
        sprintf(s, "%02d:%02d:%02d",
                ltm->tm_hour,
                ltm->tm_min,
                ltm->tm_sec);
        string str(s);
        return str;
    }
    static string get_date_full()
    {
        string day = get_day();
        string second = get_date_second();
        return day + " " + second;
    }
    static string transform_underline(string d)
    {
        string res("");
        for(int i = 0; i < d.size(); i++)
        {
            if (d[i] == ' ' || d[i] == '-' || d[i] == ':')
            {
                res += '_';
            }
            else
            {
                res += d[i];
            }
        }
        return res;
    }
    static string get_date_underline()
    {
        string d = get_date_full();
        string res = transform_underline(d);
        return res;
    }

    //06/22/1983 or 06-22-1983
    static string read_us_day(string s, int &year, int &mon, int &day)
    {
        string res("");
        for(int i =0; i < s.size(); i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                res += s[i];
            }
            else
            {
                res += ' ';
            }
        }
        stringstream ss(res);
        ss >> mon;
        ss >> day;
        ss >> year;

        return s;
    }

    //1983-06-22
    static string read_day(string s, int &year, int &mon, int &day)
    {
        string res("");
        for(int i =0; i < s.size(); i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                res += s[i];
            }
            else
            {
                res += ' ';
            }
        }
        stringstream ss(res);
        ss >> year;
        ss >> mon;
        ss >> day;

        return s;
    }

};

int main()
{
    cout << time_tool::get_current_desc() << endl;
    cout << "tick: " << time_tool::get_tick() << endl;
    cout << "day:  " << time_tool::get_day() << endl;
    cout << "second: " << time_tool::get_date_second() << endl;
    cout << "date full:" << time_tool::get_date_full() << endl;
    cout << "day underline: " << time_tool::get_date_underline() << endl;

    string s = time_tool::get_day();
    int year;
    int mon;
    int day;
    time_tool::read_day(s, year, mon, day);
    cout << "day: " << s << endl;
    cout << "read day: " << year << " " << mon << " " << day << endl;

    s = time_tool::get_us_day();
    cout << "us day: " << s << endl;
    time_tool::read_us_day(s, year, mon, day);
    cout << "read day: " << year << " " << mon << " " << day << endl;
}
#endif //UNTITLED1_TIME_TOOL_H
