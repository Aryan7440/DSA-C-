#include "binary_tree.h"
#include <bits/stdc++.h>

unordered_map<Node *, Node *> map_parents(Node *root)
{
    unordered_map<Node *, Node *> mp;
    // mp[root] = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return mp;
}

Node *find_target(Node *root, int target)
{
    if (root->val == target)
        return root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->val == target)
            return temp;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return NULL;
}
void nodes_at_dist_k(Node* root,Node*target,int k)
{
    queue<Node*> q;
    q.push(target);
    unordered_map <Node*,bool> visited;
    unordered_map<Node*,Node*> parents=map_parents(root);
    visited[target]=true;
    int curr_level=0;
    while (!q.empty())
    {
        if(curr_level++==k)break;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(parents[temp]&& !visited[parents[temp]] )//&& !visited[parents[temp]]
            {
                q.push(parents[temp]);
                visited[parents[temp]]=true;
            }
        }
        // k--;
    }

    while (!q.empty())
    {
        cout<<q.front()->val<<" ";
        q.pop();
    }
    cout<<endl;  
}
int main()
{
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->right = new Node(6);
    // root->left->left = new Node(1);
    // root->left->left->left = new Node(0);
    // root->left->left->right = new Node(8);
    // root->left->right = new Node(3);
    // root->right->left = new Node(5);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(9);

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
   

    Node*target=find_target(root,4);
    printBT(target);

    nodes_at_dist_k(root,target,2);


    // unordered_map<int,bool> test;
    // cout<<!test[0];




}