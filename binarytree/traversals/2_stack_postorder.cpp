#include"binary_tree.h"
#include<stack>


void two_stack_postorder(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node* temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL)s1.push(temp->left);
        if(temp->right!=NULL)s1.push(temp->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
    cout<<endl;

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

    postorder(root);
    cout << endl;
    qlevel(root);
    cout << endl;
    two_stack_postorder(root);
}