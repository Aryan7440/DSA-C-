#include <bits/stdc++.h>
using namespace std;
bool util(string s1, string s2, string s3, int i, int j, int k)
{
    if (k == s3.size() && i == s1.size() && j == s2.size())
        return true;
    // if (k == s3.size() || i == s1.size() || j == s2.size())
    //     return false;
    bool res = false;
    if (s1[i] == s3[k])
        res = res | util(s1, s2, s3, i + 1, j, k + 1);
    if (s2[j] == s3[k])
        res = res | util(s1, s2, s3, i, j + 1, k + 1);
    return res;
}
bool isInterleave(string s1, string s2, string s3)
{
    return util(s1, s2, s3, 0, 0, 0);
}
int main()
{
    string s1 = "a", s2 = "b", s3 = "a";
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout<<isInterleave(s1,s2,s3);
}