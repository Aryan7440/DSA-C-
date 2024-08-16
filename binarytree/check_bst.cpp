#include "binary_tree.h"


bool UTIL(Node* root, int l,int r)
{
    if(root==NULL)return true;
    if(root->val<l || root->val>r)return false;
    bool rt=UTIL(root->right,root->val,r);
    bool lt=UTIL(root->left,l,root->val);
    return rt && lt;
}
bool check_bst(Node* root)
{
    return UTIL(root,INT16_MIN,INT16_MAX);
}


int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(7);
    printBT(root);
    cout<<check_bst(root)<<endl;
    cout<<INT32_MAX<<endl;
    cout<<LONG_LONG_MAX<<endl;
    cout<<2147483647<<endl;
}