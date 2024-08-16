#include <iostream>
#include <vector>
using namespace std;
int firstIndex(vector<int> &nums, int target)
{
    int start = 0;
    int stop = nums.size() - 1;
    int mid = stop / 2;
    int res = -1;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            stop = mid - 1;
        }
        else if (nums[mid] > target)
            stop = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
    }
    return res;
}
int lastIndex(vector<int> &nums, int target)
{
    int start = 0;
    int stop = nums.size() - 1;
    int mid = stop / 2;
    int res = -1;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
            stop = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
    }
    return res;
}

int count(vector<int> &v, int target)
{
    return lastIndex(v, target) - firstIndex(v, target) + 1;
}

int main()
{
    vector<int> v = {1, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6};
    cout << firstIndex(v, 5) << endl;
    cout << lastIndex(v, 5) << endl;
    cout << count(v, 5) << endl;
}