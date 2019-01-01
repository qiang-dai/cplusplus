//
// Created by xinmei365 on 2019/1/1.
//

#include "TimeTool.h"
//Tue Jan  1 10:17:40 2019
string TimeTool::get_current_desc()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    return dt;
}
time_t TimeTool::get_tick()
{
    time_t now = time(0);
    return now;
}
string TimeTool::get_day()
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
string TimeTool::get_us_day()
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

string TimeTool::get_date_second()
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
string TimeTool::get_date_full()
{
    string day = get_day();
    string second = get_date_second();
    return day + " " + second;
}
string TimeTool::transform_underline(string d)
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
string TimeTool::get_date_underline()
{
    string d = get_date_full();
    string res = transform_underline(d);
    return res;
}

//06/22/1983 or 06-22-1983
string TimeTool::read_us_day(string s, int &year, int &mon, int &day)
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
string TimeTool::read_day(string s, int &year, int &mon, int &day)
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