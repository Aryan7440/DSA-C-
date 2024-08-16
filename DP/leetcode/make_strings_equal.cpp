#include <bits/stdc++.h>
using namespace std;
int util(string s1, string s2, int x, int ind)
{
    if (s1 == s2)
        return 0;
    if (ind >= s1.size())
        return 1e6;
    if (s1[ind] == s2[ind])
        return util(s1, s2, x, ind + 1);
    int res1 = 1e6;
    if (ind + 1 < s1.size())
    {
        s1[ind] = s1[ind] == '1' ? '0' : '1';
        s1[ind + 1] = s1[ind + 1] == '1' ? '0' : '1';
        res1 = 1 + util(s1, s2, x, ind + 1);
        s1[ind] = s1[ind] == '1' ? '0' : '1';
        s1[ind + 1] = s1[ind + 1] == '1' ? '0' : '1';
    }
    int res2 = 1e6;
    s1[ind] = s1[ind] == '1' ? '0' : '1';
    for (int i = ind + 1; i < s1.size(); i++)
    {
        s1[i] = s1[i] == '1' ? '0' : '1';
        res2 = min(res2, x + util(s1, s2, x, ind + 1));
        s1[i] = s1[i] == '1' ? '0' : '1';
    }
    return min(res1, res2);
}
int minOperations(string s1, string s2, int x)
{

    return util(s1, s2, x, 0);
}
int main()
{
    string s1 = "1100011000", s2 = "0101001010";
    int x = 2;
    cout << minOperations(s1, s2, 2);
}