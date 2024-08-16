#include "binary_tree.h"
#include <bits/stdc++.h>

int left_node_chain(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr)
    {
        curr = curr->left;
        count++;
    }
    return count;
}
int right_node_chain(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr)
    {
        curr = curr->right;
        count++;
    }
    return count;
}
int count_nodes(Node *root)
{
    if (root == NULL)
        return 0;
    int l = left_node_chain(root);
    int r = right_node_chain(root);
    if (l == r)
    {
        return pow(2, l) - 1;  //1<<l ==pow(2,l)
    }
    return count_nodes(root->left) +count_nodes(root->right) +1;
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->left->left = new Node(0);
    root->left->left->right = new Node(8);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    // root->right->right->right = new Node(9);
    root->left->right->left = new Node(11);
    root->left->right->right = new Node(13);

    printBT(root);
    cout << endl;

    cout << count_nodes(root);
}