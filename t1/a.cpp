
#include <bits/stdc++.h>
  using namespace std;

  int main() {

    int N;
    cin>>N;
    int C;
    cin>>C;
    string S;
    cin>>S;
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++)
    {
      pair<int,int> temp;
      cin>>temp.first;
      cin>> temp.second;
      v.push_back(temp);
    }
    pair<int,int> curr=v[0];
    set<pair<int,int>> s(v.begin(),v.end());
    s.erase(curr);
    int cur_ind=0;
    for(auto i:S)
    {
      if(i=='A')
      {
        for(auto p:s)
        {
          if(p.first+curr.first==p.second+curr.second)
          {
            curr=p;
            s.erase(curr);
            break;
          }
        }
      }
      else if(i=='B')
      {
        for(auto p:s)
        {
          if(p.first+curr.first==p.second-curr.second)
          {
            curr=p;
            s.erase(curr);
            break;
          }
        }
      }
      else if(i=='C')
      {
        for(auto p:s)
        {
          if(p.first-curr.first==p.second+curr.second)
          {
            curr=p;
            s.erase(curr);
            break;
          }
        }
      }
      else if(i=='D')
      {
        for(auto p:s)
        {
          if(p.first-curr.first==p.second-curr.second)
          {
            curr=p;
            s.erase(curr);
            break;
          }
        }
      }
    }
    cout<<curr.first<<" "<<curr.second<<endl;
    

  }