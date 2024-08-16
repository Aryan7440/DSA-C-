#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int end_point;
    node *link[26];

    bool contains_key(char c)
    {
        return link[c - 'a'] != NULL;
    }
    node *get(char c)
    {
        return link[c - 'a'];
    }
    void put(char c)
    {
        link[c - 'a'] = new node();
    }
};
class TRIE
{
public:
    node *root;
    TRIE()
    {
        root=new node();
    }
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
};

class Encrypter
{
public:
    unordered_map<char, string> mp;
    unordered_map<string, vector<char>> ct;
    // unordered_set<string> s;
    TRIE trie;
    Encrypter(vector<char> keys, vector<string> values, vector<string> dictionary)
    {
        for (int i = 0; i < keys.size(); i++)
        {
            mp[keys[i]] = values[i];
            ct[values[i]].push_back(keys[i]);
        }
        // for(auto i:dictionary)s.insert(i);
        for (auto i : dictionary)
        {
            trie.add_string(i);
        }
    }

    string encrypt(string word1)
    {
        string ans = "";
        for (auto i : word1)
        {
            if (mp.find(i) == mp.end())
                return "";
            ans += mp[i];
        }
        return ans;
    }
    int util(string &word2, node *curr, int i)
    {
        if (i >= word2.size())
            return curr->end_point;
        string temp;
        temp.push_back(word2[i]);
        temp.push_back(word2[i + 1]);
        int count = 0;
        for (auto c : ct[temp])
        {
            // count+=util(word2,curr+c,i+2);
            if (curr->contains_key(c))
            {
                count += util(word2, curr->get(c), i + 2);
            }
        }
        return count;
    }
    int decrypt(string word2)
    {
        return util(word2, trie.root, 0);
    }
};

int main()
{
    Encrypter encrypter({'a', 'b', 'c', 'd'}, {"ei", "zf", "ei", "am"}, {"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"});
    cout << encrypter.encrypt("abcd") << endl; // return "eizfeiam".
                                               // 'a' maps to "ei", 'b' maps to "zf", 'c' maps to "ei", and 'd' maps to "am".
    cout<<encrypter.decrypt("eizfeiam");             // return 2.
                                               // "ei" can map to 'a' or 'c', "zf" maps to 'b', and "am" maps to 'd'.
                                               // Thus, the possible strings after decryption are "abad", "cbad", "abcd", and "cbcd".
                                               // 2 of those strings, "abad" and "abcd", appear in dictionary, so the answer is 2.
}