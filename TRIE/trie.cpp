#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    node* link[26];
    int cp=0;
    int ep=0;

    bool contains_key(char c)
    {
        return link[c-'a']!=NULL;
    }
    node* get(char c)
    {
        return link[c-'a'];
    }
    void put(char c,node* node)
    {
        link[c-'a']=node;
    }
};
class trie
{
    public:
    node* root;
    trie()
    {
        root=new node();
    }
    void insert(string s)
    {
        node* ptr=root;
        for(int i=0;i<s.size();i++)
        {
            if(!ptr->contains_key(s[i]))
            {
                ptr->put(s[i],new node());
            }
            ptr=ptr->get(s[i]);
            ptr->cp++;
        }
        ptr->ep++;
    }
    bool search(string s)
    {
        node* ptr=root;
        for(int i=0;i<s.size();i++)
        {
            if(ptr->contains_key(s[i]))
            {
                ptr=ptr->get(s[i]);
            }
            else return false;
        }
        return ptr->ep;
    }
    bool startswith(string s)
    {
        node* ptr=root;
        for(int i=0;i<s.size();i++)
        {
            if(ptr->contains_key(s[i]))
            {
                ptr=ptr->get(s[i]);
            }
            else return false;
        }
        return true;
    }

};

int main()
{
    trie* obj=new trie();
    obj->insert("apple");
    cout<<obj->search("apple")<<endl;
    cout<<obj->search("app")<<endl;
    cout<<obj->startswith("app")<<endl;
    obj->insert("app");
    cout<<obj->search("app")<<endl;



}