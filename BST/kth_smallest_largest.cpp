#include "bst.h"

void kth_smallest(bst *root, int k, int &count)
{
    if (root == NULL)
        return;
    kth_smallest(root->left, k, count);
    count++;
    if (count == k)
    {
        cout << root->val;
        return;
    }
    kth_smallest(root->right, k, count);
}

int main()
{
    bst *root = create_bst({4, 2, 6, 1, 3, 5, 7, 9, 10, 11, 12});
    printBST(root);
    int c = 0;
    kth_smallest(root, 5, c);
}