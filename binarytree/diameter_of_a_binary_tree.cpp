#include "binary_tree.h"

int diameter_of_binary_tree(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = diameter_of_binary_tree(root->left, diameter);
    int rh = diameter_of_binary_tree(root->right, diameter);

    diameter = max(diameter, lh + rh); // only this is added to the height code as we only need the height to compute diameter

    return 1 + max(lh, rh); // return height
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
    // root->right->right->left = new Node(1);


    printBT(root);
    int diameter=0;
    diameter_of_binary_tree(root,diameter);
    cout<<diameter;

}
