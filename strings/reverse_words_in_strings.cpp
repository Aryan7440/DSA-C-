#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int i = 0, j = 0;
    while (i < s.size() && j < s.size())
    {
        while (j < s.size() && s[j] != ' ')
            j++;
        reverse(s.begin() + i, s.begin() + j );
        j++;
        i=j;
    }
    return s;
}

int main()
{
    string s= "Let's take LeetCode contest";
    cout<<reverseWords(s);
}