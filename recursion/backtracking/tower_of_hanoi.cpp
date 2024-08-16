#include<iostream>
using namespace std;


void TOH(int n,char beg,char ox,char end)
{
    if(n>=1)
    {
        TOH(n-1,beg,end,ox);
        cout<<beg<<" TO "<<end<<endl;
        TOH(n-1,ox,beg,end);
    }
    return;
}


int main()
{
    TOH(3,'a','b','c');
}