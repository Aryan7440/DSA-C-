#include <bits/stdc++.h>
using namespace std;

vector<int> negative_first(vector<int> arr, int k)
{
    int i = 0;
    int j = -1;
    queue<int> neg;
    vector<int> ans;
    int n = arr.size();
    while (j < n)
    {

        if (j - i + 1 == k)
        {
            if (neg.empty())
                ans.push_back(0);
            else
                ans.push_back(neg.front());
            if (arr[i] < 0)
                neg.pop();
            i++;
            j++;
            if (arr[j] < 0)
            {
                neg.push(arr[j]);
            }
        }
        else
        {
            j++;
            if (arr[j] < 0)
            {
                neg.push(arr[j]);
            }
        }
    }
    return ans;
}
vector<int> firstNegative(vector<int> arr, int n, int k)
{
    vector<int> ans(n - k + 1);
    int idx = 0;

    int firstNegIndex = 0;

    // Traversing for every window's end.
    for (int end = k - 1; end < n; end++)
    {

        while (firstNegIndex < end && (firstNegIndex <= end - k || arr[firstNegIndex] >= 0))
        {
            firstNegIndex++;
        }

        // If we found a negative.
        if (arr[firstNegIndex] < 0)
        {
            ans[idx++] = arr[firstNegIndex];
        }
        else
        {
            ans[idx++] = 0;
        }
    }

    return ans;
}
void display(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 4, -5, -2, 8, 5, -3};
    display(firstNegative(arr,arr.size(), 3));
    // display(negative_first(arr, 3));
}