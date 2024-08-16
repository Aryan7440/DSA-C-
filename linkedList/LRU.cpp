#include <bits/stdc++.h>
using namespace std;

class LL
{
public:
    int key;
    int value;
    LL *next;
    LL *prev;

    LL(int a,int b)
    {
        key = a;
        value=b;
        next = prev = NULL;
    }
};
class LRU
{
    int max_size;
    int size;
    LL *head;
    LL *tail;
    unordered_map<int,LL*> mp;
public:
    LRU(int capacity)
    {
        max_size = capacity;
        head = new LL(INT_MAX,INT_MIN);
        tail = new LL(INT_MAX,INT_MIN);
        head->next=tail;
        tail->prev=head;
        size = 0;
    }
    void put(int k,int v)
    {
        LL *temp = new LL(k,v);
        if(mp.find(k)!=mp.end())
        {
            LL* d=mp[k];
            mp[k]=NULL;
            d->prev->next=d->next;
            d->next->prev=d->prev;
            delete d;
            size--;
        }
        mp[k]=temp;
        if(size<max_size)
        {
            temp->next=head->next;
            temp->prev=head;
            head->next->prev=temp;
            head->next=temp;
            size++;
        }
        else
        {
            LL* d=tail->prev;
            d->prev->next=tail;
            tail->prev=d->prev;
            // mp[d->key]=NULL;
            mp.erase(d->key);
            delete d;

            temp->next=head->next;
            temp->prev=head;
            head->next->prev=temp;
            head->next=temp;
        }
    }
    int get(int k)
    {
        if(mp.find(k)==mp.end())return -1;
        else
        {
            LL* d=mp[k];
            d->prev->next=d->next;
            d->next->prev=d->prev;

            d->next=head->next;
            d->prev=head;
            head->next->prev=d;
            head->next=d;
            return head->next->value;
        }
    }
};

int main()
{
    LRU* obj=new LRU(2);
    obj->put(1,1);
    obj->put(2,2);
    cout<<obj->get(1)<<endl;
    obj->put(3,3);
    cout<<obj->get(2)<<endl;
    obj->put(4,4);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(3)<<endl;
    cout<<obj->get(4)<<endl;

}