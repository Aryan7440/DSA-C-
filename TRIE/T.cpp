#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int end_point;
    node *link[26];

    bool contains_key(char c)
    {
        return this->link[c - 'a'] != NULL;
    }
    node *get(char c)
    {
        return this->link[c - 'a'];
    }
    void put(char c)
    {
        this->link[c - 'a'] = new node();
    }
};
class TRIE
{
public:
    node *root;
    void add_string(string s)
    {
        node *ptr = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (!ptr->contains_key(s[i]))
                ptr->put(s[i]);
            ptr = ptr->get(s[i]);
        }
        ptr->end_point++;
    }
    bool search(string s)
    {
        node *ptr = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (!ptr->contains_key(s[i]))
                return false;
            ptr = ptr->get(s[i]);
        }
        return ptr->end_point;
    }
    bool startsWith(string s)
    {
        node *ptr = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (!ptr->contains_key(s[i]))
                return false;
            ptr = ptr->get(s[i]);
        }
        return true;
    }
};