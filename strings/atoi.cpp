#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int mod = INT_MAX;
    int ans = 0;
    int sign = 1;
    int i = 0;
    while (s[i] == ' ')
        i++;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        sign = 1;
        i++;
    }
    if (s[i] >= '0' && s[i] <= '9')
    {
        int j = i;
        while (j < s.size() && s[j] >= '0' && s[j] <= '9')
        {
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[j] - '0' > 7))
            {
                if (sign = -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            ans = ans * 10 + (s[j] - '0');
            j++;
        }
        ans = ans * sign;

        return ans;
    }
    else
        return 0;
    return 0;
}
int main()
{
    cout << myAtoi("21474836460");
}