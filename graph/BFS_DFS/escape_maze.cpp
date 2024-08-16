#include <bits/stdc++.h>
using namespace std;
struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};
bool util(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
{
    queue<pair<int, int>> q;
    unordered_set<pair<int, int>, pair_hash> mp;
    unordered_set<pair<int, int>, pair_hash> vis;
    int mb = blocked.size() * blocked.size() / 2;
    for (auto i : blocked)
    {
        mp.insert({i[0], i[1]});
    }
    vis.insert({source[0], source[1]});
    q.push({source[0], source[1]});

    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    int count = blocked.size();

    while (!q.empty())
    {
        auto temp = q.front();
        int x = temp.first;
        int y = temp.second;
        q.pop();
        count++;
        if (count >= mb)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int dx = x + di[i];
            int dy = y + dj[i];
            if (dx >= 0 && dx < 1e6 && dy >= 0 && dy < 1e6 && mp.find({dx, dy}) == mp.end() && vis.find({dx, dy}) == vis.end())
            {
                if (dx == target[0] && dy == target[1])
                    return true;
                q.push({dx, dy});
                vis.insert({dx, dy});
            }
        }
    }
    return false;
}

bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
{
    return util(blocked,source,target) && util(blocked,target,source) ;
}
int main()
{
    vector<vector<int>> blocked = {{10, 9}, {9, 10}, {10, 11}, {11, 10}};
    vector<int> source = {0, 0};
    vector<int> target = {10, 10};
    cout << isEscapePossible(blocked, source, target);
}
