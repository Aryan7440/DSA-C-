#include "binary_tree.h"
#include <bits/stdc++.h>

void inorder_morris(Node *root)
{
    Node *curr = root;
    if (root == NULL)
        return;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            if (prev->right == curr)
            {
                prev->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}
void preorder_morris(Node *root)
{
    Node *curr = root;
    if (root == NULL)
        return;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                cout << curr->val << " ";
                curr = curr->left;
            }
            if (prev->right == curr)
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout<<endl;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->left->right = new Node(9);

    printBT(root);
    cout << endl;

    inorder_morris(root);
    preorder_morris(root);
}