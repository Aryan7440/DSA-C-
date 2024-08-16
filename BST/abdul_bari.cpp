#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class bst
{
public:
    int val;
    bst *left;
    bst *right;

    bst(int x = 0)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preorder(bst *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(bst *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
void inorder(bst *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void level_order(bst *root)
{
    queue<bst *> q;
    q.emplace(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            bst *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left)
                q.emplace(temp->left);
            if (temp->right)
                q.emplace(temp->right);
        }
        cout << endl;
    }
}
bst *min(bst *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    return min(root->left);
}
bst *max(bst *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    return max(root->right);
}

bst *delete_node(bst *root, int x)
{
    if (root == NULL)
        return root;
    if (x > root->val)
    {
        root->right = delete_node(root->right, x);
    }
    if (x < root->val)
    {
        root->left = delete_node(root->left, x);
    }
    if (root->val == x)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // bst *temp=root;
            return NULL;
        }
        if (root->left == NULL)
        {
            bst *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            bst *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            bst *temp = min(root->right);
            root->val = temp->val;
            root->right = delete_node(root->right, temp->val);
        }
        return root;
    }
    return root;
}

bst *insert(bst *&root, int x)
{
    if (root == NULL)
    {
        bst *node = new bst(x);
        root = node;
        return root;
    }
    if (x > root->val)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        root->left = insert(root->left, x);
    }
    return root;
}
bst *create_BST(vector<int> v)
{
    bst *root = new bst(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        insert(root, v[i]);
    }
    return root;
}

void util(vector<int> v, bst *&root, int l, int r)
{
    if (l > r)
        return;
    int mid = l + (r - l) / 2;
    insert(root, v[mid]);
    util(v, root->left, l, mid - 1);
    util(v, root->right, mid + 1, r);
}

bst *create_balanced_tree(vector<int> v)
{
    sort(v.begin(), v.end());
    int l = 0;
    int r = v.size() - 1;
    bst *root = NULL;
    util(v, root, l, r);
    return root;
}

bst *build(vector<int> &v, int &i, int bound)
{
    if (i == v.size() || v[i] > bound)
        return NULL;
    bst *root = new bst(v[i]);
    i++;
    root->left = build(v, i, root->val);
    root->right = build(v, i, bound);
    return root;
}
bst *generate_bst_from_preorder(vector<int> v)
{
    int i = 0;
    return build(v, i, INT16_MAX);
}

bst* build2(vector<int> &v,int start,int stop)
{
    if(start>stop)return NULL;
    if(start==stop)
    {
        return new bst(v[start]);
    }
    int ls=start+1;
    int rs=start;
    while (rs<v.size() && v[rs]<=v[start])
    {
        rs++;
    }
    int le=rs-1;
    int re=stop;
    bst* root=new bst(v[start]);
    root->left=build2(v,ls,le);
    root->right=build2(v,rs,re);
    return root;
    
}
bst* bst_from_preorder(vector<int> v)
{
    if(v.size()==0)return NULL;
    bst* root=build2(v,0,v.size()-1);
    return root;
}

int main()
{

    vector<int> v1 = {8, 5, 1, 7, 10, 12};
    // bst *root3 = generate_bst_from_preorder(v1);
    bst *root3 = bst_from_preorder(v1);
    level_order(root3);
    preorder(root3);
    cout << endl;
}