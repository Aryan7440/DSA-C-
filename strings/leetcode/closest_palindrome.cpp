#include <bits/stdc++.h>
using namespace std;
string nearestPalindromic(string n)
{
    int s = n.size();
    long long N = stoll(n);
    long long upper = pow(10, s) + 1;
    long long lower = pow(10, s - 1) - 1;
    vector<long long> candidates;

    // string pre = (s % 2 == 0) ? n.substr(0, s / 2) : n.substr(0, s / 2 + 1);

    if (s % 2 == 0)
    {
        string pre = n.substr(0, s / 2);
        long long preN = stoll(pre);
        string pn1 = to_string(preN + 1);
        string pn2 = to_string(preN - 1);
        for (int i = pre.size() - 1; i >= 0; i--)
        {
            pre.push_back(pre[i]);
            pn1.push_back(pn1[i]);
            pn2.push_back(pn2[i]);
        }
        candidates = {upper, lower, stoll(pre), stoll(pn1), stoll(pn2)};
    }
    else
    {
        string pre = n.substr(0, s / 2 + 1);
        long long preN = stoll(pre);
        string pn1 = to_string(preN + 1);
        string pn2 = to_string(preN - 1);
        for (int i = pre.size() - 2; i >= 0; i--)
        {
            pre.push_back(pre[i]);
            pn1.push_back(pn1[i]);
            pn2.push_back(pn2[i]);
        }
        candidates = {upper, lower, stoll(pre), stoll(pn1), stoll(pn2)};
    }
    long long diff = INT32_MAX;
    long long curr = upper;
    for (auto i : candidates)
    {
        if (i == N)
            continue;
        if (diff > abs(i - N))
        {
            diff = abs(i - N);
            curr = i;
        }
        else if (diff == abs(i - N))
        {
            curr = min(curr, i);
        }
    }
    return to_string(curr);
}
int main()
{
    string n = "2147483647";
    int s = n.size();
    cout << nearestPalindromic(n);
    // string pre = (s % 2 == 0) ? n.substr(0, s / 2) : n.substr(0, s / 2 + 1);
    // cout << pre;
}