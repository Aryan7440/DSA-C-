#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> bombs(k, vector<int>(3));
    for (int i = 0; i < k; i++)
    {
        cin >> bombs[i][0];
        cin >> bombs[i][1];
        cin >> bombs[i][2];
    }
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < k; i++)
    {
        int x = bombs[i][0] - 1;
        int y = bombs[i][1] - 1;
        int a = bombs[i][2];

        int top = max(0, x - a);
        int bot = min(n - 1, x + a);
        int rig = min(m - 1, y + a);
        int lef = max(0, y - a);

        for (int i = top; i <= bot; i++)
        {
            mat[i][lef] += 1;
            mat[i][rig + 1] -= 1;
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += mat[i][j];
            if (sum == 0)
                ans.push_back({i, j});
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }

    return 0;
}