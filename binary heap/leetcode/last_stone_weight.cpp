#include <bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    priority_queue<int> pq;
    for (auto i : stones)
        pq.push(i);
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if (a == b)
            continue;
        else
        {
            pq.push(a - b);
        }
    }
    if(pq.empty())return 0;
    return pq.top();
}
int main()
{
    vector<int> stones={2,2};
    // vector<int> stones={2,7,4,1,8,1};
    cout<<lastStoneWeight(stones);
}