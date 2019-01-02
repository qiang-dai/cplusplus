//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_FILETOOL_H
#define UNTITLED1_FILETOOL_H

#include "iostream"
#include "list"
#include "vector"

using namespace std;
class FileTool
{
public:
    //without short name
    static string get_pure_dir(const string &filename);
    static string get_absolute_dir(const string &filename);
    static bool is_exist(const string &filename);
    static bool is_readable(const string &filename);
    static bool is_writable(const string &filename);
    static bool is_executable(const string &filename);
    //get short name
    static string get_short_name(const string &filename);
    //without dot, like a.mp4 -> mp4
    static string get_suffix(const string &filename);
    //tail with '/'
    static string format_dir(string &dir);
    static list<string> get_files(const string dir, bool is_recursive = false);
    static list<string> get_dirs(const string dir, bool is_recursive = false);
    static int get_files(const string path, list<string> &file_name, list<string> &dir_name,
            bool is_recursive = false);
};

#endif //UNTITLED1_FILETOOL_H
