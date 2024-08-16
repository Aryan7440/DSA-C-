#include <bits/stdc++.h>
using namespace std;
int shortestPathAllKeys(vector<string> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<vector<int>>> s(64,vector<vector<int>>(n,vector<int>(m,0)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]=='@')
                {
                    q.push({0, {i, j}});
                    s[0][i][j]=1;;
                }
                if (grid[i][j] >= 'A' && grid[i][j] <= 'F')
                    count++;
            }
        }
        int target = ((1 << count) - 1);
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int ans = 0;
        while (!q.empty())
        {
            int l = q.size();
            ans++;
            for (int i = 0; i < l; i++)
            {
                auto temp = q.front();
                q.pop();

                int bit = temp.first;
                int x = temp.second.first;
                int y = temp.second.second;

                for (int j = 0; j < 4; j++)
                {
                    int X = x + dx[j];
                    int Y = y + dy[j];
                    if (X >= 0 && X < n && Y >= 0 && Y < m && grid[X][Y] != '#')
                    {
                        if (grid[X][Y] >= 'A' && grid[X][Y] <= 'Z' && (((1 << (grid[X][Y] - 'A')) & bit) == 0))
                            continue;
                        int t = bit;
                        if (grid[X][Y] >= 'a' && grid[X][Y] <= 'z')
                            t = ((1 << (grid[X][Y] - 'a')) | bit);
                        if (t == target)
                            return ans;
                        if (s[t][X][Y]==0)
                        {
                            q.push({t, {X, Y}});
                            s[t][X][Y]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
int main()
{
    // vector<string>grid = {"@Aa"};
    vector<string>grid = {"@.a..",
    "###.#",
    "b.A.B"};
    cout<<shortestPathAllKeys(grid);
}