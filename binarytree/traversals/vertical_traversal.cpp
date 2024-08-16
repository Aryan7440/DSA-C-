#include "binary_tree.h"
#include <bits/stdc++.h>

void vertical(Node *root, map<int, vector<int>> &ds, int x)
{
    if (root == NULL)
        return;
    ds[x].push_back(root->val);
    vertical(root->left, ds, x - 1);

    vertical(root->right, ds, x + 1);
}

vector<vector<int>> printvertical(Node *root)
{
    map<int, vector<int>> ds;
    vertical(root, ds, 0);

    vector<vector<int>> ans;

    for (auto x : ds)
    {
        // sort(x.second.begin(),x.second.end());
        ans.push_back(x.second);
    }
    return ans;
}

void UTIL(Node *root, int x, int y, map<int, map<int, multiset<int>>> &mp)
{
    if (root == NULL)
        return;
    mp[x][y].insert(root->val);
    UTIL(root->left, x - 1, y + 1, mp);
    UTIL(root->right, x + 1, y + 1, mp);
}
void vertical_order_traversal(Node *root)
{
    map<int, map<int, multiset<int>>> mp;
    vector<vector<int>> ans;
    UTIL(root, 0, 0, mp);
    // vector<vector<int>> ans;
    for (auto p : mp)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int  j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->left->left = new Node(0);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    // root->right->right->right = new Node(9);
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->right = new Node(6);
    // root->left->left = new Node(1);
    // root->left->left->left = new Node(0);
    // root->left->right = new Node(3);
    // root->right->left = new Node(5);
    // root->right->right = new Node(7);
    // root->right->right->right = new Node(9);

    printBT(root);
    cout << endl;
    qlevel(root);
    cout << endl;

    // vector<vector<int>> ans;
    // ans = printvertical(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vertical_order_traversal(root);

    return 0;
}