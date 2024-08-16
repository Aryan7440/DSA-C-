#include <bits/stdc++.h>
using namespace std;

int atoi_(string str, int i)
{
    if(str[i]=='-')
    {
        return 0;
    }

    if (i == 0)
    {
        return (str[i] - '0');
    }
    return atoi_(str, i - 1) * 10 + (str[i] - '0');
}
int myAtoi(string s)
{
    if (s[0] == '-')
    {
        return -(atoi_(s, s.length() - 1));
    }

    return atoi_(s, s.length() - 1);
}

int main()
{
    // string s = "-12323";
    // cout << myAtoi(s);
    char a='3';
    int b=a-'0';
    cout<<b<<endl;
    
}