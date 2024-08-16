#include <iostream>
#include <vector>
using namespace std;

// vector<vector<int>> generate(int numRows)
// {
//     vector<vector<int>> ans;
//     vector<int> temp;
//     temp.push_back(1);
//     ans.push_back(temp);
//     // ans[0].push_back(1);
//     for (int i = 1; i < numRows; i++)
//     {
//         vector<int> temp;
//         temp.push_back(1);
//         //ans[i].push_back(1); // ans[i][0]=1;
//         for (int j = 1; j < ans[i - 1].size(); j++)
//         {
//             temp.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
//             //ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
//         }
//         temp.push_back(1);
//         ans.push_back(temp);
//         //ans[i].push_back(1); // arr[i][j]=1;
//     }
//     return ans;
// }
void display(vector<vector<int>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i)
                temp.push_back(1);
            else
                temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<int>> a = generate(5);
    display(a);
}