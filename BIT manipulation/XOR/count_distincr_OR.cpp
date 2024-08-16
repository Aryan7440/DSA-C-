#include <bits/stdc++.h>
using namespace std;

int countDistinctBitwiseOR(vector<int> &inputVector, int size)
{
    // Write your code here.
    int b;
    unordered_set<int> set;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        int b = 0;
        for (int j = i; j < size; j++)
        {
            b = b | inputVector[j];
            set.insert(b);
        }
    }
    return set.size();
}
// int subarrayBitwiseOR(vector<int> &A)
// {

//     // res contains distinct values
//     unordered_set<int> res;

//     unordered_set<int> pre;
//     pre.insert(0);

//     for (int x : A)
//     {
//         unordered_set<int> temp;
//         for (int y : pre)
//         {
//             temp.insert(x | y);
//         }
//         temp.insert(x);
//         pre = temp;
//         res.insert(pre.begin(), pre.end());
//     }

//     return res.size();
// }
int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> pre,res;
        pre.insert(0);

        for(auto i:arr)
        {
            unordered_set <int> temp;
            for(auto j:pre)
            {
                temp.insert(i|j);
            }
            temp.insert(i);
            pre=temp;
            res.insert(pre.begin(),pre.end());
        }
        return pre.size();
    }

int main()
{
    vector<int> inputVector = {1, 1, 2};
    // vector<int> inputVector={10 ,2 ,12, 3, 8, 4 ,3 ,17, 4 ,13, 15};
    // cout<<countDistinctBitwiseOR(inputVector,inputVector.size());
    cout << subarrayBitwiseORs(inputVector);
}