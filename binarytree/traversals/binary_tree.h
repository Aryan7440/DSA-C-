#include <iostream>
#include <queue>
// #include "queue.h"
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x = 0)
    {
        val = x;
        left = NULL;
        right = NULL;
    }

    Node *getnode(int x = 0)
    {
        Node *a = new Node(x);
        return a;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->val == x)
        {
            return true;
        }
        if (root->val > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}

void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // queue q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->val << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << endl;
}

void qlevel(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;
    q.push(root);
    // int n = q.size();
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
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
        cout<<endl;
    }
}


// Node *LCA(Node *root, int a, int b)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (root->val == a || root->val == b)
//     {
//         return root;
//     }
//     Node *left = LCA(root->left, a, b);
//     Node *right = LCA(root->right, a, b);
//     if (!left && !right)
//     {
//         return NULL;
//     }

//     if (left == NULL)
//     {
//         return right;
//     }
//     if (right == NULL)
//     {
//         return left;
//     }
//     return root;
// }
// Node *LCA(Node *root, Node* a, Node* b)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (root == a || root == b)
//     {
//         return root;
//     }
//     Node *left = LCA(root->left, a, b);
//     Node *right = LCA(root->right, a, b);
//     if (!left && !right)
//     {
//         return NULL;
//     }

//     if (left == NULL)
//     {
//         return right;
//     }
//     if (right == NULL)
//     {
//         return left;
//     }
//     return root;
// }


void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->val << std::endl;
        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}