#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    // int n;
    // cin>>n;
    vector<int> nums = {0, 2, 3, -3, 5, -5};
    int n = nums.size();
    // unordered_map
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
                continue;
            int b = nums[j];
            for (int k = j + 1; k < n; k++)
            {
                if (i == j || j == k)
                    continue;
                int c = nums[k];
                if (a + b + c == 0)
                {
                    cout << a << " " << b << " " << c << endl;
                    // return 0;
                }
            }
        }
    }
    cout << "notFound" << endl;
}
// 0,2,3,-3,5  target=0// n^2
// -1,0,2,3,5  target=0/;