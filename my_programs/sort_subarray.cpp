#include <iostream>
#include <vector>
using namespace std;
int findUnsortedSubarray(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;

    int flag1 = 0, flag2 = 0;
    while ((i < j) && (flag1 == 0 || flag2 == 0))
    {
        if (flag1 == 0)
        {
            if (nums[i] > nums[i + 1])
            {
                flag1 = 1;
            }
            if (nums[i] == nums[i + 1])
            {
                int k = 0;
                while (nums[i] != nums[i + 1])
                {
                    k++;
                    i++;
                }
                if (nums[i] > nums[i + 1])
                {
                    flag1 = 1;
                    i = i - k;
                }
            }

            else
            {
                i++;
            }
        }
        if (flag2 == 0)
        {
            if (nums[j] < nums[j - 1])
            {
                flag2 = 1;
            }
            if (nums[j] == nums[j - 1])
            {
                int l = 0;
                while (nums[j] != nums[j - 1])
                {
                    l++;
                    j--;
                }
                if (nums[j] < nums[j - 1])
                {
                    flag2 = 1;
                    j = j + l;
                }
            }

            else
            {
                j--;
            }
        }
    }
    if (i == j)
        return 0;
    else
        return (j - i + 1);
}

int main()
{
    vector<int> a = {2, 4, 6, 9, 8, 7, 8, 9, 10};
    cout << findUnsortedSubarray(a);
}
