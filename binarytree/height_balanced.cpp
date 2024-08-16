#include "binary_tree.h"

int height_node(Node *root)
{
    if (root == NULL)
        return 0;
    int lrh = height_node(root->left);
    int rrh = height_node(root->right);
    return 1 + max(lrh, rrh);
}
int height_balanced(Node *root)
{

    int lh = height_node(root->left);
    if (lh == -1)
        return -1;  // dosent recurr further as condition is already false
    int rh = height_node(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) < 1)  // if unbalanced returns -1
        return -1;
    return 1 + max(lh, rh);  // returns height if balanced
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    ;
    int hl = height(root->left);
    int hr = height(root->right);

    int bf = hl - hr;
    if (bf >= -1 && bf <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}