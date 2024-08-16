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
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << setw(4) << v[i][j] << setw(4);
        }
        cout << endl;
    }
}

void zig_zag(vector<vector<int>> v)
{
    for (int i = 0; i < 2 * v[0].size() - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (i < v[0].size())
            {
                int j = 0;
                int k = i;
                while (k >= 0)
                {
                    cout << setw(4) << v[k][j] << " ";
                    k--;
                    j++;
                }
            }
            else
            {
                int k = v.size() - 1;
                int j = (i % v.size()) + 1;
                while (j < v.size())
                {
                    cout << setw(4) << v[k][j] << " ";
                    j++;
                    k--;
                }
            }
            cout << endl;
        }
        else
        {
            if (i < v[0].size())
            {
                int j = i;
                int k = 0;
                while (j >= 0)
                {
                    cout << setw(4) << v[k][j] << " ";
                    k++;
                    j--;
                }
            }
            else
            {
                int j = v.size() - 1;
                int k = (i % v.size()) + 1;
                while (k < v.size())
                {
                    cout << setw(4) << v[k][j] << " ";
                    k++;
                    j--;
                }
            }
            cout << endl;
        }
    }
}

int main()
{
    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);
    zig_zag(v1);
}