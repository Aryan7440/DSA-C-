#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *link[26];
    int cp = 0;
    int ep = 0;
    int cw = 0;
    bool contains_key(char c)
    {
        return link[c - 'a'] != NULL;
    }
    node *get(char c)
    {
        return link[c - 'a'];
    }
    void put(char c, node *node)
    {
        cw = 1;
        link[c - 'a'] = node;
    }
};

class WordDictionary
{
public:
    node *root;
    WordDictionary()
    {
        root = new node();
    }

    void addWord(string word)
    {
        node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->contains_key(word[i]))
            {
                curr->put(word[i], new node());
            }
            curr = curr->get(word[i]);
        }
        curr->ep++;
    }
    bool search_util(node *r, string s, int p)
    {
        if (p == s.size())
        {
            if (r->ep != 0)
                return true;
            else
                return false;
        }
        if (s[p] == '.')
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (r->link[c - 'a'] != NULL)
                {
                    if (search_util(r->get(c), s, p + 1))
                        return true;
                }
            }
            return false;
        }
        if (r->contains_key(s[p]))
        {
            if (search_util(r->get(s[p]), s, p + 1))
                return true;
            else
                return false;
        }

        return false;
    }
    bool search(string word)
    {
        return search_util(root, word, 0);
    }
};
int main()
{
    WordDictionary *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("dad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
}