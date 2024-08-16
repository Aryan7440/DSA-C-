#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
{
    int l = 0, r = 0;
    while (l < haystack.size())
    {
        if (haystack[l] == needle[r])
        {
            l++;
            r++;
        }
        else
        {
            l++;
            r = 0;
        }
        if (r == needle.size())
            return l - needle.size();
    }
    return -1;
}
int main()
{
    string haystack="hello",needle="ll";
    cout<<strStr(haystack,needle);
}