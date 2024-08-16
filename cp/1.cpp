#include <bits/stdc++.h>
using namespace std;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		
		vector<int> recent;
		for (int i = 0; i < m; i++)
		{
			int temp;
			cin >> temp;
			recent.push_back(temp);
		}
		
		list<int> l;
		for (int i = 1; i <= n; i++)
			l.emplace_back(i);
		unordered_set<int> set(l.begin(),l.end());
		vector<int> ans(n);
		
		for(auto i:recent)
		{
			// if(set.find())
		}

	}
	return 0;
}
