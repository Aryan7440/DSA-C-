#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> price, int k, int mid)
{
    int count = 1;
    int prev = price[0];
    for (int i = 1; i < price.size(); i++)
    {
        if (price[i] - prev >= mid)
        {
            count++;
            prev = price[i];
            if (count >= k)
                return true;
        }
    }
    return false;
}
int maximumTastiness(vector<int> &price, int k)
{
    if (price.size() < k)
        return -1;
    sort(price.begin(), price.end());
    int l = 0;
    int r = 20;
    // int r = price[price.size() - 1];
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(price, k, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    vector<int> prices={13,5,1,8,21,2};
    cout<<maximumTastiness(prices,3);
}