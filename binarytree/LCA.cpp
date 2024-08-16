#include <iostream>
#include "binary_tree.h"
using namespace std;

Node *LCA(Node *root, Node *first, Node *second)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root == first || root == second)
    {
        return root;
    }
    Node *left = LCA(root->left, first, second);
    Node *right = LCA(root->right, first, second);
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    return root;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* common=LCA(root,root->left->left,root->right->right);
    cout<<"Lowest common ancestor of 1 and 7 is: "<<common->val<<endl;
}