//
// Created by xinmei365 on 2019/1/16.
//

#ifndef UNTITLED1_LOGTOOL_H
#define UNTITLED1_LOGTOOL_H

#define ___TRACE(...) fprintf(stdout, "%s,%u,%s  ",__FILE__,__LINE__,__func__);\
fprintf(stdout, __VA_ARGS__)

#endif //UNTITLED1_LOGTOOL_H
