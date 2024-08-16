#include "binary_tree.h"
#include <queue>

int max_width(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    int Max = 0;
    while (!q.empty())
    {

        int n = q.size();
        int start=q.front().second,stop=q.back().second;
        // int lower=q.front().second;
        for (int i = 0; i < n; i++)
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            int cur_indx=temp.second-start;

            if (temp.first->left)
                q.push({temp.first->left, 2 * cur_indx + 1});
            if (temp.first->right)
                q.push({temp.first->right, 2 * cur_indx + 2});
        }
        if(q.size()>=2)
            Max=max(q.back().second-q.front().second+1,Max);
    }
    return Max;
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right=new Node(9);

    printBT(root);
    cout << endl;

    cout<<max_width(root);

    
}