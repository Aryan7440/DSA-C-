#include <bits/stdc++.h>
using namespace std;
int DivSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    // Test Case 1: Empty sequence
    vector<int> nums1;
    cout << "Test Case 1: ";
    cout << DivSubsequence(nums1) << endl;

    // Test Case 2: Sequence with only one element
    vector<int> nums2 = {5};
    cout << "Test Case 2: ";
    cout << DivSubsequence(nums2) << endl;

    // Test Case 3: Sequence with all positive elements
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: ";
    cout << DivSubsequence(nums3) << endl;

    // Test Case 4: Sequence with all negative elements
    vector<int> nums4 = {-1, -2, -3, -4, -5};
    cout << "Test Case 4: ";
    cout << DivSubsequence(nums4) << endl;

    // Test Case 5: Sequence with both positive and negative elements
    vector<int> nums5 = {-1, 2, -3, 4, -5};
    cout << "Test Case 5: ";
    cout << DivSubsequence(nums5) << endl;
}