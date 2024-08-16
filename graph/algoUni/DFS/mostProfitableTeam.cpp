#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> &emp, vector<int> &pro, int e, vector<int> &ans)
{
    if (emp[e] == 0)
        return ans[e] = pro[e];
    return ans[e] = pro[e] + dfs(emp, pro, emp[e], ans);
}
int main()
{

    int n;
    cin >> n;
    vector<int> emp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        emp[boss] = i;
    }
    vector<int> pro(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> pro[i];
    vector<int> ans(n + 1);
    dfs(emp, pro, 1, ans);
    // int res=INT_MIN;
    // for(int i=1;i<=n;i++)res=max(res,ans[i]);
    // cout<<res<<endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}