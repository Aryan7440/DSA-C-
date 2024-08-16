#include<bits/stdc++.h>
using namespace std;
string leftRotate(string str, int d) {
    string ans;
    int k=d%str.size();
    for (int i = k; i < str.size()+k; i++)
    {
        ans.push_back(str[i%str.size()]);
    }
    
    return ans;
}

string rightRotate(string str, int d) {
    string ans;
    d=d%str.size();
    for(int i=str.size()-d;i<(2*str.size())-d;i++)
    {
        ans.push_back(str[(i%str.size())]);
    }
    return ans;
}
int main()
{
    string s="CODINGNINJAS";
    cout<<s<<endl;
    cout<<leftRotate(s,13)<<endl;
    cout<<rightRotate(s,13)<<endl;
}