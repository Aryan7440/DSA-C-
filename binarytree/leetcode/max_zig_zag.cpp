#include <bits/stdc++.h>
#include "binary_tree.h"
using namespace std;

int ans = 0;
void util(Node *root, int flag, int len)
{
    ans = max(ans, len);
    if (root == NULL)
        return;
    if (flag == 1)
    {
        util(root->right, 0, len + 1);
        util(root->left, 1, 1);
    }
    else
    {
        util(root->left, 1, len + 1);
        util(root->right, 0, 1);
    }

    // return l;
}
int longestZigZag(Node *root)
{
    // int ans=0;
    util(root->left, 1, 1);
    util(root->right, 0, 1);
    return ans;
}
int main()
{
    Node* n = new Node(1);
    n->right = new Node(1);
    n->right->left = new Node(1);
    n->right->right = new Node(1);
    n->right->right->right = new Node(1);
    n->right->right->left = new Node(1);
    n->right->right->left->right = new Node(1);
    n->right->right->left->right->right = new Node(1);
    // printBT(n);
    cout<<longestZigZag(n);

}