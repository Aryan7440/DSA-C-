#include <iostream>
using namespace std;

int main()
{

    int(*p)[6]; // 6 arrays whose 1st element is pointed by p[0],p[1].......
    int(*pt)[6];
    int b[6][6] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36}};
    int a[] = {1, 2, 3, 4, 5, 6};
    p = &a;
    pt = b;
    int *ptr = a;
    cout<<sizeof(a)<<endl;                  //24   (6*4)
    cout<<sizeof(p[0])<<endl;             //24      p[0]=a
    cout<<sizeof(*p[0])<<endl;             //4     size of pointer is 4 in 32bit nad 8 in 64bit
    cout<<sizeof(b[0])<<endl;             //24     b[0] is an array of 6 elements
    cout<<sizeof(b)<<endl;             //144     b is an array of 6*6 elements

    double *pointer;
    double d=2.314141;
    pointer=&d;
    cout<<d<<" "<<sizeof(d)<<endl;                       //size of double is 8
    cout<<pointer<<" "<<sizeof(pointer)<<endl;              //size of pointer is 4 in 32bit
    cout<<*pointer<<" "<<sizeof(*pointer)<<endl;


}