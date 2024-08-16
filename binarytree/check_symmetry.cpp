#include"binary_tree.h"


bool help(Node* root1,Node* root2)
{
    if(root1==NULL ||root2==NULL)return root1==root2;
    if(root1->val!=root2->val)return false;

    return help(root1->left,root2->right) && help(root1->right,root2->left);
}

bool check_symmetry(Node* root)
{
    return root==NULL || help(root->left,root->right);  //root1/left/right == root2/right/left
}

int main()
{
    Node* root=new Node(0);
    root->left=new Node(1);
    root->right=new Node(1);
    root->left->left=new Node(2);
    root->right->right=new Node(2);

    root->left->right=new Node(3);
    root->right->left=new Node(3);

    root->left->right->right=new Node(4);
    root->right->left->left=new Node(4);
    root->right->left->left->left=new Node(4);

    printBT(root);
    qlevel(root);
    cout<<endl;
    cout<<check_symmetry(root);
}