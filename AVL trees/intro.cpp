#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;

class avl
{
public:
    avl *left;
    avl *right;
    int val;
    int height;
    avl(int x = 0)
    {
        val = x;
        left = right = NULL;
        height = 1;
    }
};

avl *min(avl *root)
{
    if (root == NULL)
        return NULL;
    avl *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
avl *max(avl *root)
{
    if (root == NULL)
        return NULL;
    avl *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
int height(avl *root)
{
    // if (root == NULL)
    //     return 0;
    // return max(height(root->left),height(root->right)) + 1;

    int hl = (root && root->left) ? root->left->height : 0;
    int hr = (root && root->right) ? root->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}
int balanace_factor(avl *root)
{
    // return height(root->left) - height(root->right);
    int hl = (root && root->left) ? root->left->height : 0;
    int hr = (root && root->right) ? root->right->height : 0;

    return hl - hr;
}

avl *LLrotation(avl *&root)
{
    avl *p = root;
    avl *pl = root->left;
    avl *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = height(p);
    pl->height = height(pl);

    if (root == p)
        root = pl;

    return pl;
}
avl *RRrotation(avl *&root)
{
    avl *p = root;
    avl *pr = p->right;
    avl *prl = pr->left;

    pr->left = p;
    p->right = prl;

    pr->height = height(pr);
    p->height = height(p);

    if (root == p)
        root = pr;
    return pr;
}
avl *LRrotation(avl *&root)
{
    avl *p = root;
    avl *pl = p->left;
    avl *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);

    if (root == p)
        root = plr;
    return plr;
}
avl *RLrotation(avl *&root)
{
    avl *p = root;
    avl *pr = p->right;
    avl *prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;
    prl->left = p;
    prl->right = pr;

    pr->height = height(pr);
    p->height = height(p);
    prl->height = height(prl);

    if (root == p)
        root = prl;

    return prl;
}

avl *insert(avl *&root, int x)
{
    if (root == NULL)
    {
        avl *node = new avl(x);
        return node;
    }
    if (x > root->val)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        root->left = insert(root->left, x);
    }
    root->height = height(root);

    if (balanace_factor(root) == 2 && balanace_factor(root->left) == 1)
        return LLrotation(root);
    else if (balanace_factor(root) == -2 && balanace_factor(root->right) == -1)
        return RRrotation(root);
    else if (balanace_factor(root) == 2 && balanace_factor(root->left) == -1)
        return LRrotation(root);
    else if (balanace_factor(root) == -2 && balanace_factor(root->right) == 1)
        return RLrotation(root);

    return root;
}

void level_order(avl *root)
{
    if (!root)
        return;
    queue<avl *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            avl *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

avl *deleteBST(avl *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val > key)
    {
        root->left = deleteBST(root->left, key);
    }
    else if (root->val < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else if (root->val == key)
    {
        if (!root->left)
        {
            avl *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            avl *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            avl *temp = min(root->right);
            root->val = temp->val;
            root->right = deleteBST(root->right, temp->val);
        }
        return root;
    }

    // Update height
    root->height = height(root);

    // Balance Factor and Rotation
    if (balanace_factor(root) == 2 && balanace_factor(root->left) == 1)
    { // L1 Rotation
        return LLrotation(root);
    }
    else if (balanace_factor(root) == 2 && balanace_factor(root->left) == -1)
    { // L-1 Rotation
        return LRrotation(root);
    }
    else if (balanace_factor(root) == -2 && balanace_factor(root->right) == -1)
    { // R-1 Rotation
        return RRrotation(root);
    }
    else if (balanace_factor(root) == -2 && balanace_factor(root->right) == 1)
    { // R1 Rotation
        return RLrotation(root);
    }
    else if (balanace_factor(root) == 2 && balanace_factor(root->right) == 0)
    { // L0 Rotation
        return LLrotation(root);
    }
    else if (balanace_factor(root) == -2 && balanace_factor(root->right) == 0)
    { // R0 Rotation
        return RRrotation(root);
    }

    return root;
}

int main()
{
    vector<int> a = {10, 20, 30, 40, 50, 60, 70};
    BST *root1 = create_BST(a);
    levelorder(root1);

    avl *root = new avl(10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);

    level_order(root);
}
