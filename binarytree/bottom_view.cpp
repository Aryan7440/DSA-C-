#include "binary_tree.h"
#include<bits/stdc++.h>

void util(Node* root,int x,map<int,int> &mp)
{
    if(root)
    {
        mp[x]=root->val;
        util(root->left,x-1,mp);
        util(root->right,x+1,mp);
    }
}

void bottom_view(Node* root)
{
    map<int,int> mp;
    util(root,0,mp);
    for(auto i:mp)
    {
        cout<<i.second<<" ";
    }
    cout<<endl;
}

int main()
{
    // root->right->right->right = new Node(9);
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);

    printBT(root);
    cout << endl;
    qlevel(root);
    cout << endl;
    bottom_view(root);
}