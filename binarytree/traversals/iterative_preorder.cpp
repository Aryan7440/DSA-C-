#include "binary_tree.h"
#include <stack>

void preorder_it(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->val << " ";
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
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
    root->right->right->left = new Node(1);

    preorder(root);
    cout << endl;
    qlevel(root);
    cout << endl;
    preorder_it(root);
}
