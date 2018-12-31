//
// Created by xinmei365 on 2018/12/28.
//

#ifndef UNTITLED1_CHILD_H
#define UNTITLED1_CHILD_H

#include <boost/shared_ptr.hpp>
#include "iostream"
using namespace std;
class Parent;
class Child;
typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<Child> child_ptr;

class Child {
public:
    Child()
    {
        cout << "Child..." << endl;
    }
    ~Child()
    {
        cout << "~Child..." << endl;
    }
    void show() {
        cout << "show Child..." << endl;
    }

    parent_ptr parent_;

};

class Parent
{
public:
    Parent()
    {
        cout << "Parent..." << endl;
    }
    ~Parent()
    {
        cout << "~Parent..." << endl;
    }
    child_ptr child_;
    //boost::weak_ptr<Parent> child_;
};


#endif //UNTITLED1_CHILD_H
