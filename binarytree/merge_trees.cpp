#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        int l = root1 == NULL ? 0 : root1->val;
        int r = root2 == NULL ? 0 : root2->val;
        TreeNode *l1 = (root1 == NULL) ? NULL : root1->left;
        TreeNode *r1 = (root1 == NULL) ? NULL : root1->right;
        TreeNode *l2 = (root2 == NULL) ? NULL : root2->left;
        TreeNode *r2 = (root2 == NULL) ? NULL : root2->right;

        if (!root1 && !root2)
            return NULL;
        TreeNode *ans = new TreeNode(l + r);
        ans->left = mergeTrees(l1, l2);
        ans->right = mergeTrees(r1, r2);
        return ans;
    }
};