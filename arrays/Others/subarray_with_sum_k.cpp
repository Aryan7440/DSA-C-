// #include <iostream>
// using namespace std;
// #include <vector>
// #include <limits.h>

// int max_subarray(vector<int> a, int k)
// {
//     int i = 0, j = 0, sum = 0, len = INT_MIN;
//     while (j < a.size())
//     {
//         sum = sum + a[j];
//         // maxlen=max(maxlen,len);
//         if (sum == k)
//         {
//             len = max(len, j - i + 1);
//             j++;
//         }
//         else if (sum < k)
//         {
//             j++;
//         }
//         else if (sum > k)
//         {
//             // sum=sum-a[i];
//             // i++;
//             while (sum > k)
//             {
//                 sum = sum - a[i];
//                 i++;
//                 if (sum == k)
//                 {
//                     len = max(len, j - i + 1);
//                 }
//                 j++;
//             }
//         }

//         // j++;
//     }
//     return len;
// }
// int main()
// {
//     vector<int> a = {1,1,4,2,3};
//     cout << max_subarray(a, 5);
// }

// C++ implementation to find the length
// of longest subarray having sum k
#include <bits/stdc++.h>
using namespace std;

// function to find the length of longest
// subarray having sum k
int lenOfLongSubarr(int A[], int N, int K)
{
    int total=0;
    for (int i = 0; i < N; i++)
    {
        total+=A[i];
    }
    K=total-K;
    

	int i = 0, j = 0, sum = 0;
	int maxLen = INT_MIN;

	while (j < N) {
		sum += A[j];
		if (sum < K) {
			j++;
		}
		else if (sum == K) {
			maxLen = max(maxLen, j-i+1);
			j++;
		}
		else if (sum > K) {
			while (sum > K) {
				sum -= A[i];
				i++;
			}
			if(sum == K){
			maxLen = max(maxLen, j-i+1);
			}
			j++;
		}
	}
	return N-maxLen;
}

// Driver Code
int main()
{
	int arr[] = { 1,1,4,2,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	cout << "Length = " << lenOfLongSubarr(arr, n, k);
	return 0;
}

