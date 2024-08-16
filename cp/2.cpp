#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> c;
        for (int i = 0; i < 2 * n; i++)
        {
            int temp;
            cin >> temp;
            c.push_back(temp);
        }

        int flag = 0;
        unordered_map<int,int> mp;
        for (auto i : c)
        {
            mp[i]++;
            if (mp[i] > 2)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}