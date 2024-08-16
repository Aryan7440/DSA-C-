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
int flip_bits(int path, int i)
{
    int bit = (1 << i);
    if ((path & bit) != 0)
        path = path & (~bit);
    else
        path = path | bit;
    return path;
}
int dfs(TreeNode *root, int path)
{
    if (!root->left && !root->right)
    {
        path = flip_bits(path, root->val - 1);
        int set_bits = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((1 << i) & path)
                set_bits++;
            if (set_bits > 1)
                return 0;
        }
        return 1;
    }
    int l = (root->left != NULL) ? dfs(root->left, flip_bits(path, root->val - 1)) : 0;
    int r = (root->right != NULL) ? dfs(root->right, flip_bits(path, root->val - 1)) : 0;
    return l + r;
}
int pseudoPalindromicPaths(TreeNode *root)
{
    return dfs(root, 0);
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    cout << pseudoPalindromicPaths(root);
}