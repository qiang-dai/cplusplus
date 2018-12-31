//
// Created by xinmei365 on 2018/12/30.
//

#include <iostream>
using namespace std;
void foo(int a[3])/*这个地方传递的是数组的首地址*/
{
    cout << sizeof(a)/sizeof(a[0]) << endl;
}
void bar(int (&a)[3])/*这里传参的时候就是数组的整体*/
{
    cout << sizeof(a)/sizeof(a[0]) << endl;
}
int main31(void)
{
    int a;
    int* p = &a;
    int** pp = &p;/*存在指向指针的指针*/
    int& r  = a;
//    int&& rr = r;/*error没有引用引用的引用*/
    int*&  rp = p; /*有引用指针的引用(指针引用)*/
//    int&* pr = &r; /*没有指向引用的指针(引用指针)*/
    int x, y, z;
    int* pa[] = {&x,&y,&z};/*指针数组*/
//    int& ra[] = {x,y,z};/*引用数组是不存在的因为引用不是一个实体*/
    int arr[3] = {0};
    int (&ar)[3] = arr;/*数组引用(先近后远,先右后左)*/
    foo(arr);/*这里传递的是数组的第一个元素的首地址*/
    cout << sizeof(arr)/sizeof(arr[0]) << endl;
    /*这里的数组名代表的是真个数组*/
    int (*parr)[3] = &arr;/*对数组名取地址得到的是一个数组指针
                             这个时候arr代表的是数组的整体;*/
    bar(arr);/*这里传递的就是数组的整体*/
    return 0;
}