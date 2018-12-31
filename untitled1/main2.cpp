#include <iostream>
#include <string>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "CSmartPtr.cpp"
#include "Book.h"
#include "X.h"
#include "Child.h"
#include "tt.h"
#include "MyString.h"

using namespace std;


int main21() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "ok" << std::endl;

    cout << "=====Main Begin=====" << endl;
    boost::scoped_ptr<Book> myBook(new Book("[1984]"));
    myBook.reset();
    cout << "=====Main End=====" << endl;

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

int main3() {
    cout << "Entering main..." << endl;
    boost::shared_ptr<X> p1(new X);
    cout << p1.use_count() << endl;
    boost::shared_ptr<X> p2 = p1;
    cout << p1.use_count() << endl;
    cout << " " << p2.use_count() << endl;
    boost::shared_ptr<X> p3;
    p3 = p1;

    cout << p2.use_count() << endl;
    p1.reset();
    cout << p2.use_count() << endl;
    p2.reset();
    cout << "Exiting main..." << endl;

    return 0;
}

int main4() {
    parent_ptr parent(new Parent);
    child_ptr child(new Child);
    parent->child_ = child;
    child->parent_ = parent;

    //child->parent_.reset();
    //parent->child_.reset();
    return 0;
}



int main5() {

    int *p = new int(2);

    tt test(std::move(p));

    //tt test2(p);//error

    delete p;

    p = nullptr;

    test.print();

    //getchar();
    int* a= new int(11);
    printf("%p", a);
    tt test1(a);
    tt test2(new int(10));
    test1.print();
    test2.print();

    return 0;
}

void process_value(int& i) {
    std::cout << "LValue processed: " << i << std::endl;
}

void process_value(int&& i) {
    std::cout << "RValue processed: " << i << std::endl;
}
void forward_value(int&& i) {
    process_value(i);
}

int main6() {
    int a = 0;
    process_value(a);
    process_value(1);
    forward_value(2);

    return 0;
}

int main7() {
//    MyString a;
//    a = MyString("Hello");
//    std::vector<MyString> vec;
//    vec.push_back(MyString("World"));

    return 0;
}