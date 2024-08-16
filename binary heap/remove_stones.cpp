#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq(piles.begin(), piles.end());
    for (int i = 0; i < k; i++)
    {
        int temp = ceil(pq.top() / 2.0);
        pq.pop();
        pq.push(temp);
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> piles = {5,4,9};
    int k = 2;
    cout<<minStoneSum(piles,k);
}