#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &arr,int x)
{
    if(arr.empty() || arr.back()<x)
    {
        arr.push_back(x);
        return;
    }
    int temp=arr.back();
    arr.pop_back();
    insert(arr,x);
    arr.push_back(temp);
    return;
}

void sort(vector<int> &arr)
{
    if(arr.empty() || arr.size()==1)
    {
        return;
    }
    int temp=arr.back();
    arr.pop_back();
    sort(arr);
    insert(arr,temp);
    return;
}

void display(vector<int> arr)
{
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr={5,3,6,22,5,1,0};
    display(arr);
    sort(arr);
    display(arr);

}