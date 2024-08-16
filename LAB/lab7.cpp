// write a prog based on binary search tree by excuting the follwoing steps

// a. take node values to be inserted in the binary search tree as input from the user
// b. formuklate the bianry search trees using the node values takes as input from the input ablve

// c. print the leaf nodes as well as sum of leaf nodes values present in the binary earch tree obtaind in step b
// d. insert n number of additional nodes in the binary search tree obtained in step b where n is taken as input from the user
// now primt the sum of leaf nodes valuse of the newly constructed BST

// 2.  write a prog to find out the subset of the array satisfying the following given conditions

// a. consider an array  a of int size and ele are taken as input
// take an int k as input from the user  your prog shuld be able to find out all possible combinations of array ind numbers for which the sum of array elements is equal to k if no such combinations is found print no such numbers are present in the array
#include <iostream>
#include <vector>
#include <queue>

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

bst *insert(bst *root, int x)
{
    if (root == NULL)
    {
        bst *ans = new bst(x);
        return ans;
    }
    if (root->val > x)
    {
        root->left = insert(root->left, x);
    }
    if (root->val < x)
    {
        root->right = insert(root->right, x);
    }
    return root;
}

void print_leaf_nodes(bst *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
        return;
    }
    print_leaf_nodes(root->left);
    print_leaf_nodes(root->right);
    return;
}

int sum_of_leaf_nodes(bst *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    return sum_of_leaf_nodes(root->left) + sum_of_leaf_nodes(root->right);
}

void level(bst *root)
{
    queue<bst *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            bst *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cout << "enter NUMBER of elements:";
    cin >> n;
    cout << "enter elements: ";
    bst *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (i == 0)
        {
            root = new bst(temp);
        }
        else
            insert(root, temp);
    }
    cout << "level order of BST:" << endl;
    level(root);
    cout << endl;

    cout << "leaf nodes are: " << endl;
    print_leaf_nodes(root);
    cout << endl;

    cout << "SUM OF LEAF NODES:" << sum_of_leaf_nodes(root) << endl;

    cout << "enter NUMBER of  more elements you want to add:";
    cin >> n;
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        insert(root, temp);
    }
    cout << "level order of BST:" << endl;
    level(root);

    cout << "leaf nodes after adding are: " << endl;
    print_leaf_nodes(root);
    cout << endl;

    cout << "SUM OF LEAF NODES AFTER ADDING:" << sum_of_leaf_nodes(root) << endl;
}