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

int max_till_i(int arr[],int size,int i)
{
    // int max=INT16_MIN;
    int max=arr[0];
    for (int j = 0; j <= i; j++)
    {
        max=Max(max,arr[j]);
    }
    return max;
    
}

int main()
{
    int a[]={1,0,5,4,6,8};
    int size=sizeof(a)/4;
    for (int i = 0; i < size; i++)
    {
        cout<<max_till_i(a,size,i)<<endl;
    }
    

}