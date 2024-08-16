#include <bits/stdc++.h>
using namespace std;

int bulbs(vector<int> &A)
{
    int state = 0;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (state == 0)
        {
            if (A[i] == 0)
            {
                ans++;
                state = 1;
            }
            else
                continue;
        }
        else
        {
            if (!A[i] == 0)
            {
                ans++;
                state = 0;
            }
            else
                continue;
        }
    }
    return ans;
}

int main()
{
    vector<int> A={1, 1, 0, 0, 1, 1, 0, 0, 1 };
    cout<<bulbs(A);
}
