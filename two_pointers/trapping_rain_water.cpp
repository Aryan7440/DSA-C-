#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int l = 0, r = n - 1;
    int lmax = height[l], rmax = height[r];
    int water = 0;
    while (l <= r)
    {
        if (height[l] >= lmax)
        {
            lmax = height[l];
            l++;
        }
        else if (height[r] >= rmax)
        {
            rmax = height[r];
            r--;
        }
        else if (height[l] < lmax && lmax < rmax)
        {
            water += lmax - height[l];
            l++;
        }
        else
        {
            water += rmax - height[r];
            r--;
        }
    }
    return water;
}
int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights);
}