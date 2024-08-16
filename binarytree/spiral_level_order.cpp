#include "binary_tree.h"
#include <stack>

void spiral_level_order(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    if (root == NULL)
        return;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {

            Node *temp = s1.top();
            s1.pop();
            cout << temp->val << " ";
            if (temp->left)
            {
                s2.push(temp->left);
            }
            if (temp->right)
            {
                s2.push(temp->right);
            }
        }
        while (!s2.empty())
        {

            Node *temp = s2.top();
            s2.pop();
            cout << temp->val << " ";
            if (temp->right)
            {
                s1.push(temp->right);
            }
            if (temp->left)
            {
                s1.push(temp->left);
            }
        }
    }
}

int main(int argc, char const *argv[])
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
    qlevel(root);
    cout<<endl;
    spiral_level_order(root);

    return 0;
}
