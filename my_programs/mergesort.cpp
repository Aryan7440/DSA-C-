#include <iostream>
#include <vector>

using namespace std;

void merge_sort(int a[], int size_a, int b[], int size_b, int c[])   //arrays have to be sorted
{
    int size_c = size_a + size_b;
    int i = 0, j = 0, k = 0;
    while (i < size_a || j < size_b)
    {
        if (a[i] < b[j] || j == size_b)
        {
            c[k] = a[i];
            i++;
            k++;
            // cout << c[k - 1] << " ";
        }
        else if (b[j] < a[i] || i == size_a)
        {
            c[k] = b[j];
            j++;
            k++;
            // cout << c[k - 1] << " ";
        }
        else if(b[j]==a[i])
        {
            c[k]=b[j];
            j++;
            k++;
            // cout << c[k - 1] << " ";
            c[k]=a[i];
            k++;
            i++;
            // cout << c[k - 1] << " ";
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector <int> ans;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                cout<<i<<j<<endl;
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                cout<<i<<j<<endl;
                ans.push_back(nums2[j]);   
                j++;
            }
        }
        if(i<m)
        {
            cout<<i<<j<<endl;
            ans.push_back(nums1[i]);
            i++; 
        }
        else if(j<n)
        {
            cout<<i<<j<<endl;
            ans.push_back(nums2[j]);   
            j++;
        }
        // return ans;
        nums1=ans;
        
    }
    void diplay(vector<int> a,int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
};
int main()
{

    // int arr1[] = {0, 1, 2, 4, 17, 28,521,658};
    // int arr2[] = {5, 6, 7, 8, 9, 17,28,29,845,3569};
    // int arr3[(sizeof(arr1) + sizeof(arr2)) / 4];
    // merge_sort(arr1, sizeof(arr1) / 4, arr2, sizeof(arr2) / 4, arr3);
    // display(arr3, sizeof(arr3) / 4);
    vector<int>a={1,2,3};
    vector<int>b={2,5,6};
    Solution ans;
    ans.merge(a,3,b,3);
    // ans.diplay(a,6);

}