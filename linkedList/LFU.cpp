#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    int value;
    node *next;
    node *prev;
    int f;

    node(int a, int b)
    {
        key = a;
        value = b;
        f = 0;
        next = prev = NULL;
    }
};
class LL
{
public:
    node *head;
    node *tail;
    int size;
    LL()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        size = 0;
    }
    void remove(node *rem)
    {
        rem->prev->next = rem->next;
        rem->next->prev = rem->prev;
        delete rem;
        size--;
    }
    void add_front(node *n)
    {
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        size++;
    }
};

class LFUCache
{
    unordered_map<int, node *> add;
    unordered_map<int, LL *> freq;
    int cap;
    int least_freq;

public:
    LFUCache(int capacity)
    {
        cap = capacity;
    }
    void update_freq(node *n)
    {
        freq[n->f]->remove(n);
        if (n->f == least_freq && freq[n->f]->size == 0)
            least_freq++;
        LL *next_higher_f = new LL();
        if (freq.find(n->f + 1) != freq.end())
            next_higher_f = freq[n->f + 1];
        n->f += 1;
        next_higher_f->add_front(n);
        freq[n->f] = next_higher_f;
        add[n->key] = n;
    }

    int get(int key)
    {
        if (add.find(key) != add.end())
        {
            node *n = add[key];
            int val = n->value;
            update_freq(n);
            return val;
        }
        return -1;
    }

    // void put(int key, int value)
    // {
    //     if()
    // }
};