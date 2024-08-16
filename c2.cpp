#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve()
{
    long long n,x,y;
    cin >> n >> x >> y;
    vector<long long> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    unordered_map<unordered_map<long long,long long>,long long> mp;
    for(int i=0;i<n;i++)
    {
        int a=x-(v[i]%x);
        int b=y-(v[i]%y);
    }


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
