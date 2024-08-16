#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the amount "<<endl;
    int am;
    cin>>am;
    vector<int>A(7);
    A={100,50,20,10,5,2,1};
    for(int i=0;i<7;i++)
    {
        if(am/A[i]>0){
        cout<<A[i]<<"*"<<am/A[i]<<endl;
        am=am%A[i];
        }
    }
    return 0;   
}