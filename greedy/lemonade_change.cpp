#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    // sort(bills.begin(), bills.end());
    int five = 0, ten = 0, twenty = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            if (five == 0)
                return false;
            else
                five--;
            ten++;
        }
        else
        {
            if (ten > 0)
            {
                if (five > 0)
                {
                    ten--;
                    five--;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            if (five > 3)
            {
                five = five - 3;
            }
            else
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int> bills = {5,5,5,20};
    cout << lemonadeChange(bills);
}