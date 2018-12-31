//
// Created by xinmei365 on 2018/12/31.
//
#include "iostream"
#include "sstream"

using namespace std;
int main()
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

