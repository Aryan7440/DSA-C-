#include "binary_tree.h"
#include <bits/stdc++.h>

void children_sum(Node *&root)
{
    if (root == NULL)
        return;
    int c_sum = 0;
    if (root->left)
        c_sum += root->left->val;
    if (root->right)
        c_sum += root->right->val;

    if (c_sum <= root->val)
    {
        if (root->left)
            root->left->val = c_sum;
        if (root->right)
            root->right->val = c_sum;
    }
    else
    {
        root->val = c_sum;
    }
    children_sum(root->left);
    children_sum(root->right);

    int cs = 0;
    if (root->left)
        cs += root->left->val;
    if (root->right)
        cs += root->right->val;
    if (root->left || root->right)
        root->val = cs;
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(9);
    root->left->right->left->left->right = new Node(89);
    root->left->right->left->left->right->left = new Node(55);
    root->left->right->left->left->right->right = new Node(44);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(10);
    root->left->right->right->right->left = new Node(11);
    root->left->right->right->right->left->right = new Node(182);

    printBT(root);
    cout << endl;

    children_sum(root);
    printBT(root);
    cout << endl;
}