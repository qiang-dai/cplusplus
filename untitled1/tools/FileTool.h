//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_FILETOOL_H
#define UNTITLED1_FILETOOL_H

#include "iostream"
#include "list"

using namespace std;
class FileTool
{
public:
    //without short name
    static string get_pure_dir(string s);
    //get short name
    static string get_short_name(string s);
    //tail with '/'
    static string format_dir(string s);
    static list<string> get_files(string dir);
    static list<string> get_dirs(string dir);
};


#endif //UNTITLED1_FILETOOL_H
