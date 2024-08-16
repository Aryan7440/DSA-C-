#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool func(Item i, Item j)
{
    double a = (double)i.value / (double)i.weight;
    double b = (double)j.value / (double)j.weight;

    if (a > b)
        return true;
    return false;
}
double fractionalKnapsack(int W, vector<Item> &v, int n)
{
    sort(v.begin(), v.end(), func);
    double ans = 0;
    double w = 0;
    for (auto i : v)
    {
        if (i.weight > (W - w))
        {
            ans = ans + (W - w) * ((double)i.value / (double)i.weight);
            return ans;
        }
        else
        {
            w = w + i.weight;
            ans = ans + i.value;
        }
    }
    return ans;
}

int main()
{
    // vector<int> weight = {
    //     10,
    //     20,
    //     30,
    // };
    // vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20};
    vector<int> value = {
        60,
        100,
    };
    vector<Item> v;
    for (int i = 0; i < value.size(); i++)
    {
        Item temp;
        temp.value = value[i];
        temp.weight = weight[i];
        v.push_back(temp);
    }
    cout << fractionalKnapsack(50, v, 3);
}
