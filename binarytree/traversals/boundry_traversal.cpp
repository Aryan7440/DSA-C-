#include "binary_tree.h"
  // boundry traversal donsent mean left view
void left_side(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) // dont prnt leaf nodes
        return;
    cout << root->val << " ";
    if (root->left)
        left_side(root->left);
    else
        left_side(root->right);
}

void right_side(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) // dont prnt leaf nodes
        return;
    if (root->right)
        right_side(root->right);
    else
        right_side(root->left);
    cout << root->val << " ";
}

void print_nodes(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->val << " ";
    print_nodes(root->left);
    print_nodes(root->right);
}
void boundry(Node *root)
{
    cout << root->val << " ";   //root node
    left_side(root->left);
    // cout<<endl;
    print_nodes(root);
    // cout<<endl;
    right_side(root->right);
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(12);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(9);
    root->left->right->left->left->right = new Node(89);
    root->left->right->left->left->right->left = new Node(55);
    root->left->right->left->left->right->right = new Node(44);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(10);
    root->left->right->right->right->left = new Node(11);
    root->left->right->right->right->left->right = new Node(12);

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

    boundry(root);

    return 0;
}