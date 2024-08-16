#include "binary_tree.h"


//solution is kinda like diameter but instead of height we find the left sum and right sum of paths of the root and a reference variabe store the lp+rp+val
// the function will return the max path from a root to node
int max_path(Node *root, int &max_sum)
{
    if (root == NULL)
        return 0;

    int lps = max(0, max_path(root->left, max_sum));
    int rps = max(0, max_path(root->right, max_sum));

    // max(0,max_path())   0 is for negative numbers a tree with 2,-1,NULL   ans would be 2  but without zero it will return 2-1=1!!

    max_sum = max(max_sum, lps + rps + root->val);

    return max(lps, rps) + root->val;
}
int max_path_sum(Node *root)
{
    int max_sum = INT_MIN;
    max_path(root, max_sum);
    return max_sum;
}

int main()
{
    // Node *root = new Node(2);
    // root->right = new Node(-1);

    Node* root=new Node(4);
    root->left=new Node(3);
    root->right=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(9);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->right->right=new Node(5);
    root->right->left->left=new Node(8);
    
    
    
    printBT(root);

    cout << max_path_sum(root);
}