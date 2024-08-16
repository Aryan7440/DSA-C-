#include <bits/stdc++.h>
using namespace std;
bool hours(vector<int> piles, int h, int k)
{
    int count = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] <= k)
        {
            count++;
            continue;
        }
        if (piles[i] % k != 0)
            count = count + (piles[i] / k) + 1;
        else
            count = count + (piles[i] / k);
    }
    if (count > h)
    {
        return false;
    }
    return true;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 0, stop = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        stop = max(stop, piles[i]);
    }
    int mid = start + (stop - start) / 2;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (hours(piles, h, mid))
        {
            stop = mid - 1;
        }
        else
            start = mid + 1;
    }
    return start;
}
int main()
{
    vector<int> arr = {312884470};
    
// int a=312884470;
// int b=968709470;
// cout<<a%(b/2);
    cout << minEatingSpeed(arr, 968709470);
}