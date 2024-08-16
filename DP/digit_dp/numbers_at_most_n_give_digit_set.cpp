#include <bits/stdc++.h>
using namespace std;
unordered_set<int> st;
int help(string &num, int ind, int tight, int flag, vector<vector<vector<int>>> &dp)
{
    if (ind == num.size())
        return flag != 0;
    if (dp[ind][tight][flag] != -1)
        return dp[ind][tight][flag];
    int limit = tight ? num[ind] - '0' : 9;
    int res = 0;
    for (int i = 0; i <= limit; i++)
    {
        if ((flag == 0 && i == 0) || st.find(i) != st.end())
        {
            res += help(num, ind + 1, tight && i == limit, flag || st.find(i) != st.end(), dp);
        }
    }
    return dp[ind][tight][flag] = res;
}
int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    for (auto i : digits)
        st.insert(i[0] - '0');
    string num = to_string(n);
    vector<vector<vector<int>>> dp(num.size(), vector<vector<int>>(2, vector<int>(2, -1)));

    return help(num, 0, 1, 0, dp);
}
int main()
{
    vector<string> digits={"1","4","9"};
    // vector<string> digits={"1","3","5","7"};
    cout<<atMostNGivenDigitSet(digits,1000000000);

}