#include<bits/stdc++.h>
using namespace std;

bool expression(string s)
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
    string s;
    cin>>s;
    if(expression(s))cout<<"It is of the form a*b+"<<endl;
    else cout<<"It is not of the form a*b+"<<endl;
}