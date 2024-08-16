#include <bits/stdc++.h>
using namespace std;
vector<double> medianSlidingWindow(vector<int> &nums, int k)
{
    multiset<double, greater<double>> Max;
    multiset<double> Min;
    int l = 0, r = 0;
    int n = nums.size();
    vector<double> median;
    while (r < n)
    {
        while (r - l + 1 <= k)
        {
            double L = (Max.empty()) ? 0 : *(Max.begin());
            double R = (Min.empty()) ? 0 : *(Min.begin());

            double num = nums[r];

            if (num < L)
                Max.insert(num);
            else
                Min.insert(num);

            while (Min.size() < Max.size())
            {
                double m = *(Max.begin());
                Min.insert(m);
                Max.erase(Max.find(m));
            }
            while (Max.size() < Min.size())
            {
                double m = *(Min.begin());
                Max.insert(m);
                Min.erase(Min.find(m));
            }
            r++;
        }
        double lm = (Max.empty()) ? 0 : *(Max.begin());
        double rm = (Min.empty()) ? 0 : *(Min.begin());
        double mid = ((Max.size() + Min.size()) % 2 == 0) ? (double)(lm + rm) / 2 : lm;
        median.push_back(mid);

        double num = nums[l];
        if (num > mid)
        {
            Min.erase(Min.find(num));
            // Min.insert(*Max.begin());
            // Max.erase(*Max.begin());
        }
        else
        {
            Max.erase(Max.find(num));
        }
        while (Min.size() < Max.size())
        {
            double m = *(Max.begin());
            Min.insert(m);
            Max.erase(Max.find(m));
        }
        while (Max.size() < Min.size())
        {
            double m = *(Min.begin());
            Max.insert(m);
            Min.erase(Min.find(m));
        }
        l++;
    }
    return median;
}

int main()
{
    // vector<int> nums = {2147483647, 1, 2, 3, 4, 5, 6, 7, 2147483647};
    // vector<double> ans = medianSlidingWindow(nums, 2);
    // vector<int> nums = {6, 5, 9, 5, 4, 9, 1, 7, 5, 5};
    // vector<double> ans = medianSlidingWindow(nums, 4);
    // vector<int> nums = {1, 2, 4,3};
    // vector<double> ans = medianSlidingWindow(nums, 4);
    // vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    // vector<double> ans = medianSlidingWindow(nums, 3);
    // for (auto i : ans)
    //     cout << i << " ";
    // cout << endl;
    multiset<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);
    // cout<<*(set.begin()+1);
    auto it=set.begin();
    // cout<<*(it+1);
}