#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{
private:
    vector<int> arr;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }
    bool insert(int val)
    {
        if (mp.find(val) == mp.end())
        {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {
            int ind = mp[val];
            mp[arr[arr.size() - 1]] = ind;
            swap(arr[arr.size() - 1], arr[ind]);
            arr.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int rand_ind = rand() % arr.size();
        return arr[rand_ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
    // srand(time(0));

    // for (int i = 0; i < 4; i++)
    //     cout << rand() << " ";
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(0) << endl;
    cout << obj->insert(1) << endl;
    cout << obj->remove(0) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->remove(1) << endl;
    cout << obj->getRandom() << endl;
    // cout << obj->remove(1) << endl;
    // cout << obj->insert(2) << endl;
    // cout << obj->getRandom() << endl;
}