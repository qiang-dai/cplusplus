//
// Created by xinmei365 on 2018/12/31.
//
#include <vector>
#include <list>
#include "string"
#include "fstream"
#include "iostream"
#include "sstream"
#include "io_tool.h"

using namespace std;
///////////////////////////////////////////////////
string read_line(string filename) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
        exit(1);
    }

    while(!in.eof())
    {
        in.getline(buffer, 255);
        break;
    }
    in.close();
    return buffer;
}
vector<string> read(string filename, int limit) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
    }

    vector<string> vec;
    while (!in.eof())
    {
        in.getline(buffer, 255);
        vec.push_back(buffer);
        if (vec.size() >= limit) {
            break;
        }
    }
    in.close();
    //trim last empty string
    if (vec.size() > 0 && vec[vec.size() - 1] == "") {
        vec.pop_back();
    }

    return vec;
}
list<string> read_list(string filename, int limit) {
    char buffer[256];
    ifstream in(filename);
    if (!in.is_open())
    {
        cout << "Error opening file:" + filename << endl;
    }

    list<string> tmp_list;
    while (!in.eof())
    {
        in.getline(buffer, 255);
        tmp_list.push_back(buffer);
        if (tmp_list.size() >= limit) {
            break;
        }
    }
    in.close();
    //trim last empty string
    if (tmp_list.size() > 0 && buffer[0] == '\0') {
        tmp_list.pop_back();
    }


    return tmp_list;
}
///////////////////////////////////////////////////
char *read_binary(string filename)
{
    long size = get_files_size(filename);
    char *buffer = new char[size];
    ifstream in(filename, ios::in|ios::binary);
    in.read(buffer, size);
    in.close();

//    for(int i = 0; i < size; i++)
//    {
//        cout << (char)(*(buffer + i)) << endl;
//    }

    return buffer;
}
///////////////////////////////////////////////////
bool write(string filename, string s) {
    ofstream out(filename);
    if (out.is_open())
    {
        out << s << endl;
    }
    return true;
}

bool write(string filename, vector<string> vec)
{
    ofstream out(filename);
    for(int i = 0; i < vec.size(); i++)
    {
        out << vec[i] << endl;
    }
    return true;
}
///////////////////////////////////////////////////
long get_files_size(string filename)
{
    long l,m;
    ifstream in(filename, ios::in|ios::binary);
    l = in.tellg();
    in.seekg(0, ios::end);
    m = in.tellg();
    in.close();

    return m - l;
}

string long2string(long v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
string int2string(int v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
string double2string(double v)
{
    ostringstream ss;
    ss << v;
    return ss.str();
}
int string2int(string s)
{
    int n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
long string2long(string s)
{
    long n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
double string2double(string s)
{
    double n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
}
string size_to_read(long size)
{
    static char arr[3] = {'K', 'M', 'G'};
    int unit = 1024;
    string s = "";
    for(int i = -1; i < 3; i++)
    {
        int v = size%unit;
        string tmp = int2string(v);

        if (v != 0)
        {
            if ( i >= 0)
            {
                s = ' ' + s;
                s = arr[i] + s;
            }
            s = tmp + s;
        }

        size = size/unit;
        if (size == 0) {
            break;
        }
    }
    return s;
}
