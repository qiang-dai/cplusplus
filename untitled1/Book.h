//
// Created by xinmei365 on 2018/12/28.
//

#ifndef UNTITLED1_BOOK_H
#define UNTITLED1_BOOK_H

#include "string"
#include <cstdio>
#include <iostream>
using namespace std;

class Book
{
private:
    string name_ ;

public:
    Book(string name) : name_(name)
    {
        cout << "Creating book" << name_ << "..." << endl;
    }

    ~Book()
    {
        cout << "Destroying bood" << name_ << "..." << endl;
    }
};


#endif //UNTITLED1_BOOK_H
