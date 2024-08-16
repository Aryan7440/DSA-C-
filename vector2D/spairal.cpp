#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void input(vector<vector<int>> &v, int row, int column)
{
    for (int j = 0; j < row; j++)
    {
        vector<int> temp;
        for (int i = 0; i < column; i++)
        {

            int t;
            cin >> t;
            temp.push_back(t);
        }
        v.push_back(temp);
    }
}

void output(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << setw(4) << v[i][j] << "   ";
        }
        cout << endl;
    }
}

void spiral(vector<vector<int>> v)
{
    int l = 0;
    int b = v.size() - 1;
    int t = 0;
    int r = v[0].size() - 1;

    while (l <= r && t <= b)
    {
        for (int i = l; i <= r; i++)
        {
            cout << v[t][i] << " ";
        }
        t++;
        for (int i = t; i <= b; i++)
        {
            cout << v[i][r] << " ";
        }
        r--;
        if (l <= r)
        {
            for (int i = r; i >= l; i--)
            {
                cout << v[b][i] << " ";
            }
            b--;
        }

        if (b >= t)
        {
            for (int i = b; i >= t; i--)
            {
                cout << v[i][l] << " ";
            }
            l++;
        }
    }
    cout << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rows = 0, cols = 0;
    int n = matrix.size(), m = matrix[0].size();
    int rowe = n - 1, cole = m - 1;
    int d[] = {1, 2, 3, 4};
    int di = 0;
    vector<int> ans;
    int count = 0;
    while (count < n * m)
    {
        if (d[di] == 1)
        {
            for (int i = cols; i <= cole; i++)
            {
                ans.push_back(matrix[rows][i]);
                count++;
            }
            rows++;
        }
        if (d[di] == 2)
        {
            for (int i = rows; i <= rowe; i++)
            {
                ans.push_back(matrix[i][cole]);
                count++;
            }
            cole--;
        }
        if (d[di] == 3)
        {
            for (int i = cole; i >= cols; i--)
            {
                ans.push_back(matrix[rowe][i]);
                count++;
            }
            rowe--;
        }
        if (d[di] == 4)
        {
            for (int i = rowe; i >= rows; i--)
            {
                ans.push_back(matrix[i][cols]);
                count++;
            }
            cols++;
        }
        di = (di + 1) % 4;
    }
    return ans;
}

void inv_spiral(vector<vector<int>> v)
{
    int rows = 0, cols = 0;
    int rowe = v.size() - 1, cole = v[0].size() - 1;
    while (rows <= rowe && cols <= cole)
    {

        for (int i = rows; i <= rowe; i++)
        {
            cout << v[i][cols] << " ";
        }
        cols++;

        for (int i = cols; i <= cole; i++)
        {
            cout << v[rowe][i] << " ";
        }
        rowe--;
        if (rows < rowe)
        {
            for (int i = rowe; i >= rows; i--)
            {
                cout << v[i][cole] << " ";
            }
            cole--;
        }
        if (cols < cole)
        {
            for (int i = cole; i >= cols; i--)
            {
                cout << v[rows][i] << " ";
            }
            rows++;
        }
    }
    cout << endl;
}

int main()
{
    // vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}};
    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);

    spiral(v1);
    inv_spiral(v1);
    // for (int i = 0; i < spiralOrder(v1).size(); i++)
    // {
    //     cout << spiralOrder(v1)[i] << " ";
    // }
    // cout << endl;
}
