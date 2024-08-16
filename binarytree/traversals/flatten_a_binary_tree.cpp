#include "binary_tree.h"
#include <bits/stdc++.h>
void flatten(Node *root, Node *&prev)
{
    if (root == NULL)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

void flatten_stack(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
        if (!s.empty())
        {
            curr->right = s.top();
        }
        curr->left = NULL;
    }
    return;
}

void morris_flatten(Node *root)
{
    if (root == NULL)
        return;
    Node *curr = root;
    while(curr!=NULL)
    {
        if(curr->left!=NULL)
        {
            Node* prev=curr->left;
            while(prev->right)
            {
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    return;
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
    // Node* prev=NULL;
    // flatten(root,prev);


    // flatten_stack(root);

    morris_flatten(root);

    printBT(root);
}