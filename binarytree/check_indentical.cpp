#include"binary_tree.h"
using namespace std;
bool check_identical(Node* root1,Node* root2)
{
    if(root1==NULL || root2==NULL)
    {
        return root1==root2;
    }
    if(root1->val!=root2->val)
    {
        return false;
    }
    bool l=check_identical(root1->left,root2->left);
    bool r=check_identical(root1->right,root2->right);
    return l&&r;
}


int main()
{
    Node* root1=new Node(4);
    root1->left=new Node(3);
    root1->right=new Node(2);
    root1->left->left=new Node(1);
    root1->left->right=new Node(9);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);
    root1->left->right->right=new Node(5);
    root1->right->left->left=new Node(8);

    Node* root2=new Node(4);
    root2->left=new Node(3);
    root2->right=new Node(2);
    root2->left->left=new Node(1);
    root2->left->right=new Node(9);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    root2->left->right->right=new Node(5);
    root2->right->left->left=new Node(8);

    cout<<check_identical(root1,root2);



}








