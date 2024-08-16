#include "bst.h"

bst *construct(vector<int> &pre, int start, int stop)
{
    if (start == stop)
        return new bst(pre[start]);
    bst *ans = new bst(pre[start]);
    int i = start;
    while (i <= stop)
    {
        if (pre[i] > pre[start])
            break;
        i++;
    }
    ans->left=construct(pre,start+1,i-1);
    ans->right=construct(pre,i,stop);
    return ans;
}


int main()
{
    vector<int> pre={4,2,1,3,6,5,7};
    bst* root=construct(pre,0,pre.size()-1);
    printBST(root);
}