#include <bits/stdc++.h>
using namespace std;

void set_zero(vector<vector<int>> &mat)
{
    int col = 0;
    int row = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                if (j == 0)
                    col = 1;
                if (i == 0)
                    row = 1;
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < mat.size(); i++)
    {
        for (int j = 1; j < mat[i].size(); j++)
        {
            if (mat[i][0] == 0 || mat[0][j] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }

    if (row)
    {
        for (int i = 0; i < mat[0].size(); i++)
        {
            mat[0][i] = 0;
        }
    }
    if (col)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            mat[i][0] = 0;
        }
    }

    // return mat;
}

void display(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << "            ";
        }
        cout << endl;
    }
}

int main()
{
    // vector<vector<int>> mat={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // vector<vector<int>> mat = {{-4, -2147483648, 6, -7, 0},
    //                            {-8, 6, -8, -6, 0},
    //                            {2147483647, 2, -9, -6, -10}};
    // vector<vector<int>> mat={{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> mat={{1,1,1,1},{1,0,1,1},{1,1,0,0},{0,0,0,1}};
    vector<vector<int>> mat =
        {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};

    display(mat);
    set_zero(mat);
    display(mat);
}
