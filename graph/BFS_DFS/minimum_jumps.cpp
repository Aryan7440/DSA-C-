#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        vector<vector<int>> vis(2,vector<int>(6000,0));
        for(auto i:forbidden)
        {
            vis[0][i]=1;
            vis[1][i]=1;
        }
        queue<pair<int,int>> q;
        vis[0][0]=1;
        vis[1][0]=1;
        q.push({0,-1});
        int jump=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                int num=p.first;
                int flag=p.second;
                if(num==x)return jump;
                q.pop();
                if(num+a<6000 && !vis[0][num+a] )
                {
                    q.push({num+a,0});
                    vis[0][num+a]=1;
                }
                if(num-b>0 && !vis[1][num-b] && !flag)
                {
                    q.push({num-b,1});
                    vis[1][num-b]=1;
                }
            }
            jump++;
        }
        return -1;
    }
int main()
{
    vector<int> forbidden = {8,3,16,6,12,20};
    int a = 15, b = 13, x = 11;
    cout<<minimumJumps(forbidden,a,b,x);
}