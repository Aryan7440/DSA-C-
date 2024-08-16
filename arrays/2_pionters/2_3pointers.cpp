#include <bits/stdc++.h>
using namespace std;

int peak_len(vector<int> arr)
{
    int count=0;
    int mcount=INT_MIN;
    for (int i = 1; i < arr.size()-1; i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            count=1;
            int j=i;
            while(j>0 && arr[j]>arr[j-1])
            {
                count++;
                j--;
            }
            while (i<arr.size()-1 && arr[i]>arr[i+1])
            {
                count++;
                i++;
            } 
        }
        mcount=max(count,mcount);
    }
    return mcount;
    
}

int main()
{
    vector<int> v={2,4,1,5,4,3,2,1};
    cout<<peak_len(v);
}

// 2 4 1 5 4 3 2 1