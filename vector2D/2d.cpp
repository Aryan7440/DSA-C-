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


template <class T>
void output(vector<vector<T>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << setw(4) << v[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v(3,vector<int>(5,1));
    vector<vector<bool>> v3(3,vector<bool>(5,false));
    vector<vector<char>> v2(4,vector<char>(4,'a'));
    vector<vector<string>> v4(3,vector<string>(3,"aryan"));
    output(v3);
    output(v);
    output(v2);
    output(v4);
    // input(v, 3, 5);

    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);
}
