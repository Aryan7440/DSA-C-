#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet
{
public:
    int s;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> mp;
    SmallestInfiniteSet()
    {
        s = 1;
    }

    int popSmallest()
    {
        if (!pq.empty() && s > pq.top())
        {
            int n = pq.top();
            pq.pop();
            if (n <= 1000)
                mp.insert(n);
            return n;
        }
        s++;
        if (s - 1 <= 1000)
            mp.insert(s - 1);
        return s - 1;
    }

    void addBack(int num)
    {
        if(num>=s)return;
        if (mp.find(num) == mp.end())
            return;
        mp.insert(num);
        pq.push(num);
    }
};
int main()
{
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
    smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
    smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
    smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
    smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
    smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                       // is the smallest number, and remove it from the set.
    smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
    smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
}