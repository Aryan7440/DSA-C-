#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) == mp.end())
        {
            mp[val].insert(arr.size());
            arr.push_back(val);
            return true;
        }
        mp[val].insert(arr.size());
        arr.push_back(val);
        return false;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {
            int ind = *mp[val].begin();
            mp[val].erase(mp[val].begin());
            if (mp[val].size() == 0)
            {
                mp.erase(val);
            }
            if (ind != arr.size() - 1)
            {
                mp[arr[arr.size() - 1]].erase(arr.size() - 1);
                mp[arr[arr.size() - 1]].insert(ind);
            }
            swap(arr[ind], arr[arr.size() - 1]);
            arr.pop_back();
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
    RandomizedCollection *obj = new RandomizedCollection();
    cout << obj->insert(1) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->insert(1) << endl;
}