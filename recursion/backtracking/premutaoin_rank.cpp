#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
    string ans = "";
    vector<int> fac(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    int rank = 0;
    unordered_set<char> set;
    for (int i = 1; i <= n; i++)
    {
        for (char num = '1'; num <= to_string(n)[0]; num++)
        {
            if (set.find(num) != set.end())
                continue;
            if (rank + fac[n - i] >= k)
            {
                ans.push_back(num);
                set.insert(num);
                break;
            }
            rank = rank + fac[n - i];
        }
    }
    return ans;
}
int main()
{
    cout << getPermutation(4, 4);
}