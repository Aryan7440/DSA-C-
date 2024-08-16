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
// int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)//brute force
// {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int count = 0;
//     calculate_prefix_sum(matrix);
//     for (int x1 = 0; x1 < n; x1++)
//     {
//         for (int x2 = x1; x2 < n; x2++)
//         {
//             for (int y1 = 0; y1 < m; y1++)
//             {
//                 for (int y2 = y1; y2 < m; y2++)
//                 {
//                     long long sum = query(x1, y1, x2, y2);
//                     if (sum == target)
//                         count++;
//                 }
//             }
//         }
//     }
//     return count;
// }

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) // brute force
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    calculate_prefix_sum(matrix);
    int ans = 0;
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int x2 = x1; x2 < n; x2++)
        {
            unordered_map<long long, int> mp;
            mp[0] = 1;
            for (int y2 = 0; y2 < m; y2++)
            {
                long long sum = query(x1, 0, x2, y2);
                ans += mp[target - sum];
                mp[sum]++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    cout << numSubmatrixSumTarget(matrix, 3) << endl;
    printMatrix(pre);
}