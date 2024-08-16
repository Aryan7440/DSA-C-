#include <iostream>
#include <queue>
using namespace std;

class BST
{
public:
    int val;
    BST *left;
    BST *right;

    BST(int x = 0)
    {
        val = x;
        left = right = NULL;
    }
};

BST *newnode(int x)
{
    BST *node = new BST(x);
    return node;
}
BST *insert_node(BST *root, int x)
{
    if (root == NULL)
    {
        return newnode(x);
    }
    if (x > root->val)
    {
        root->right = insert_node(root->right, x);
    }
    if (x < root->val)
    {
        root->left = insert_node(root->left, x);
    }
    return root;
}
BST *create_BST(vector<int> v)
{
    BST *root = new BST(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        insert_node(root, v[i]);
    }
    return root;
}

void inorder(BST *a)
{
    if (a)
    {
        inorder(a->left);
        cout << a->val << " ";
        inorder(a->right);
    }
}

void preorder(BST *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(BST *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
int height(BST *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
void levelorder(BST *root)
{
    if (!root)
        return;
    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            BST *temp = q.front();
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

BST *min(BST *root)
{
    if (root == NULL)
        return NULL;
    BST *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
BST *max(BST *root)
{
    if (root == NULL)
        return NULL;
    BST *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

BST *deleteBST(BST *root, int key)
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
            BST *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            BST *temp = min(root->right);
            root->val = temp->val;
            root->right = deleteBST(root->right, temp->val);
        }
        return root;
    }
    return nullptr;
}