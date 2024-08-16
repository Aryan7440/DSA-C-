#include <bits/stdc++.h>
using namespace std;
int powersOf10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int x[] = {0, 1, 2, 3, 4, 5, 1, 2, 4, 5, 7, 8};
int y[] = {3, 4, 5, 6, 7, 8, 0, 1, 3, 4, 6, 7};
int swapD(int num, int i, int j)
{
    int digit_i = (num / powersOf10[8 - i]) % 10;
    int digit_j = (num / powersOf10[8 - j]) % 10;

    num = num - digit_i * powersOf10[8 - i] + digit_j * powersOf10[8 - i];
    num = num - digit_j * powersOf10[8 - j] + digit_i * powersOf10[8 - j];

    return num;
}
int shortestPath(int start, int target)
{
    queue<int> q;
    unordered_set<int> visited;
    int steps = 0;
    q.push(start);
    visited.insert(start);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int cur = q.front();
            q.pop();
            if (cur == target)
                return steps;
            for (int i = 0; i < 12; i++)
            {
                int next = swapD(cur, x[i], y[i]);
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        ++steps;
    }
    return -1;
}
int convertGridToNum(vector<vector<int>> &grid)
{
    int num = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            num = num * 10 + grid[i][j];
        }
    }
    return num;
}
int main()
{
    int start = 0, target;
    string st;
    for (int i = 0; i < 9; i++)
    {
        int t;
        cin >> t;
        start = start * 10 + t;
    }
    target = 123456789;
    int result = shortestPath(start, target);
    cout << result << endl;

    return 0;
}