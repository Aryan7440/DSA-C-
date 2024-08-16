#include <vector>
#include <iostream>
#include <string>
using namespace std;

void output(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << "   ";
        }
        cout << endl;
    }
}

void transpose(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v[0].size(); j++)
        {
            int temp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = temp;
        }
    }
}

void rotate_perpendicular(vector<vector<int>> &v)
{

    //reverse rowwise
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size()/2; j++)
        {
            int temp=v[i][j];
            v[i][j]=v[i][v[0].size()-j-1];
            v[i][v[0].size()-j-1]=temp;
        }
        
    }
    //transpose
    transpose(v);
    
}

int main()
{
    vector<vector<int>> v1 = {{1, 2, 3, 11}, {4, 5, 6, 12}, {7, 8, 9, 13}, {21, 22, 23, 24}};
    output(v1);
    // transpose(v1);
    rotate_perpendicular(v1);
    output(v1);
}