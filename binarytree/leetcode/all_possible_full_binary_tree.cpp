#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode *> help(int n, unordered_map<int, vector<TreeNode *>> &dp)
{
    if (dp.find(n) != dp.end())
        return dp[n];
    vector<TreeNode *> res;
    for (int i = 1; i < n - 1; i = i + 2)
    {
        vector<TreeNode *> le = allPossibleFBT(i);
        vector<TreeNode *> ri = allPossibleFBT(n - i - 1);
        for (int l = 0; l < le.size(); l++)
        {
            for (int r = 0; r < ri.size(); r++)
            {
                TreeNode *temp = new TreeNode(0);
                temp->left = le[l];
                temp->right = ri[r];
                res.push_back(temp);
            }
        }
    }
    return dp[n] = res;
}
vector<TreeNode *> allPossibleFBT(int n)
{
    if (n % 2 == 0)
        return {};
    unordered_map<int, vector<TreeNode *>> dp;
    dp[1] = {new TreeNode(0)};
    // return help(n,dp);
    for (int i = 3; i <= n; i = i + 2)
    {
        for (int l = 1; l < i; l = l + 2)
        {
            int r = i - 1 - l;
            for (int le = 0; le < dp[l].size(); le++)
            {
                for (int ri = 0; ri < dp[r].size(); ri++)
                {
                    TreeNode *temp = new TreeNode(0);
                    temp->left = dp[l][le];
                    temp->right = dp[r][ri];
                    dp[i].push_back(temp);
                }
            }
        }
    }
    return dp[n];
}
int main()
{
    vector<TreeNode *> ans = allPossibleFBT(7);
    for (auto i : ans)
    {
        cout << "AGAG"
             << " ";
    }
}