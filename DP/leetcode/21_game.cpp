#include <bits/stdc++.h>
using namespace std;
double new21Game(int n, int k, int maxPts)
{
    vector<double> probability(k + maxPts, 0);
    probability[0] = 1.0;
    // for (int i = 1; i <= k + maxPts; i++)
    // {
    //     for(int j=1;j<=maxPts;j++)
    //     {
    //         if(i-j>=0 && i-j<k)probability[i]+=probability[i-j]/maxPts;;
    //     }
    // }
    // double ans = 0.0;
    // for (int i = k; i <= n; i++)
    // {
    //     ans += probability[i];
    // }
    // return ans;

    double window_sum=1;
    double ans=0.0;
    for(int i=1;i<=n;i++)
    {
        probability[i]=window_sum/maxPts;
        if(i<k)window_sum=window_sum+probability[i];
        else ans+=probability[i];

        if(i>=maxPts)window_sum=window_sum-probability[i-maxPts];
    }
    return ans;


}
int main()
{
    cout << new21Game(21, 17, 10);
}