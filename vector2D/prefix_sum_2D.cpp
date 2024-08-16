#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> pre;
void calculate_prefix_sum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    pre.resize(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }
}

long long query(int x1, int y1, int x2, int y2)
{
    int X2 = max(x1, x2) + 1;
    int X1 = min(x1, x2) + 1;
    int Y2 = max(y1, y2) + 1;
    int Y1 = min(y1, y2) + 1;

    return pre[X2][Y2] - pre[X2][Y1 - 1] - pre[X1 - 1][Y2] + pre[X1 - 1][Y1 - 1];
}
void printMatrix(vector<vector<long long>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << std::setw(10);
            cout << pre[i][j] << "   ";
        }
        cout << "\n";
    }
}
int main()
{
    // int n=6,m=8;
    // vector<vector<int>>matrix(n,vector<int>(m));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cin>>matrix[i][j];
    //     }
    // }
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    calculate_prefix_sum(matrix);
    printMatrix(pre);
}