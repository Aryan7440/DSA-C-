#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}

int main()
{
    int a=4,b=7;
    swap(a,b);
    cout<<a<<" "<<b;
}