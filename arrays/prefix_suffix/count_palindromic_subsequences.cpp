#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int ADD(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }
    int MUL(int a, int b)
    {
        return ((long long)(a % mod) * (b % mod)) % mod;
    }
    int left[10005][10][10] = {0};
    int right[10005][10][10] = {0};
    int countPalindromes(string s)
    {
        int n = s.size();
        int freq[10] = {0};
        freq[s[0] - '0']++;
        for (int i = 1; i < s.size(); i++)
        {
            for (int a = 0; a < 10; a++)
            {
                for (int b = 0; b < 10; b++)
                {
                    left[i][a][b] = left[i - 1][a][b];
                    if (b == s[i] - '0')
                        left[i][a][b] = ADD(left[i][a][b], freq[a]);
                }
            }
            freq[s[i] - '0']++;
        }
        int freq2[10] = {0};
        // int right[n][10][10] = {0};
        freq2[s[n - 1] - '0']++;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int a = 0; a < 10; a++)
            {
                for (int b = 0; b < 10; b++)
                {
                    right[i][a][b] = right[i + 1][a][b];
                    if (a == s[i] - '0')
                        right[i][a][b] = ADD(right[i][a][b], freq2[b]);
                }
            }
            freq2[s[i] - '0']++;
        }
        int count = 0;
        for (int i = 2; i < n - 2; i++)
        {
            for (int a = 0; a < 10; a++)
            {
                for (int b = 0; b < 10; b++)
                {
                    count = ADD(count, MUL(left[i - 1][a][b], right[i + 1][b][a]));
                }
            }
        }
        return count;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution *sol = new Solution;
    cout << sol->countPalindromes(s);
}