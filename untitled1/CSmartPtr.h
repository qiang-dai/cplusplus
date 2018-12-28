#pragma once
//
// Created by xinmei365 on 2018/12/28.
//
#include <cstdio>
#include <iostream>
#ifndef UNTITLED1_CSMARTPTR_H
#define UNTITLED1_CSMARTPTR_H

template <class T>
class CSmartPtr {
    T* m_pointer;

public:
    CSmartPtr(T* p = NULL);
    CSmartPtr(const CSmartPtr<T>& obj);
    ~CSmartPtr();

    CSmartPtr<T>&operator=(const CSmartPtr<T>& obj);
    T* operator->();
    T& operator*();
    T* get();
};

class CWorkPtr
{
    template <class T> friend class CSmartPtr;
    int UseCnt;
public:
    CWorkPtr();
    ~CWorkPtr();
    void Disp();
};
#endif //UNTITLED1_CSMARTPTR_H
