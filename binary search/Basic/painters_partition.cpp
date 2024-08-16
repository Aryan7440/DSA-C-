#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> boards, int k, int area)
{
    int total = 0;
    int painters = 1;
    for (int i = 0; i < boards.size(); i++)
    {
        total += boards[i];
        if (total > area)
        {
            total = boards[i];
            painters++;
            if (painters > k)
                return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int start=0,stop=10000;
    for(int i=0;i<boards.size();i++)
    {
        start=max(start,boards[i]);
    }
    int mid=start+(stop-start)/2;
    int ans;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (isvalid(boards, k, mid))
        {

            stop = mid - 1;
            
        }
        else
        {

            start = mid + 1;
            ans = mid;
        }
    }
    return start;
}
int main()
{
    vector<int> v = {48, 90};
    cout << findLargestMinDistance(v, 2);
}