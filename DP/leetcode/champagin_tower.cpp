#include <bits/stdc++.h>
using namespace std;
void util(double poured, vector<vector<double>> &tower, int i, int j)
{
    if (i == 100)
        return;
    if (poured <= 0)
        return;
    if (tower[i][j] == 0)
    {
        if (poured >= 1)
        {
            tower[i][j] = 1;
            poured = poured - 1;
            ;
            util((double)poured / 2, tower, i + 1, j);
            util((double)poured / 2, tower, i + 1, j + 1);
        }
        else
            tower[i][j] = poured;
    }
    else
    {
        if (poured + tower[i][j] >= 1)
        {
            poured = poured - tower[i][j];
            tower[i][j] = 1;
            // poured--;
            util((double)poured / 2, tower, i + 1, j);
            util((double)poured / 2, tower, i + 1, j + 1);
        }
        else
            tower[i][j] += poured;
    }
}
double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> tower(100, vector<double>(100, 0));
    util(poured, tower, 0, 0);
    return tower[query_row][query_glass];
}
int main()
{
    cout << champagneTower(2, 1, 1);
}