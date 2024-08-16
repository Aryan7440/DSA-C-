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
void wave(vector<vector<int>> v)
{
    for (int j = 0; j < v[0].size(); j++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (j % 2 == 0)
            {
                cout << v[i][j] << " ";
            }
            else
            {
                cout << v[v.size() - i - 1][j] << " ";
            }
        }
    }
    cout << endl;
}

void inv_wave(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (i % 2 == 0)
            {
                cout << v[i][j] << " ";
            }
            else
            {
                cout << v[i][v[0].size() - 1 - j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{

    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);
    wave(v1);
    inv_wave(v1);
}