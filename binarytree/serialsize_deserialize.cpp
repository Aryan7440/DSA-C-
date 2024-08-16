#include "binary_tree.h"
#include <bits/stdc++.h>



string deserialize(Node* root)
{
    queue<Node*> q;
    q.push(root);
    string  ans;
    while (!q.empty())
    {
        Node* curr=q.front();
        q.pop();
        if(curr==NULL)ans.append("#,");
        else ans.append(to_string(curr->val)+",");

        if(curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    ans.pop_back();
    return ans;
    
}
Node *serialize(string str)
{
    queue<Node *> q;

    if (str.size() == 0)
        return NULL;
    stringstream s(str);
    string a;
    getline(s, a, ',');

    Node *curr = new Node(stoi(a));
    q.push(curr);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        getline(s, a, ',');
        if (a == "#")
        {
            temp->left = NULL;
        }
        else
        {
            Node* l=new Node(stoi(a));
            temp->left = l;
            q.push(l);
        }

        getline(s, a, ',');
        if (a == "#")
        {
            temp->right = NULL;
        }
        else
        {
            Node* r=new Node(stoi(a));
            temp->right =r;
            q.push(r);
        }
    }
    return  curr;
}


int main()
{
    // string s="1,2,3,4,#,#,#,#,#";
    // Node* root=serialize(s);
    // printBT(root);

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->left->right=new Node(9);

    printBT(root);
    cout << endl;

    string ans=deserialize(root);
    cout<<ans<<endl;


    Node* root2=serialize(ans);
    printBT(root2);
}