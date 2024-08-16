#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int> &nums)
    {
        K=k;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
                // return val;
            }
        }
    }

    int add(int val)
    {
        if(pq.size()<K)
        {
            pq.push(val);
            return pq.top();
        }

        if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        return pq.top();
    }
};
int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest *k = new KthLargest(3, nums);
    cout << k->add(3) << endl;
    cout << k->add(5) << endl;
    cout << k->add(10) << endl;
    cout << k->add(9) << endl;
    cout << k->add(4) << endl;
}