#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> v(100001, 0);
    int floor = arr.size() / 3;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (v[arr[i]] != -1)
        {
            v[arr[i]]++;
            if (v[arr[i]] > floor)
            {
                ans.push_back(arr[i]);
                v[arr[i]] = -1;
            }
        }
    }
    return ans;
    // return v;
}

int main()
{
    vector<int> a={4 ,4, 4, 4, 4};
    vector<int> fr=majorityElementII(a);
    for (int i = 0; i < fr.size(); i++)
    {
        cout<<fr[i]<<" ";
    }
    cout<<endl;
    
}

