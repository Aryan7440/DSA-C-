#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *&root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<Node*> q;
    q.emplace(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> t;
        for (int i = 0; i < n; i++)
        {
            Node* TEMP=q.front();
            vector<Node *> temp = TEMP->children;
            q.pop();
            t.push_back(TEMP->val);

            for (auto i : temp)
            {
                // t.push_back(i->val);
                // if (!(i->children).empty())
                // {
                //     q.emplace(i);
                // }
                q.emplace(i);
            }
        }
        ans.push_back(t);
    }
    return ans;
}
void display(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;  
    }
    
}

int main()
{
    vector<Node *> ch2;
    Node *ch21 = new Node(3);
    ch2.push_back(ch21);
    Node *ch22 = new Node(4);
    ch2.push_back(ch22);

    vector<Node *> ch3;
    Node *ch31 = new Node(5);
    ch3.push_back(ch31);
    Node *ch32 = new Node(6);
    ch3.push_back(ch32);

    vector<Node *> ch1;
    Node *ch11 = new Node(1, ch2);
    ch1.push_back(ch11);
    Node *ch12 = new Node(2, ch3);
    ch1.push_back(ch12);

    Node *head = new Node(0, ch1);

    vector<vector<int>> lo=levelOrder(head);
    display(lo);

}