#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> &ans, int n, int k, int num)
{
    if (n == 0)
    {
        ans.push_back(num);
        return;
    }
    if ((num % 10) + k <= 9)
        DFS(ans, n - 1, k, (num * 10) +(num%10)+ k);
    if ((num % 10) - k >= 0 && k!=0)
        DFS(ans, n - 1, k, (num * 10)+(num%10) - k);
}

vector<int> cmd(int n,int k)
{
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
    {
        DFS(ans,n-1,k,i);
    }
    return ans;
    
}

int main()
{
    vector<int> ans=cmd(2,2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}