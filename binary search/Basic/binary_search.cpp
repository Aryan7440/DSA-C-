#include <iostream>
#include <vector>
using namespace std;

bool binary(vector<vector<int>> &matrix, int start, int end, int target)
{
    if (start > end)
        return false;
    else if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
        {
            return true;
        }
        else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] > target)
        {
            return binary(matrix, start, mid - 1, target);
        }
        else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
        {
            return binary(matrix, mid + 1, end, target);
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    return binary(matrix, 0, matrix.size() * matrix[0].size() - 1, target);
}

int searchInsert(vector<int> &nums, int target)
{
    int start = 0;
    int stop = nums.size() - 1;
    int mid = stop / 2;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            stop = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
    }
    return start;
}

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
            stop=mid-1;
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
            start=mid+1;
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
    return lastIndex(v,target)-firstIndex(v,target)+1;
}

int main()
{
    // vector<vector<int>> v1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // cout << searchMatrix(v1, 305);
    vector<int> v = {1, 3, 5,5,5,5,5,5,5,5,5,5, 6};
    // cout << searchInsert(v, 7);
    cout << firstIndex(v, 5)<<endl;
    cout << lastIndex(v, 5)<<endl;
    cout << count(v,5)<<endl;
}