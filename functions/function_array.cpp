#include<iostream>
using namespace std;

int sum(int a,int b)
{
    return a+b;
}
int difference(int a,int b)
{
    return a-b;
}

int product(int a,int b)
{
    return a*b;
}
int division(int a,int b)
{
    return a/b;
}

int main()
{
    int (*func_ptr_array[])(int,int)={sum,difference,product,division};
    for (int i = 0; i < 4; i++)
    {
        cout<< func_ptr_array[i](5,4)<<endl;
    }
    
    
    
}