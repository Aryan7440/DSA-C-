#include <bits/stdc++.h>
using namespace std;
// void UTIL(string &s, int ind, vector<string> &ans, int count, string ds, int curr)
// {
//     if (ds[ds.size()-2]=='0' && ds[ds.size()-1]!='.' && ds[ds.size()-3]=='.')
//         return;
//     if (count == 4)
//         return;
//     if (ind == s.size())
//     {
//         if (count == 3)
//             ans.push_back(ds);
//         return;
//     }
//     else
//     {
//         if (ds.size() != 0)
//         {
//             if (ds.back() != '.')
//                 UTIL(s, ind, ans, count + 1, ds + '.', 0);
//         }
//         if (curr * 10 + (s[ind] - '0') <= 255)
//         {
//             UTIL(s, ind + 1, ans, count, ds + s[ind], curr * 10 + (s[ind] - '0'));
//         }
//     }
// }
// vector<string> restoreIpAddresses(string s)
// {
//     vector<string> ans;
//     for (auto i : s)
//     {
//         if (i > '9' || i < '0')
//             return ans;
//     }
//     string ds;
//     UTIL(s, 0, ans, 0, ds, 0);
//     return ans;
// }
#include <bits/stdc++.h> 

void util(string s,int ind,int count,string ds,int curr,int dig,vector<string> &ans)
{
	if(dig==2 && curr<10)return;
	if(count==4)return;
	if(ind==s.size())
	{
		if(count==3)ans.push_back(ds);
		return;
	}
	else
	{
		if(ds.size()!=0)
		{
			if(ds.back()!='.')util(s,ind,count+1,ds+'.',0,0,ans);
		}
		if(curr*10+(s[ind]-'0')<=255)
		{
			util(s,ind+1,count,ds+s[ind],curr*10+(s[ind]-'0'),dig+1,ans);
		}
	}
}
vector<string> generateIPAddress(string s)
{
	vector<string> ans;
	string ds;
	util(s,0,0,ds,0,0,ans);
    return ans;
	// Write your code here
}

int main()
{
    string s = "101023";
    vector<string> ans = generateIPAddress(s);
    // vector<string> ans = restoreIpAddresses(s);
    for (auto i : ans)
        cout << i << endl;
}