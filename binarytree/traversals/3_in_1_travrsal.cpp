#include "binary_tree.h"

void all_traversals(Node *root, vector<int> &in, vector<int> &pre, vector<int> &post)
{
    if (root == NULL)
        return;
    pre.push_back(root->val);
    all_traversals(root->left, in, pre, post);
    in.push_back(root->val);
    all_traversals(root->right, in, pre, post);
    post.push_back(root->val);
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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
    // root->right->right->right=new Node(23);
    // root->right->right->left = new Node(1);

    qlevel(root);
    cout << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;

    // vector<int> post;
    // vector<int> in;
    // vector<int> pre;
    // all_traversals(root, in, pre, post);
    // display(pre);
    // display(post);
    // display(in);

    printBT(root);
}