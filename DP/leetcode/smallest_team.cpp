#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &peoples, int ind, int bit, vector<vector<int>> &dp,vector<vector<int>> &choice,int t)
{
    int n = peoples.size();
    int target = (1 << t) - 1;
    if (ind == n)
    {
        if (bit == target)
        {
            return 0;
        }
        return 1e6;
    }

    if (dp[ind][bit] != -1)
        return dp[ind][bit];
    int temp = bit | peoples[ind];
    int take=1e6;
    if(temp>bit) take = 1 + util(peoples, ind + 1, temp, dp,choice,t);
    
    int dont_take = util(peoples, ind + 1, bit, dp,choice,t);
    if(take<dont_take)
    {
        choice[ind][bit]=1;
    }
    return dp[ind][bit] = min(take, dont_take);
}
vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
{
    int bit = 0;
    unordered_map<string, int> mp;
    int t = req_skills.size();
    for (int i = 0; i < t; i++)
    {
        mp[req_skills[i]] = i;
    }
    int n=people.size();
    vector<int> peoples(n,0);
    for (int i = 0; i < people.size(); i++)
    {
        int temp = 0;
        for (auto s : people[i])
        {
            temp |= 1 << mp[s];
        }
        peoples[i] = temp;
    }
    vector<vector<int>> dp(n, vector<int>((1 << n) + 1, -1));
    vector<vector<int>> choice(n, vector<int>((1 << n) + 1, -1));
    vector<int> ans;
    util(peoples, 0, 0, dp,choice,t);

    int mask = 0;
        for(int i = 0; i<n; i++)
        {
            if(choice[i][mask] == 1)
            {
                // If the person was included at that particular point, we need to include him in the current answer
                ans.push_back(i);
                // Changing the mask including the current person skills as well
                mask = mask| peoples[i];
            }
            // As soon as we get the required mask, we break
            if(mask == (1<<t)-1){
                break;
            }
        }
        return ans;
}
int main()
{
    vector<string> req_skills = {"mmcmnwacnhhdd", "vza", "mrxyc"};
    // vector<string> req_skills = {"algorithms","math","java","reactjs","csharp","aws"};
    // vector<string> req_skills = {"java", "nodejs", "reactjs"};
    vector<vector<string>> people = {{"mmcmnwacnhhdd"}, {}, {}, {}, {"vza", "mrxyc"}};
    // vector<vector<string>> people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
    vector<int> ans1 = smallestSufficientTeam(req_skills, people);
    for (auto i : ans1)
        cout << i << endl;
    // cout<<smallestSufficientTeam(req_skills,people);
}