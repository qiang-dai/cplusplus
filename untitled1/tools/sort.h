//
// Created by xinmei365 on 2018/12/31.
//

#ifndef UNTITLED1_SORT_H
#define UNTITLED1_SORT_H

#include <vector>
#include <algorithm>
using namespace std;


bool less_int(int a, int b)
{
    return b < a;
}

bool sort_vector(vector<int> &vec)
{
    //sort(vec.begin(), vec.end());
    sort(vec.begin(), vec.end(), less_int);
    return true;
}


#endif //UNTITLED1_SORT_H
