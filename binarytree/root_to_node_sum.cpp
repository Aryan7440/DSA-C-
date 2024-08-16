#include "binary_tree.h"

int sum_path(Node *root, int cur_sum)
{
    if (root == NULL)
        return 0;
    cur_sum = cur_sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
        return cur_sum;
    return sum_path(root->left, cur_sum) + sum_path(root->right, cur_sum);
}
int sumNumbers(Node *root)
{
    int cur_sum = 0;
    int ans = sum_path(root, cur_sum);
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

    cout<<sumNumbers(root);

    
}