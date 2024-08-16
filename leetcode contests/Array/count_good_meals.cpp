#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &deliciousness)
{
    int n = deliciousness.size();
    int mod = 1e9 + 7;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[deliciousness[i]]++;
    sort(deliciousness.begin(), deliciousness.end());
    int M = deliciousness[n - 1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num = deliciousness[i];
        mp[deliciousness[i]]--;
        for (int j = 1; j <= 2*M; j = j * 2)
        {
            int num2=(j-num);
            if (mp[num2]>0)
            {
                ans = (ans + mp[num2] % mod) % mod;
            }
        }
        
    }
    return ans;
}
int main()
{
    // vector<int> deliciousness = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
    vector<int> deliciousness = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64};
    // vector<int> deliciousness = {1,1,1,3,3,3,7};
    // vector<int> deliciousness = {1, 3, 5, 7, 9};
    cout << countPairs(deliciousness);
}