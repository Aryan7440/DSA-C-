#include "binary_tree.h"
#include <queue>
#include <bits/stdc++.h>

// int preindex = 0;
// int search(int arr[], int start, int end, int key)
// {
//     for (int i = start; i <= end; i++)
//     {
//         if (arr[i] == key)
//             return i;
//     }
// }

// Node *cons(int pre[], int in[], int start, int end)
// {
//     static int ind = 0;

//     if (start > end)
//         return NULL;
//     Node *root = new Node(pre[ind++]);
//     if (start == end)
//         return root;
//     int index = search(in, start, end, root->element);
//     root->left = cons(pre, in, start, index - 1);
//     root->right = cons(pre, in, index + 1, end);
//     return root;
// }

// int search(int element, vector<int> inorder, int start, int stop)
// {
//     for (int i = start; i <= stop; i++)
//     {
//         if (inorder[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Node *build(vector<int> inorder, vector<int> preorder, int start, int stop, int &preindex)
// {
//     // static int preindex = 0;

//     if (start > stop)
//         return NULL;
//     Node *temp = new Node(preorder[preindex++]);
//     if (start == stop)
//         return temp;
//     // preindex=preindex+1;
//     int index = search(temp->val, inorder, start, stop);
//     temp->left = build(inorder, preorder, start, index - 1, preindex);
//     temp->right = build(inorder, preorder, index + 1, stop, preindex);
//     return temp;
// }

// Node *buildtree(vector<int> inorder, vector<int> preorder)
// {
//     int preindex = 0;
//     Node *ans = build(inorder, preorder, 0, inorder.size() - 1, preindex);
//     return ans;
// }

Node *build(vector<int> &ino, vector<int> &pre, int start, int stop, int &pre_index, unordered_map<int, int> &mp)
{
    if (start > stop)
        return NULL;
    Node *res = new Node(pre[pre_index++]);
    // if(start==stop)return res;
    res->left = build(ino, pre, start, mp[res->val] - 1, pre_index, mp);
    res->right = build(ino, pre, mp[res->val] + 1, stop, pre_index, mp);
    return res;
}

Node *build_tree(vector<int> &ino, vector<int> &pre)
{
    int pre_index = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < ino.size(); i++)
    {
        mp[ino[i]] = i;
    }
    Node *res = build(ino, pre, 0, pre.size() - 1, pre_index, mp);
    return res;
}

int main()
{
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->right = new Node(6);
    // root->left->left = new Node(1);
    // root->left->left->left = new Node(0);
    // root->left->right = new Node(3);
    // root->right->left = new Node(5);
    // root->right->right = new Node(7);
    // inorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // levelorder(root);
    // cout << endl;

    // int in[] = {1, 2, 3, 4, 5, 6, 7};
    // int pre[] = {4, 2, 1, 3, 6, 5, 7};

    vector<int> ino = {1, 2, 3, 4, 5, 6, 7};
    vector<int> pro = {4, 2, 1, 3, 6, 5, 7};
    // Node *root3 = cons(pre, in, 0, 6);
    // levelorder(root3);
    // qlevel(root3);

    // Node *root2 = build(ino, pro, 0, ino.size() - 1);
    // Node *root2 = buildtree(ino, pro);
    // qlevel(root2);
    // printBT(root2);
    // levelorder(root2);

    // post=1,3,2,5,7,6,4

    Node *root = build_tree(ino, pro);
    printBT(root);
    // qlevel(root);
}