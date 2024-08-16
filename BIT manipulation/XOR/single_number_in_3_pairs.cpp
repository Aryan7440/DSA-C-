#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    long long pow = 1;

    for (int i = 0; i < 32; i++)
    {
        if (i != 0)
            pow = pow * 2;
        long long count = 0;
        for (auto num : nums)
        {
            count += ((1 << i) & num);
        }
        if (count % 3 != 0)
            ans += pow;
    }
    return ans;
}
int main()
{
    vector<int> nums={1,1,1,5,6,7,7,6,5,4,4,4,6,5,7,9};
    cout<<singleNumber(nums);
}