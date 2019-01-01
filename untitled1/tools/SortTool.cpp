//
// Created by xinmei365 on 2019/1/1.
//

#include "SortTool.h"
bool SortTool::less_int(int a, int b)
{
    return b < a;
}
bool SortTool::sort_list(list<int> &tmp_list)
{
    tmp_list.sort();

    return true;
}
bool SortTool::sort_vector(vector<int> &vec)
{
    sort(vec.begin(), vec.end());

    return true;
}
bool SortTool::reverse_list(list<int> &tmp_list)
{
    tmp_list.sort(less_int);

    return true;
}
bool SortTool::reverse_vector(vector<int> &vec)
{
    sort(vec.begin(), vec.end(), less_int);

    return true;
}

/*
see more at:

https://blog.csdn.net/marising/article/details/4567531
 */
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(7);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << "orig: " << i << " " << vec[i] << endl;
    }
    SortTool::sort_vector(vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << "sort: " << i << " " << vec[i] << endl;
    }
    SortTool::reverse_vector(vec);
    for(int i = 0; i < vec.size(); i++)
    {
        cout << "reverse: " << i << " " << vec[i] << endl;
    }

    list<int> tmp_list;
    tmp_list.push_back(1);
    tmp_list.push_back(3);
    tmp_list.push_back(8);
    tmp_list.push_back(6);
    tmp_list.push_back(2);
    list<int>::iterator it;
    for(it = tmp_list.begin(); it != tmp_list.end(); ++it)
    {
        cout << "orig: " << *it << endl;
    }
    SortTool::sort_list(tmp_list);
    for(it = tmp_list.begin(); it != tmp_list.end(); ++it)
    {
        cout << "sort: " << *it << endl;
    }
    SortTool::reverse_list(tmp_list);
    for(it = tmp_list.begin(); it != tmp_list.end(); ++it)
    {
        cout << "reverse: " << *it << endl;
    }

}