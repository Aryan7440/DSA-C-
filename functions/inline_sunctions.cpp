#include <iostream>
using namespace std;



//inline fuctions are the fuctions which are expanded in line when it is called


inline int inline_func(int a, int b)
{
    return (a * b);
}

int main()
{
    cout<<"product is:"<<inline_func(4,7);
}