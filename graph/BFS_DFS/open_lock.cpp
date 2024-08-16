#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string>& deadends, string target) 
    {
        if(target=="0000")return 0;
        queue<string> q;
        q.push("0000");
        int len=0;
        unordered_set<string> set(deadends.begin(),deadends.end());
        if(set.find("0000")!=set.end())return -1;
        set.insert("0000");
        while(!q.empty())
        {
            int n=q.size();
            len++;
            for(int i=0;i<n;i++)
            {
                string curr=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    string temp=curr;
                    char c=temp[j];
                    temp[j]=char(c+1)>'9' ? '0':char(c+1);
                    if(set.find(temp)==set.end())
                    {
                        if(temp==target)return len;
                        q.push(temp);
                        set.insert(temp);
                    }
                    temp[j]=char(c-1)<'0' ? '9':char(c-1);
                    if(set.find(temp)==set.end())
                    {
                        if(temp==target)return len;
                        q.push(temp);
                        set.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
int main()
{
    vector<string>deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    cout<<openLock(deadends,target);
    // cout<<'0'+0; 0=48 &&9=57
    // char c='8';
    // char d=char(c+1)>'9'?'0':char(c+1);
    // cout<<d;
}