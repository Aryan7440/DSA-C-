#include "binary_tree.h"
#include <bits/stdc++.h>
using namespace std;

void UTIL(Node *root, vector<int> &ds)
{
    if (root == NULL)
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i] << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(root->val);
    UTIL(root->left, ds);
    UTIL(root->right, ds);
    ds.pop_back();
}
void root_to_leaf(Node *root)
{
    vector<int> ds;
    UTIL(root, ds);
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
    root->left->right->left->left->left = new Node(100);
    root->left->right->left->left->right->left = new Node(55);
    root->left->right->left->left->right->right = new Node(44);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(10);
    root->left->right->right->right->left = new Node(11);
    root->left->right->right->right->left->right = new Node(182);
    root->left->right->right->right->left->left = new Node(181);

    printBT(root);
    cout << endl;
    qlevel(root);
    cout << endl;
    // root_to_leaf(root);
}