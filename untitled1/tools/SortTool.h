//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_SORTTOOL_H
#define UNTITLED1_SORTTOOL_H

#include "list"
#include "vector"
#include "iostream"

using namespace std;

class SortTool
{
public:
    static bool less_int(int a, int b);
    static bool sort_list(list<int> &tmp_list);
    static bool sort_vector(vector<int> &vec);
    static bool reverse_list(list<int> &tmp_list);
    static bool reverse_vector(vector<int> &vec);
};

#endif //UNTITLED1_SORTTOOL_H
