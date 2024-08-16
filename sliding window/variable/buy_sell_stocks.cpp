#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int l = 0, r = 1;
    int p = 0;
    int tp = 0;
    while (r < prices.size())
    {
        int temp = prices[r] - prices[l];
        if (temp > p)
        {
            tp = tp - p+temp;
            p = temp;
        }
        else
        {
            p = 0;
            l = r;
        }
        
        r++;
    }
    return tp;
}
int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    // vector<int> prices={7,1,5,3,6,4};
    cout << maxProfit(prices);
}