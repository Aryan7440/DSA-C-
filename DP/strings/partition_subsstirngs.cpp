#include <bits/stdc++.h>
using namespace std;
bool isPower(int x, long long y)
{
    // logarithm function to calculate value
    float res1 = log(y) / log(x);
    return res1 == floor(res1);
}
long long util(string s, int ind)
{
    if (ind == s.size())
        return 0;
    if (s[ind] == '0')
        return INT_MAX - 1;
    long long num = 0;
    long long res = INT_MAX - 1;
    for (int i = ind; i < s.size(); i++)
    {
        num = num << 1;
        num = num | (s[i] == '1');
        if (isPower(5, num))
        {
            res = min(res, 1 + util(s, i + 1));
        }
    }
    return res;
}
int minimumBeautifulSubstrings(string s)
{
    return util(s, 0);
}
int main()
{
    string s = "1011";
    cout << minimumBeautifulSubstrings(s);
    // int num=0;
    // for(auto i:s)
    // {
    //     num=num<<1;
    //     num=num|(i=='1');
    //     cout<<num<<endl;


    // }
}