#include <bits/stdc++.h>
using namespace std;

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    set<pair<int, int>> set;
    set.insert({0, 0});
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto p = q.front();
        int j1 = p.first;
        int j2 = p.second;
        q.pop();
        if ((j1 + j2) == targetCapacity)
            return true;
        if (j1 > 0 && set.find({0, j2}) == set.end())
        {
            q.push({0, j2});
            set.insert({0, j2});
        }
        if (j2 > 0 && set.find({j1, 0}) == set.end())
        {
            q.push({j1, 0});
            set.insert({j1, 0});
        }
        if (j1 < jug1Capacity && set.find({jug1Capacity, j2}) == set.end())
        {
            q.push({jug1Capacity, j2});
            set.insert({jug1Capacity, j2});
        }
        if (j2 < jug2Capacity && set.find({j1, jug2Capacity}) == set.end())
        {
            q.push({j1, jug2Capacity});
            set.insert({0, j2});
        }
        int rem1 = jug1Capacity - j1;
        int rem2 = jug2Capacity - j2;
        if (j1 > 0)
        {
            int j2i = (j2 + j1) % jug2Capacity == 0 ? jug2Capacity : (j2 + j1) % jug2Capacity;
            int j1i = j1 - rem2 < 0 ? 0 : j1 - rem2;
            if (set.find({j1i, j2i}) == set.end())
            {
                q.push({j1i, j2i});
                set.insert({j1i, j2i});
            }
        }
        if (j2 > 0)
        {
            int j1i = (j2 + j1) % jug1Capacity == 0 ? jug1Capacity : (j2 + j1) % jug1Capacity;
            int j2i = j2 - rem1 < 0 ? 0 : j2 - rem1;
            if (set.find({j1i, j2i}) == set.end())
            {
                q.push({j1i, j2i});
                set.insert({j1i, j2i});
            }
        }
    }
    return false;
}

int main()
{
    cout<<canMeasureWater(3,5,4);
}