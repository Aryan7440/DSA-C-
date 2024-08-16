#include "binary_tree.h"
#include<stack>

void inorder_it(Node* root)
{
    stack<Node*> s;
    // s.push(root);
    Node* curr=root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->val<<" ";
        curr=curr->right; 
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

    inorder(root);
    cout << endl;
    // qlevel(root);
    // cout << endl;
    inorder_it(root);
}
