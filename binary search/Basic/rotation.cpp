#include <iostream>
#include <vector>
using namespace std;

// int rotation(vector<int> v)
// {
//     int start = 0;
//     int stop = v.size() - 1;
//     int n = stop;
//     if (n == 0)
//         return n;
//     int mid = (stop - start) / 2;
//     while (start <= stop)
//     {
//         mid = start + (stop - start) / 2;
//         if (v[mid] < v[(mid - 1 + n) % n])
//         {
//             return mid;  //return n-mid   if left rotated
//         }
//         else if (v[mid] > v[stop])
//         {
//             start = mid + 1;
//         }
//         else // if(v[mid]<v[start])  //already soterd already invluded
//         {
//             stop = mid - 1;
//         }
//     }
//     return start;
// }
// //after that u can search in 1st part and last part
// // target>=arr[0]( first array)
// // targrt<arr[0]  (second array)

// bool search(vector<int>& nums, int target)
//     {
//         int start,stop;
//         if(target<nums[0])
//         {
//             start=rotation(nums);
//             stop=nums.size()-1;
//         }
//         else
//         {
//             start=0;
//             stop=rotation(nums)-1;
//         }
//         int mid=(stop-start)/2;
//         while(start<=stop)
//         {
//             mid=start+(stop-start)/2;
//             if (nums[mid]==target) return true;
//             else if(nums[mid]>target)stop=mid-1;
//             else start=mid+1;
//         }
//         return false;

//     }

// int rotate(vector<int> &nums)
// {
//     int start = 0;
//     int stop = nums.size() - 1;
//     int size = stop+1;
//     int mid = (stop - start) / 2;

//     // while(nums[start]==nums[mid])
//     // {
//     //     start++;
//     // }
//     // while(nums[stop]==nums[mid])
//     // {
//     //     stop--;
//     // }

    
//     while (start <= stop)
//     {
        
//         while(nums[start]==nums[stop] && start<stop)start++;
//         // while(nums[stop]==nums[start] && stop>start)stop--;
//         mid = start + (stop - start) / 2;
//         if (nums[mid] < nums[(mid - 1 + size) % size])
//             return mid;
//         else if (nums[mid] > nums[stop])
//             start = mid + 1;
//         else
//             stop = mid - 1;
//     }
//     return start;
// }
// bool search(vector<int> &nums, int target)
// {
//     int start, stop;
//     if(rotate(nums)==0)
//     {
//         start=0;
//         stop=nums.size()-1;
//     }
//     else if (target < nums[0])
//     {
//         start = rotate(nums);
//         stop = nums.size() - 1;
//     }
//     else
//     {
//         start = 0;
//         stop =rotate(nums) - 1;
//     }
//     int mid = (stop - start) / 2;
//     while (start <= stop)
//     {
//         mid = start + (stop - start) / 2;
//         if (nums[mid] == target)
//             return true;
//         else if (nums[mid] > target)
//             stop = mid - 1;
//         else
//             start = mid + 1;
//     }
//     return false;
// }


bool binary_Search(vector<int> &nums,int target)
{
    int start=0;
    int stop=nums.size()-1;
    int mid;
    while(start<=stop)
    {
        mid=start+(stop-start)/2;
        if(nums[mid]==target)return true;
        if((nums[start]==nums[mid])&& (nums[stop]==nums[mid])) //use if
        {
            start++;
            stop--;
        }
        else if(nums[mid]>=nums[start])//usr else if with >=
        {
            if (nums[mid]>target && nums[start]<=target)
            {
                stop=mid-1;
            }
            else
            {
                start=mid+1;
            }
            
        }
        else
        {
            if(nums[mid]<target && nums[stop]>=target)
            {
                start=mid+1;
            }
            else
            {
                stop=mid-1;
            }
        }

    }
    return false;
}




int main()
{
    vector<int> v = {1,1,1,1,1,1,2,1,1};

    // cout << rotate(v);
    cout << binary_Search(v, 2);
}