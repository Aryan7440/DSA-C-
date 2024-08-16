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

int util(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + min(l, r);
}
int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return util(root);
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(5);
    root->right->right->right->right=new TreeNode(6);
    cout<<minDepth(root);
}