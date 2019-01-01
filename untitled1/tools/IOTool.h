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
#include "boost/scoped_ptr.hpp"
#include "boost/scoped_array.hpp"

using namespace std;

class IOTool
{
public:
    ///////////////////////////////////////////////////
    static string read_line(string filename);
    static vector<string> read(string filename, int limit = 10000);
    static list<string> read_list(string filename, int limit = 10000);
    static bool write(string filename, string s);
    static bool write(string filename, vector<string> vec);
    ///////////////////////////////////////////////////
    static long get_files_size(string filename);
    ///////////////////////////////////////////////////
    static char *read_binary(string filename);
    static string long2string(long v);
    static string int2string(int v);
    static string double2string(double v);
    static int string2int(string s);
    static long string2long(string s);
    static double string2double(string s);
    static string size_to_read(long size);
    ///////////////////////////////////////////////////
    static string replace(string src, string first, string second);

};


#endif //UNTITLED1_IOTOOL_H
