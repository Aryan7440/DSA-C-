#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
public:
    int prime = 636613;
    int a = 333;
    int b = 777;
    int m = 150;
    // h(c)=((ac+b)mod(prime))mod(m)

    vector<forward_list<int>> map;

    MyHashSet()
    {
        map.resize(150);
    }
    int hash_function(int key)
    {
        return ((a * key + b) % prime) % m;
    }

    void add(int key)
    {
        int pos = hash_function(key);
        map[pos].emplace_front(key);
    }

    void remove(int key)
    {
        int pos = hash_function(key);
        map[pos].remove(key);
    }

    bool contains(int key)
    {
        int pos = hash_function(key);
        for (auto i : map[pos])
        {
            if (i == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */