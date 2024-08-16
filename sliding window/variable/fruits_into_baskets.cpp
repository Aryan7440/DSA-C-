#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int max_fruits = 0;
    int i = 0, j = 0;
    unordered_map<int,int> s;
    while (j < fruits.size())
    {
        s[fruits[j]]++;
        while (s.size() > 2)
        {
            s[fruits[i]]--;
            if(s[fruits[i]]==0)s.erase(fruits[i]);
            i++;
        }
        max_fruits = max(max_fruits, j - i + 1);
        j++;
    }
    return max_fruits;
}
int main()
{
    vector<int> fruits={3,3,3,1,2,1,1,2,3,3,4};
    cout<<totalFruit(fruits);
}