#include <bits/stdc++.h>
using namespace std;

void insert_at_pos(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.emplace(x);
        return ;
    }
    if(s.top()<x)
    {
        int temp=s.top();
        s.pop();
        insert_at_pos(s,x);
        s.push(temp);
    }
    else
    {
        s.push(x);
        return;
    }
}

void sort(stack<int> &s)
{
    if(s.size()<=1)return;
    int x=s.top();
    s.pop();
    sort(s);
    insert_at_pos(s,x);
    return;
}

void display(stack<int> s)
{
    int n=s.size();
    for (int i = 0; i < n; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    vector<int> arr={8,4,2,1,11,5,23};
    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
    }

    display(s);
    sort(s);
    display(s);
    
}
