#include <bits/stdc++.h>
using namespace std;

// N: number
// find max( a1*a2*a3*a4...ai)
// a1+a2+a3+a4...ai = N
// a1,a2,a3,a4...ai >= 1

int partitionN(int N)
{
    // return util(N);
    vector<int> dp(N + 1, 0);
    dp[1] = 0;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        for (int k = 2; k <= i; k++)
        {
            dp[i] = max(dp[i], k * dp[i - k]);
        }
    }
    return dp[N];
}
int main()
{
    cout << partitionN(8) << endl;
    return 0;
}