#include <bits/stdc++.h>
using namespace std;
vector<int> rabin_karp(string const &s, string const &t) // t=test and s=pattern
{
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    // hash the string
    // rolling hash
    // hash(s) = (s[0] + s[1]*p + s[2]*p^2 + ... + s[n-1]*p^(n-1) )mod m
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    // hash of prefix of t
    // to search pattern as substring
    // hash(i->j)=hash(j+1)-hash(i)*p^(j-i+1)
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0; // hash of pattern
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}
void count_unique_substrings(string const &s)
{
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;
    for (auto i : p_pow)
        cout << i << " ";
    cout << endl;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    for (auto i : h)
        cout << i << " ";
    cout << endl;
    int cnt = 0;
    for (int l = 1; l <= n; l++)
    {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++)
        {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    cout << cnt << endl;
}
int main(int argc, char const *argv[])
{
    // string s = "abc";
    string t = "bbcababcc";
    // vector<int> ans = rabin_karp(s, t);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    count_unique_substrings(t);
    return 0;
}
