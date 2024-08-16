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
TreeNode *util(string traversal, int l, int r)
{
    int n = traversal.size();
    if (l > r)
        return NULL;
    int st = l;
    while (l <= r && traversal[l] != '-')
        l++;
    string str = traversal.substr(st, l - st);

    TreeNode *root = new TreeNode(stoi(str));
    if (l >= r)
        return root;

    int count = 0;
    st = l;
    while (l <= r && traversal[l++] == '-')
        count++; // left ka begining
    int s = l, ep = l;
    // l=l-1;

    while (ep <= r)
    {
        s = ep;
        while (ep <= r && traversal[ep] == '-')
            ep++;
        if (ep - s == count)
            break;
        while (ep <= r && traversal[ep] != '-')
            ep++;
    }
    if (ep > r)
        s = r + 1;
    // else
    // {
    //     s--;
    //     while (traversal[s] != '-')
    //         s--;
    // }
    root->left = util(traversal, l - 1, s - 1);
    root->right = util(traversal, ep, r);
    return root;
}
TreeNode *recoverFromPreorder(string traversal)
{
    int n = traversal.size();
    return util(traversal, 0, n - 1);
}
void preorder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    string traversal = "1-401--349---90--88";
    // string traversal = "1-2--3---4-5--6---7";
    // string traversal = "1-2--3--4-5--6--7";
    TreeNode *root = recoverFromPreorder(traversal);
    preorder(root);
}