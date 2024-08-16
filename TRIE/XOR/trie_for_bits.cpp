#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *link[2];
    bool contains_key(int bit)
    {
        return link[bit] != NULL;
    }
    void put(int bit, Node *node)
    {
        link[bit] = node;
    }
    Node *get(int bit)
    {
        return link[bit];
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *ptr = root;
        for (int i = 31; i >= 0; i--)
        {
            int pos = 1 << i;
            int bit = (num & pos) ? 1 : 0;
            if (!ptr->contains_key(bit))
                ptr->put(bit, new Node());
            ptr = ptr->get(bit);
        }
    }
    int maxElement(int num)
    {
        int res = 0;
        Node *ptr = root;
        for (int i = 31; i >= 0; i--)
        {
            int pos = 1 << i;
            int bitOfNum = (pos & num) ? 1 : 0;
            int reqBit = !bitOfNum;
            if (ptr->contains_key(reqBit))
            {
                ptr = ptr->get(reqBit);
                res = res | pos;
            }
            else
                ptr = ptr->get(1 - reqBit);
        }
        return res;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie trie;
    for (auto i : nums)
    {
        trie.insert(i);
    }
    int ans = INT_MIN;
    for (auto i : nums)
    {
        ans = max(ans, trie.maxElement(i));
    }
    return ans;
}