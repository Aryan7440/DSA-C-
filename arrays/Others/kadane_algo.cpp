#include <iostream>
#include <limits.h>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;

    else
        return b;
}

void subarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

void subarray2(int arr[],int size)  //O(N^2)
{
    int sum=0;
    int max_sum=INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        sum=0;
        for (int j = i; j < size; j++)
        {
            sum+=arr[j];
            max_sum=max(max_sum,sum);
        }
        
    }
    cout<< max_sum;
}

int kadane(int *a, int size)
{
    int sum = 0, maxsum = a[0];//a[0] if all negative then print minimum
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        if (sum < 0)
        {
            maxsum = max(maxsum, sum);
            sum = 0;
        }
    }
    return maxsum;
    // if all negative
    // if circular array then  ans=total-(sum of longest negative array)
}
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{

    // int arr[] = {1, -2, -3, 4, -1, 2, 1};
    int arr[] = {-11, -23, -3, -4, -5, -6};

    cout<<kadane(arr,sizeof(arr)/sizeof(arr[0]));
    // subarray2(arr, sizeof(arr) / 4);
    // subarray(arr, sizeof(arr) / 4);
}