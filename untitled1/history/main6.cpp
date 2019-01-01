//
// Created by xinmei365 on 2018/12/31.
//
#include <boost/scoped_ptr.hpp>
#include "iostream"
#include "sstream"
#include "../tools/sort.h"

using namespace std;
int main61()
{
    istringstream istr("1 56.7");
    cout << istr.str() << endl;

    string str = istr.str();
    cout << str << endl;

    int n;
    double d;
//    istr >> n;
//    istr >> d;
    cout << "d= " << d << endl;
    cout << "n= " << n << endl;

    istr >> d;
    istr >> n;

    cout << "d= " << d << endl;
    cout << "n= " << n << endl;

    return 0;
}

int main62()
{
    istringstream istr;
    string line, str;
    while(getline(cin, line)) {
        istr.str(line);
        while(istr >> str) {
            cout << str << endl;
        }
    }

    return 0;
}



int main66()
{
}