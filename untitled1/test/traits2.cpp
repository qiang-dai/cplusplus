//
// Created by xinmei365 on 2019/1/16.
//

#include <iostream>

using namespace std;

class Parent{};
class Child : public Parent{}; //class Child : Parent{}，为private继承
class Alone{};

int maintr1()
{
    cout << std::boolalpha; //以下的0、1按false和true格式输出

    /*基本的type_traits用法*/
    cout << is_const<int>::value << endl;         //false
    cout << is_const<const int>::value << endl;   //true
    cout << is_const<const int&>::value << endl;  //false
    cout << is_const<const int*>::value << endl;  //false
    cout << is_const<int* const>::value << endl;  //true

    /*is_same用法*/
    cout << is_same<int, int>::value << endl;         //true
    cout << is_same<int, unsigned int>::value << endl;//false
    cout << is_same<int, signed int>:: value << endl; //true

    /*is_base_of*/
    cout << is_base_of<Parent, Child>:: value << endl; //true
    cout << is_base_of<Child, Parent>:: value << endl; //false
    cout << is_base_of<Parent, Alone>:: value << endl; //false

    /*is_convertible<From, To>用法：判断From类型是否可以转为To类型*/
    cout << is_convertible<Parent*, Child*>:: value << endl; //false
    cout << is_convertible<Child*, Parent*>:: value << endl; //true
    cout << is_convertible<Parent*, Alone*>:: value << endl; //false
    return 0;
}