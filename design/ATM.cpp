#include <bits/stdc++.h>
using namespace std;
class ATM
{
public:
    vector<int> money;
    vector<int> note;
    ATM()
    {
        money = {20, 50, 100, 200, 500};
        note.resize(5, 0);
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < 5; i++)
        {
            note[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount)
    {
        vector<int> ans(5,0);
        // vector<int> dep(5, 0);
        for (int i = 4; i >= 0; i--)
        {
            if(amount==0)return ans;
            if (amount >= money[i])
            {
                if (amount / money[i] <= note[i])
                {
                    ans[i] = amount / money[i];
                    note[i] -= ans[i];
                    amount = amount % money[i];
                }
                else
                {
                    for(int j=i+1;j<5;j++)note[j]+=ans[j];
                    return {-1};
                }
            }
        }
        return ans;
    }
};
int main()
{
    ATM atm;
    atm.deposit({0, 0, 1, 2, 1}); // Deposits 1 $100 banknote, 2 $200 banknotes,
                                  // and 1 $500 banknote.
    atm.withdraw(600);            // Returns {0,0,1,0,1}. The machine uses 1 $100 banknote
                                  // and 1 $500 banknote. The banknotes left over in the
                                  // machine are {0,0,0,2,0}.
    atm.deposit({0, 1, 0, 1, 1}); // Deposits 1 $50, $200, and $500 banknote.
                                  // The banknotes in the machine are now {0,1,0,3,1}.
    atm.withdraw(600);            // Returns {-1}. The machine will try to use a $500 banknote
                                  // and then be unable to complete the remaining $100,
                                  // so the withdraw request will be rejected.
                                  // Since the request is rejected, the number of banknotes
                                  // in the machine is not modified.
    atm.withdraw(550);            // Returns {0,1,0,0,1]. The machine uses 1 $50 banknote
                                  // and 1 $500 banknote.
}