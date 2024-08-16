#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memPalindrome(string &s)
{
    int n = s.size();
    vector<vector<int>> isPalindrome(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j += i + 1)
        {
            int l = j - i;
            int r = j;
            if (l > r)
            {
                isPalindrome[l][r] = 1;
            }
            else if (s[l] == s[r])
            {
                isPalindrome[l][r] = isPalindrome[l + 1][r - 1];
            }
            else
            {
                isPalindrome[l][r] = 0;
            }
        }
    }
    return isPalindrome;
}

int main()
{
    string s = "sbsbs";
}