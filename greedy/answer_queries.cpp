#include <bits/stdc++.h>
using namespace std;

vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    sort(nums.begin(), nums.end());
    sort(queries.begin(), queries.end());
    int i = 0, j = 0, k = 0;
    int sum = 0;
    int ans = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        while (k < queries.size() && sum > queries[k])
        {
            queries[k] = ans;
            k++;
        }
        if (sum <= queries[k])
            ans = j + 1;
        j++;
    }
    return queries;
}
int main()
{
    vector<int> nums = {4,5,2,1}, queries = {3,10,21};
    vector<int> ans=answerQueries(nums,queries);
    for(auto i:ans)cout<<i<<" ";
}