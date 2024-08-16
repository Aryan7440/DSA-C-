#include "binary_tree.h"


class nodevalue
{
    public:
    int minval;
    int maxval;
    int numb;
    nodevalue(int min,int max,int num)
    {
        minval=min;
        maxval=max;
        numb=num;
    }
};

class solution
{
    nodevalue largest(Node* root)
    {
        if(root==NULL)return nodevalue(INT_MAX,INT_MIN,1);

        auto l=largest(root->left);
        auto r=largest(root->right);

        if(l.maxval>root->val || r.minval<root->val)return nodevalue(INT_MIN,INT_MAX,max(l.numb,r.numb));
        else return nodevalue(min(root->val,l.minval),max(root->val,r.maxval),l.numb+r.numb+1);

    }
    public:
    
};