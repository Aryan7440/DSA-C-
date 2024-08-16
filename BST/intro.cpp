#include <iostream>
#include <queue>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;

    BST(int x = 0)
    {
        data = x;
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
    if (x > root->data)
    {
        root->right = insert_node(root->right, x);
    }
    if (x < root->data)
    {
        root->left = insert_node(root->left, x);
    }
    return root;
}

void inorder(BST *a)
{
    if (a)
    {
        inorder(a->left);
        cout << a->data << " ";
        inorder(a->right);
    }
}

void levelorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        BST *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int height(BST *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void print_level(BST *root, int h)
{
    if (root == NULL)
    {
        return;
    }
    if (h == 1)
    {
        cout << root->data << " ";
    }
    else
    {
        print_level(root->left, h - 1);
        print_level(root->right, h - 1);
    }
}

void printlevelorder(BST *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_level(root, i);
        cout << endl;
    }
}

int numOfNodes(BST *root)
{
    if (root == NULL)
        return 0;
    return numOfNodes(root->left) + numOfNodes(root->right) + 1;
}
int sumOfNodes(BST *root)
{
    if (root == NULL)
        return 0;
    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

void print_leaf(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
    }
    print_leaf(root->left);
    print_leaf(root->right);
}
void print_internal(BST *root)
{
    if (!root)
        return;
    if (root->left || root->right)
    {
        cout << root->data << " ";
    }
    print_internal(root->left);
    print_internal(root->right);
}

void qlevel(BST *root)
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
            cout << temp->data << " ";
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

void leftview(BST *root)
{
    if (!root)
    {
        return;
    }
    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {

            BST *temp = q.front();
            q.pop();
            if (i == 1)
            {
                cout << temp->data << " ";
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void rightview(BST *root)
{
    if (!root)
    {
        return;
    }
    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {

            BST *temp = q.front();
            q.pop();
            if (i == n)
            {
                cout << temp->data << " ";
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
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
    if (root->data > key)
    {
        root->left = deleteBST(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else if (root->data == key)
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
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
        return root;
    }
    return nullptr;
}

vector<int> level_sum(BST *root)
{
    vector<int> ans;
    int h = height(root);
    if (root == NULL)
    {
        ans.push_back(0);
        return ans;
    }
    queue<BST *> q;
    q.push(root);
    for (int j = 0; j < h; j++)
    {
        int n = q.size();
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            BST *temp = q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            sum+=temp->data;
        }
        ans.push_back(sum/n);
    }
    return ans;
}



int main()
{
    BST *a = newnode(4);
    insert_node(a, 2);
    insert_node(a, 6);
    insert_node(a, 1);
    insert_node(a, 3);
    insert_node(a, 5);
    insert_node(a, 7);
    insert_node(a, 8);
    insert_node(a, 0);
    // insert_node(a, 9);
    // insert_node(a, 10);
    // insert_node(a, 11);
    // insert_node(a, -1);
    // inorder(a);
    // cout << endl;
    // levelorder(a);
    // cout<<endl;
    printlevelorder(a);
    cout << endl;
    

    vector<int> ans=level_sum(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    




    // deleteBST(a,7);
    // deleteBST(a,6);
    // printlevelorder(a);
    // cout<<endl;
    // cout << numOfNodes(a) << endl;
    // cout << sumOfNodes(a) << endl;
    // print_leaf(a);
    // cout << endl;
    // print_internal(a);
    // cout << endl;
    // qlevel(a);
    // leftview(a);
    // cout<<endl;
    // rightview(a);
    // cout<<endl;
    // cout<<min(a)->data<<endl;
    // cout<<max(a)->data<<endl;
}