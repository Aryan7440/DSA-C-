#include <iostream>
#include <queue>
// #include "queue.h"
using namespace std;

class Node
{
public:
    int element;
    Node *left;
    Node *right;
    Node(int x = 0)
    {
        element = x;
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
    cout << root->element << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->element << " ";
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
    cout << root->element << " ";
}

bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->element == x)
        {
            return true;
        }
        if (root->element > x)
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
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->element << " ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}


Node *LCA(Node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->element == a || root->element == b)
    {
        return root;
    }
    Node *left = LCA(root->left, a, b);
    Node *right = LCA(root->right, a, b);
    if (!left && !right)
    {
        return NULL;
    }
    
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    return root;
}
Node *LCA(Node *root, Node* a, Node* b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == a || root == b)
    {
        return root;
    }
    Node *left = LCA(root->left, a, b);
    Node *right = LCA(root->right, a, b);
    if (!left && !right)
    {
        return NULL;
    }
    
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    return root;
}
int height(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    return max(height(root->right),height(root->left))+1;
    
}
int numberOfnodes(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    return numberOfnodes(root->right)+numberOfnodes(root->left)+1;
    
}
int sumofnodes(Node* root)
{
    if (root==NULL)
    {
        return 0;
    }
    return sumofnodes(root->right)+sumofnodes(root->left)+root->element;
    
}
bool isLeaf(Node* root)
{
    if (root==NULL) return false;
    if(root->left==NULL && root->right==NULL)return true;
    return false;   
}

int sumOfLeft(Node* root)
{
    int sum=0;
    if(root!=NULL)
    {
        if (isLeaf(root->left))
        {
            sum+=root->left->element;
        }
        else
        {
            sum+=sumOfLeft(root->left);
        }
        sum+=sumOfLeft(root->right); 
    }
    return sum;

}
int main()
{
    // binary* a;
    // binary b(5);
    // cout<<b.element<<endl;
    // a=a->getnode(3);
    // cout<<a->element<<endl;

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    // root->left->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    // root->right->right->left = new Node(1);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    // cout << search(root, 23) << endl;
    cout << endl;
    levelorder(root);
    // cout << endl;

    // cout<<sumOfLeft(root)<<endl;

    // Node* ans=LCA(root,5,1);
    // cout<<ans->element<<endl;
    // Node* ans2=LCA(root,root->left->left,root->right->right);
    // // levelorder(ans2);
    // cout<<ans2->element<<endl;
    // cout<<height(root)<<endl;
    // cout<<numberOfnodes(root)<<endl;
    // cout<<sumofnodes(root)<<endl;

    // Node* root2=new Node(20);
    // root2->left                = new Node(9);
    // root2->right               = new Node(49);
    // root2->right->left         = new Node(23);
    // root2->right->right        = new Node(52);
    // root2->right->right->left  = new Node(50);
    // root2->left->left          = new Node(5);
    // root2->left->right         = new Node(12);
    // root2->left->right->right  = new Node(12);
    // cout << "Sum of left leaves is "<<sumOfLeft(root2);

}