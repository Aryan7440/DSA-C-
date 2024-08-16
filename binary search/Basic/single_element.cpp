#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int stop = nums.size() - 1;
    if (stop == 0)
        return nums[0];
    int mid = (stop - start) / 2;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }
        else if ((mid % 2 == 0 && nums[mid] != nums[mid + 1]) || (mid % 2 != 0 && nums[mid] != nums[((mid - 1 + nums.size()) % nums.size())]))
            stop = mid - 1;
        else
            start = mid + 1;
    }
    return nums[mid];
}

int main()
{
    vector<int> a = {1,1, 2, 2, 3,4,4};
    cout << singleNonDuplicate(a);
}