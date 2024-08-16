#include "binary_tree.h"
#include <bits/stdc++.h>
using namespace std;

// int search(vector<int> arr, int x)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] == x)
//             return i;
//     }
//     return -1;
// }

// Node *build(vector<int> &post, vector<int> &in, int start, int stop, int &post_in)
// {
//     if (start > stop)
//         return NULL;
//     Node *temp = new Node(post[post_in--]);
//     if (start == stop)
//     {
//         return temp;
//     }

//     int index = search(in, temp->val);
//     temp->right = build(post, in, index + 1, stop, post_in);
//     temp->left = build(post, in, start, index - 1, post_in);
//     return temp;
// }

// Node *buildtree(vector<int> &post, vector<int> &in)
// {
//     int post_in = post.size() - 1;
//     Node *root = build(post, in, 0, post.size() - 1, post_in);
//     return root;
// }

Node *build(vector<int> &inorder, vector<int> &postorder, int start, int stop, int &post_index, unordered_map<int, int> &mp)
{
    if (start > stop)
        return NULL;
    Node *ans = new Node(postorder[post_index--]);
    ans->right = build(inorder, postorder, mp[ans->val] + 1, stop, post_index, mp);
    ans->left = build(inorder, postorder, start, mp[ans->val] - 1, post_index, mp);
    
    return ans;
}
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    int post_index = postorder.size() - 1;
    Node *res = build(inorder, postorder, 0, postorder.size() - 1, post_index, mp);
    return res;
}
int main()
{
    vector<int> ino = {1, 2, 3, 4, 5, 6, 7};
    vector<int> post = {1, 3, 2, 5, 7, 6, 4};
    Node *root = buildTree(ino, post);
    printBT(root);
}