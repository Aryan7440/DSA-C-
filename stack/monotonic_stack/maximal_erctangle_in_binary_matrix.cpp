#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximal-rectangle/description/
int max_area_histogram(vector<vector<int>> &mat, int ind) // one pass most optimal
{
    stack<int> st;
    int n = mat[ind].size();
    int area = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || mat[ind][st.top()] >= mat[ind][i]))
        {
            int h = mat[ind][st.top()];
            st.pop();
            int r = i;
            int l = (st.empty()) ? -1 : st.top();
            area = max(area, h * (r - l - 1));
        }
        st.push(i);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
                count++;
            else
                count = 0;
            mat[i][j] = count;
        }
    }
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        area = max(area, max_area_histogram(mat, i));
    }
    return area;
}
int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix);
}