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
    TRIE()
    {
        root = new node();
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

void dfs(vector<vector<char>> &board, string word, int x, int y, node *curr,vector<string> &ans)
{
    int n = board.size();
    int m = board[0].size();
    if (curr->end_point)
    {  
        ans.push_back(word);
    }  
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && board[X][Y]!='*' && curr->contains_key(board[X][Y]))
        {
            word.push_back(board[X][Y]);
            char temp=board[X][Y];
            board[X][Y]='*';
            dfs(board, word, X, Y, curr->get(temp),ans);
            board[X][Y]=temp;
            word.pop_back();
        }
    }
    return;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        TRIE trie;
        for(auto i:words)trie.add_string(i);
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char c=board[i][j];
                if(!trie.root->contains_key(c))continue;
                string word="";
                word.push_back(c);
                board[i][j]='*';
                dfs(board,word,i,j,trie.root->get(c),ans);
                board[i][j]=c;
                // if(temp!="")ans.push_back(temp);
            }
        }
        return ans;
    }

int main()
{
    // vector<vector<char>> board = {{'a', 'a'}};
    // vector<string> words = {"aaa"};
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};
    vector<string> words = {"oath","pea","eat","rain","hklf", "hf"};
    // vector<string> words = {"oa","oaa"};
    // vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> ans = findWords(board,words);
    for(auto i:ans)cout<<i<<" ";
}