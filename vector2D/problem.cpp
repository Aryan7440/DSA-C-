#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    vector<int> ans;
    // for (auto i = nums.begin(); i !=nums.end(); i++)
    // {
    //     if (*i%2==0)
    //     {
    //         ans.insert(ans.begin(),*i);

    //     }
    //     else
    //     {
    //         ans.push_back(*i);

    //     }

    // }

    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] % 2 == 0)
    //         ans.insert(ans.begin(), nums[i]);
    //     else
    //         ans.push_back(nums[i]);
    // }
    // return ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
        }
    }
    return nums;
}

int main()
{
    vector<int> a = {2, 24, 5323, 11, 414, 6, 737, 7};
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // a.insert(a.begin(), 8);
    // a.insert(a.begin(), 7);
    // for (auto i = a.begin(); i != a.end(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout<<endl;
    // a.erase(a.begin()+1);
    vector<int> ans = sortArrayByParity(a);

    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}