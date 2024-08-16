#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int> &hand, int groupSize)
{
    unordered_map<int, int> set;
    for (auto i : hand)
    {
        set[i]++;
    }
    while (!set.empty())
    {
        int k = groupSize;
        int num = set.begin()->first;
        int l = 0;
        while (k--)
        {
            if (set.find(num + l) != set.end())
            {
                set[num + l]--;
                if (set[num + l] == 0)
                    set.erase(num + l);
            }
            else
                return false;
        }
    }
    return true;
}
int main()
{
    vector<int> hands={1,2,3,6,2,3,4,7,8};
    cout<<isNStraightHand(hands,3);
}