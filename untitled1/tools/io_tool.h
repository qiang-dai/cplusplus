//
// Created by xinmei365 on 2018/12/31.
//

#ifndef UNTITLED1_IO_TOOL_H
#define UNTITLED1_IO_TOOL_H

#include <vector>
#include <list>
#include "string"
#include "fstream"
#include "iostream"
#include "sstream"

using namespace std;
///////////////////////////////////////////////////
string read_line(string filename);
vector<string> read(string filename, int limit = 10000);
list<string> read_list(string filename, int limit = 10000);
bool write(string filename, string s);
bool write(string filename, vector<string> vec);
///////////////////////////////////////////////////
long get_files_size(string filename);
///////////////////////////////////////////////////
char *read_binary(string filename);
string long2string(long v);
string int2string(int v);
string double2string(double v);
int string2int(string s);
long string2long(string s);
double string2double(string s);
string size_to_read(long size);

#endif //UNTITLED1_IO_TOOL_H
