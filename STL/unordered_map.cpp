#include <bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<int,int> mp;
    vector<int> arr={1,3,5,6,1,5,8,5,5,};
    for (auto i:arr)
    {
        mp[i]++;
    }
    for(auto i:mp)
    {
        cout<<i.first<<"--"<<i.second<<endl;
    }
    cout<<endl;
    
    for(auto i:mp)
    {
        cout<<i.first<<"--"<<i.second<<endl;
    }
    auto it=mp.find(5);
    cout<<(*it).second<<endl;
    auto a=mp.find(5);
    cout<<(*a).second<<endl;
    // auto a=mp.find(78);
    if(mp.find(78)==mp.end())cout<<"Aevav";
    // cout<<mp.size()<<endl;
    // mp.clear();
    // mp.erase(8);
    // mp.erase(6);
    // mp.erase(5);
    // mp.erase(3);
    // mp.erase(1);
    // cout<<mp.size()<<endl;

    // cout<<mp.co
    

}