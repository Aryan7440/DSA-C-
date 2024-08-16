#include<bits/stdc++.h>
using namespace std;

bool reg(string s)
{
    int i=0;
    while(s[i]!='b')
    {
        if(s[i]!='a')return false;
        i++;
    }
    while(i<s.size())
    {
        if(s[i]!='b')return false;
        i++;
    }
    return true;
}

int main()
{
    string s="b";
    cout<<reg(s);
}