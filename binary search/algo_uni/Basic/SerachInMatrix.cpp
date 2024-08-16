#include <bits/stdc++.h>
using namespace std;
pair<int, int> grid_search(vector<vector<int>> &matrix, int x)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int l = -1, r = m * n;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] < x)
            l = mid;
        else
            r = mid;
    }
    return {r / m, r % m};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int query;
        cin >> query;
        pair<int, int> p = grid_search(matrix, query);
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}