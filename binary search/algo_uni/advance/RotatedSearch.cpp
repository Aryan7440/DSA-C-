#include <bits/stdc++.h>
using namespace std;
bool Predicate(vector<int> &arr, int ind)
{
    if (arr[ind] < arr[0])
        return 1;
    else
        return 0;
}
int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int l = -1, r = n;
    int mid = l + (r - l) / 2;
    while (l + 1 < r)
    {
        mid = l + (r - l) / 2;
        if (Predicate(nums, mid))
            r = mid;
        else
            l = mid;
    }
    if (r >= n)
        cout << nums[0] << endl;
    else
        cout << nums[r] << "\n";

    return 0;
}