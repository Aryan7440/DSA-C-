#include <bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int l = 0, r = -1;
    int n = people.size();
    int sum = 0;
    int ans = 0;
    while (l < n && r < n)
    {
         while (sum < limit && r < n)
        {
            r++;
            sum += people[r];
        }
        ans++;
        sum=0;
        l=r;
    }
    
    return ans;
}
int main()
{
    vector<int>people={3,5,3,4};
    cout<<numRescueBoats(people,5);
    // vector<int>people={3,2,2,1};
    // cout<<numRescueBoats(people,3);
}