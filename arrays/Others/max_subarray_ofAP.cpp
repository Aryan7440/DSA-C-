#include <iostream>
using namespace std;
int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}

int maxAP(int arr[],int size)
{
    int count=2,maxcount=2;
    int diff=arr[1]-arr[0];
    for (int i = 2; i < size; i++)
    {
        if(diff==arr[i]-arr[i-1])
        {
            count++;
            // cout<<count<<endl;
            maxcount=Max(count,maxcount);
        }
        else
        {
            maxcount=Max(count,maxcount);
            count=2;
            // cout<<count<<endl;
        }
        diff=arr[i]-arr[i-1];
    }
    return maxcount;
    
}

int main()
{
    int a[]={1,0,5,5,5,5,5,4,6,7,8,9,10,11,12,13};
    int size=sizeof(a)/4;
    // maxAP(a,size);
    cout<<maxAP(a,size);
}