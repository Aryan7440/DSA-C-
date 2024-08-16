#include "bst.h"
using namespace std;


class Solution {
public:
    bst* fst;
    bst* prev;
    bst* mid;
    bst* sec;
    void inorder(bst* root)
    {
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val)
        {
            if(fst==NULL)
            {
                mid=root;
                fst=prev;  
            }
            else
            {
                sec=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(bst* root)
    {
        prev=fst=mid=prev=NULL;
        inorder(root);
        if(fst&& sec)swap(fst->val,sec->val);
        else swap(fst->val,mid->val);
    
    }
};