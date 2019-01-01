//
// Created by xinmei365 on 2019/1/1.
//

#ifndef UNTITLED1_SHELLTOOL_H
#define UNTITLED1_SHELLTOOL_H

#include "string"
#include "vector"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "iostream"
#include "boost/scoped_ptr.hpp"
using namespace std;

class ShellTool
{
public:
    static int32_t myexec(const char *cmd, vector<string> &resvec);
};


#endif //UNTITLED1_SHELLTOOL_H
