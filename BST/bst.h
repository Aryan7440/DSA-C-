#include <bits/stdc++.h>
using namespace std;

class bst
{
public:
    bst *right;
    bst *left;
    int val;

    bst(int x = 0)
    {
        val = x;
        right = left = NULL;
    }
};

void print_bst(const string &prefix, const bst *node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;
        cout << (isLeft ? "R--" : "L--");
        // print the value of the node
        cout << node->val << std::endl;
        // enter the next tree level - left and right branch
        print_bst(prefix + (isLeft ? "|   " : "    "), node->right, true);
        print_bst(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBST(const bst *node)
{
    print_bst("", node, false);
}
bst *insert(bst *root, int x)
{
    if (root == NULL)
        return new bst(x);
    if (x > root->val)
        root->right = insert(root->right, x);
    if (x < root->val)
        root->left = insert(root->left, x);

    return root;
}

bst *delete_bst(bst *root, int x)
{
    if (root == NULL)
        return root;
    else if (x > root->val)
    {
        root->right = delete_bst(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = delete_bst(root->left, x);
    }

    else
    {

        if(!root->left)return root->right;
        if(!root->right)return root->left;
        if (root->left && root->right)
        {
            bst *succesor = root->right;
            while (succesor->left != NULL)
            {
                succesor = succesor->left;
            }
            root->val = succesor->val;
            root->right = delete_bst(root->right, succesor->val);
        }
    }
    return root;
}

bst* create_bst(vector<int> arr)
{
    bst* ans=new bst(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        insert(ans,arr[i]);
    }
    return ans;
    
}

bst* search(bst* root,int x)
{
    if(root==NULL)return root;
    if(x>root->val)return search(root->right,x);
    if(x<root->val)return search(root->left,x);
    if(x==root->val)return root;
    else return NULL;

}


void inorder(bst* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
bst* inorder_succesor(bst* root)
{
    bst* ans=root->right;
    while(ans && ans->left)
    {
        ans=ans->left;
    }
    return ans;
}
bst* inorder_predicessor(bst* root)
{
    bst* ans=root->left;
    while(ans && ans->right)
    {
        ans=ans->right;
    }
    return ans;
}

int height(bst* root)
{
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right);
    return l>r ? l+1:r+1;
}