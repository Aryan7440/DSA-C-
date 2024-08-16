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
            int reqBit = 1 - bitOfNum;
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

static bool comp(vector<int> &i1, vector<int> &i2)
{
    return (i1[1] < i2[1]);
}
vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
{
    Trie trie;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < queries.size(); i++)
        queries[i].push_back(i);
    sort(queries.begin(), queries.end(), comp);
    vector<int> ans(queries.size());
    int q = 0;
    int i = 0;
    while (q < queries.size())
    {
        while (i < n && nums[i] <= queries[q][1])
        {
            trie.insert(nums[i]);
            i++;
        }
        if (i == 0)
            ans[queries[q][2]] = -1;
        else
            ans[queries[q][2]] = trie.maxElement(queries[q][0]);
        q++;
        if (q == queries.size())
            break;
    }
    return ans;
}
int main()
{
    vector<int> nums = {536870912, 0, 534710168, 330218644, 142254206};
    vector<vector<int>> queries = {{558240772, 1000000000}, {307628050, 1000000000}, {3319300, 1000000000}, {2751604, 683297522}, {214004, 404207941}};
    // vector<int> nums = {5, 2, 4, 6, 6, 3};
    // vector<vector<int>> queries = {{12, 4}, {8, 1}, {6, 3}};
    vector<int> ans = maximizeXor(nums, queries);
    for (auto i : ans)
        cout << i << " ";
}
