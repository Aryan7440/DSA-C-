#include "binary_tree.h"

bool path(Node *root, vector<int> &path_, int x)
{
    if (root == NULL)
        return false;
    path_.push_back(root->val);
    if (root->val == x)
        return true;

    if (path(root->left, path_, x) || path(root->right, path_, x))
        return true;

    path_.pop_back();
    return false;
}

vector<int> root_to_node(Node *root, int x)
{
    vector<int> ans;
    path(root, ans, x);
    return ans;
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

    printBT(root);
    cout << endl;
    vector<int> ans = root_to_node(root, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}