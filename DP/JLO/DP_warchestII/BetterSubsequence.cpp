#include <bits/stdc++.h>
using namespace std;
int sub(vector<vector<int>> &mat, vector<int> &p, int node, int ind)
{
    if (ind == p.size())
        return 0;
    int take = 0;
    if (node == p[ind])
    {
        for (int i = 1; i <= mat.size(); i++)
        {
            if (mat[node][i] == 1)
            {
                take = max(take, 1 + sub(mat, p, i, ind + 1));
            }
        }
    }
    int not_take = sub(mat, p, node, ind + 1);
    return max(take, not_take);
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, sub(mat, p, i, 0));
    }

    cout << ans;
    return 0;
}