#include <iostream>
#include <string>
#include <boost/scoped_ptr.hpp>
#include "CSmartPtr.cpp"
#include "Book.h"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "ok" << std::endl;

    cout << "=====Main Begin=====" << endl;
    boost::scoped_ptr<Book> myBook(new Book("[1984]"));
    myBook.reset();
    cout << "=====Main End=====" << endl;

    cout << "first contruct >>>" << endl;
    CSmartPtr<CWorkPtr> pNewPtr = new CWorkPtr();
    pNewPtr->Disp();
    cout << "first ref >>>" << endl;
    CSmartPtr<CWorkPtr> pRef1 = pNewPtr;
    cout << "second ref>>>" << endl;
    CSmartPtr<CWorkPtr> pRef2;
    pRef2 = pRef1;
    pNewPtr->Disp();

    return 0;
}


int main2() {
    cout << "first contruct >>>" << endl;
    CSmartPtr<CWorkPtr> pNewPtr = new CWorkPtr();
    pNewPtr->Disp();
    cout << "first ref >>>" << endl;
    CSmartPtr<CWorkPtr> pRef1 = pNewPtr;
    cout << "second ref>>>" << endl;
    CSmartPtr<CWorkPtr> pRef2;
    pRef2 = pRef1;
    pNewPtr->Disp();

    return 0;
}


