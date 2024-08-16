#include "binary_tree.h"
#include <stack>

void one_stack_postorder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    // s.push(root);
    while (curr != NULL || !s.empty())
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                cout << temp->val << " ";
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->val << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
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
    // root->right->right->left = new Node(1);

    postorder(root);
    cout << endl;
    qlevel(root);
    cout << endl;
    one_stack_postorder(root);
}