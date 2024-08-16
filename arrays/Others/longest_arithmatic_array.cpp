#include<bits/stdc++.h>
using namespace std;

int longest_arithmatic_subarray(vector<int> v)
{
    int i=0,j=1;
    int diff=v[j]-v[i];
    int len=0;
    while(j<v.size()-1)
    {   
        if(v[j+1]-v[j]==diff)
        {
            len=max(len,j-i+2);
            j++;
        }
        else
        {
            diff=v[j+1]-v[j];
            i=j;
            j++;
        }
    }
    return len;
}
int main()
{
    vector<int> v={5 ,5 ,4 ,5 ,5 ,5 ,4 ,5 ,6};
    // vector<int> v={10,7,4,6,8,10,11};
    cout<<longest_arithmatic_subarray(v);
}

