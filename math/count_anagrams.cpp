// binary exponentiation
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int fact[100002];
    int MUL(int a, int b)
    {
        return ((long long)(a % mod) * (long long)(b % mod)) % mod;
    }
    int BinExpo(int a, int m)
    {
        if (m == 0)
            return 1;
        int res = BinExpo(a, m / 2);
        res = MUL(res, res);
        return (m % 2 == 0) ? res : MUL(res, a);
    }
    int MULI(int a)
    {
        return BinExpo(a, mod - 2);
    }
    void factorial()
    {
        fact[0] = 1;
        for (int i = 1; i < 100001; i++)
            fact[i] = MUL(fact[i - 1], i);
    }
    int countAnagrams(string s)
    {
        factorial();
        int n = s.size();
        int ans = 1;
        int i = 0;
        while (i < n)
        {
            unordered_map<char, int> mp;
            int count = 0;
            while (i < n && s[i] != ' ')
            {
                count++;
                mp[s[i]]++;
                i++;
            }
            int num = fact[count];
            int den = 1;
            for (auto i : mp)
            {
                den = MUL(den, fact[i.second]);
            }
            int total = MUL(num, MULI(den));
            ans = MUL(ans, total);
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "too hot";
    cout << sol.countAnagrams(s) << endl;
}