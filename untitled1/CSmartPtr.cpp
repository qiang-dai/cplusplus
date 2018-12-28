//
// Created by xinmei365 on 2018/12/28.
//
#include <cstdio>
#include <iostream>
#include "CSmartPtr.h"
using namespace std;

template <class T>
CSmartPtr<T>::CSmartPtr(T *p) {
    m_pointer = p;
    if (m_pointer != NULL)
    {
        std::cout << "Constructor:" << m_pointer->UseCnt << endl;
    }
}

template <class T>
CSmartPtr<T>::CSmartPtr(const CSmartPtr<T>& obj) {
    m_pointer = obj.m_pointer;
    ++m_pointer->UseCnt;
    cout << "Copy Constructor" << m_pointer->UseCnt << endl;
}

template <class T>
CSmartPtr<T>::~CSmartPtr() {
    if (m_pointer != NULL && --m_pointer->UseCnt == 0) {
        cout << "Destructor: " << m_pointer->UseCnt << endl;
        delete m_pointer;
    }
}

template<class T>
CSmartPtr<T>& CSmartPtr<T>::operator=(const CSmartPtr<T> &obj) {
    if (this != &obj) {
        if (m_pointer != NULL && --m_pointer->UseCnt == 0) {
            delete m_pointer;
        }
        m_pointer = obj.m_pointer;
        ++m_pointer->UseCnt;
        cout << "set value: " << m_pointer->UseCnt << endl;
    }
    return *this;
}

template<class T>
T* CSmartPtr<T>::operator->() { return m_pointer; }
template <class T>
T& CSmartPtr<T>::operator*() { return *m_pointer; }
template <class T>
T* CSmartPtr<T>::get() { return m_pointer; }

CWorkPtr::CWorkPtr() : UseCnt(1){ cout << "constructor called!" << endl;}
CWorkPtr::~CWorkPtr() {cout << "distructor called!" << endl;}
void CWorkPtr::Disp() {cout << "I'm CWorkPtr, implemented the main function.Now I am refed by "
<< UseCnt << " SmartPtrs." << endl;}
