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
int time_to_burn(Node *root, Node *target)
{
    unordered_map<Node *, Node *> parents = map_parents(root);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            // cout<<curr->val<<" ";
            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left]=true;
                flag = true;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right]=true;
                flag = true;
            }
            if (parents[curr] && !visited[parents[curr]])
            {
                q.push(parents[curr]);
                visited[parents[curr]]=true;
                flag = true;
            }
        }
        // cout<<endl;
        if (flag)
            time++;
    }
    return time;
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
    root->right->right->right = new Node(9);

    printBT(root);
    cout << endl;

    Node *target = find_target(root, 2);
    printBT(target);

    cout<<time_to_burn(root, target);
}
