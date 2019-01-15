//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_IOTOOL_H
#define UNTITLED1_IOTOOL_H

#include <vector>
#include <list>
#include "string"
#include "fstream"
#include "iostream"
#include "sstream"
#include <algorithm>
#include "boost/scoped_ptr.hpp"
#include "boost/scoped_array.hpp"

using namespace std;

class IOTool
{
public:
    ///////////////////////////////////////////////////
    static string read_line(const string filename);
    static list<string> read(const string filename, int limit = 10000);
    static list<string> read_list(const string filename, int limit = 10000);
    static bool write(const string filename, const string line);
    static bool write(const string filename, list<string> &line_list);
    ///////////////////////////////////////////////////
    static long get_files_size(const string filename);
    ///////////////////////////////////////////////////
    static char *read_binary(const string filename);
    static string long2string(long v);
    static string int2string(int v);
    static string double2string(double v);
    static int string2int(const string &s);
    static long string2long(const string &s);
    static double string2double(const string &s);
    static string size_to_read(long size);
    ///////////////////////////////////////////////////
    static string replace(string &src, char c, char d);
    static string replace_first(string &src, char c, char d);
};
#endif //UNTITLED1_IOTOOL_H
