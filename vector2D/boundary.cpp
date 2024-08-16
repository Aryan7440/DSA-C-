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
            cout <<setw(4)<< v[i][j] << "   ";
        }
        cout << endl;
    }
}

void boundary(vector<vector<int>> v)
{
    int m = v.size();
    int n = v[0].size();
    int i = 0, j = 0;
    for (; j < n; j++)
    {
        cout << v[i][j] << " ";
    }
    i++;
    j--;
    for (; i < m; i++)
    {
        cout << v[i][j] << " ";
    }
    i--;
    j--;
    for (; j >= 0; j--)
    {
        cout << v[i][j] << " ";
    }
    i--;
    j++;
    for (; i != 0; i--)
    {
        cout << v[i][j] << " ";
    }
}

int main()
{
    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);
    boundary(v1);
}