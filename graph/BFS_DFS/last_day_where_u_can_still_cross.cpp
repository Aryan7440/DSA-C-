#include <bits/stdc++.h>
using namespace std;
bool check(int day, int row, int col, vector<vector<int>> &cells)
{
    unordered_map<int, unordered_map<int, int>> mp;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i <= day; i++)
    {
        mp[cells[i][0]][cells[i][1]] = 1;
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= col; i++)
    {
        if (mp[1][i] == 1)
            continue;
        q.push({1, i});
    }
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (X >= 1 && Y >= 1 && X <= row && Y <= col && mp[X][Y] != 1)
            {
                if (X == row)
                    return true;
                q.push({X, Y});
                mp[X][Y] = 1;
            }
        }
    }
    return false;
}

int latestDayToCross(int row, int col, vector<vector<int>> &cells)
{
    int l = 0, n = cells.size(), r = n-1, mid = l + (r - l) / 2;
    int ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(mid, row, col, cells))
        {
            ans = mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans+1;
}
int main()
{
    vector<vector<int>>cells = {{1,1},{1,2},{2,1},{2,2}};
    cout<<latestDayToCross(2,2,cells);
}