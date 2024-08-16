#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *dfs(Node *node, unordered_map<int, Node *> &mp)
{
    if (node == NULL)
        return NULL;
    Node *copy = new Node(node->val);
    if (mp.find(node->val) != mp.end())
        return mp[node->val];
    mp[node->val] = copy;
    for (auto i : node->neighbors)
    {
        copy->neighbors.push_back(dfs(i, mp));
    }
    return copy;
}
Node *cloneGraph(Node *node)
{
    unordered_map<int, Node *> mp;
    Node *ans = dfs(node, mp);
    return ans;
}

int main()
{
    Node *head = new Node(1);
    head->neighbors = {new Node(2), new Node(4)};
    head->neighbors[0]->neighbors = {head, new Node(3)};
    head->neighbors[0]->neighbors[1]->neighbors = {head->neighbors[0], head->neighbors[1]}; // 3
    head->neighbors[1]->neighbors = {head, head->neighbors[0]->neighbors[1]};
}