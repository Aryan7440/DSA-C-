
#include <bits/stdc++.h>
using namespace std;
#define ll long long

using namespace std;

int maximumLength(vector<int> &nums)
{
    unordered_map<double, int> A;
    for (auto it : nums)
        A[(double)it]++;
    vector<int> ns;
    for (auto i : A)
        ns.push_back(i.first);
    int res = 0;
    int ans = 0;
    for (auto it : ns)
    {
        if (it == 1)
            continue;
        int count = 1;
        double num = (double)it;
        if (A[num] >= 1)
        {
            double sq = sqrt(num);
            while (A[sq] >= 2)
            {
                count += 2;
                num = sqrt(num);
                sq = sqrt(num);
            }
        }
        ans = max(ans, count);
    }
    if (A[1] % 2 == 0)
        A[1]--;
    return max(A[1], ans);
}

int main()
{
    // Example usage:
    vector<int> nums = {1, 1};
    // vector<int> nums = {2, 4, 16, 2, 3, 3, 9, 9, 81, 81, 6561};
    int result = maximumLength(nums);
    cout << result << endl;
    // cout << sqrt(5);

    return 0;
}
