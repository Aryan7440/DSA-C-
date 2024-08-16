#include "bst.h"

bst* LCA(bst* root,bst* first,bst* second)
{
    if(first->val>second->val)return LCA(root,second,first);

    if(first->val > root->val)return LCA(root->right,first,second);
    if(second->val < root->val)return LCA(root->left,first,second);

    else return root;  
}

int main()
{
    bst *root = create_bst({4,2,6,1,3,5,7,9,10,11,12});
    printBST(root);
    bst* r2=search(root,1);
    bst* r1=search(root,3);
    bst* ans=LCA(root,r2,r1);
    printBST(ans);
}

