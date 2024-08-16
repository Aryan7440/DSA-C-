#include"binary_tree.h"
#include<bits/stdc++.h>

void left_view(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(i==0)cout<<temp->val<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    cout<<endl;
    
}
void right_view(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(i==n-1)cout<<temp->val<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    cout<<endl;
    
}

void Lutil(Node* root,int level,vector<int> &ds)
{
    if(root)
    {
        if(level==ds.size())ds.push_back(root->val);
        Lutil(root->left,level+1,ds);
        Lutil(root->right,level+1,ds);
    }
}
void rec_leftView(Node *root)
{
    vector<int> ds;
    Lutil(root,0,ds);
    for (int i = 0; i < ds.size(); i++)
    {
        cout<<ds[i]<<" ";
    }
    cout<<endl;
    
}
void Rutil(Node* root,int level,vector<int> &ds)//O(h)
{
    if(root)
    {
        if(level==ds.size())ds.push_back(root->val);
        Rutil(root->right,level+1,ds);
        Rutil(root->left,level+1,ds);
    }
}
void rec_rightView(Node *root)
{
    vector<int> ds;
    Rutil(root,0,ds);
    for (int i = 0; i < ds.size(); i++)
    {
        cout<<ds[i]<<" ";
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
    // bottom_view(root);
    left_view(root);
    right_view(root);
    rec_leftView(root);
    rec_rightView(root);
}