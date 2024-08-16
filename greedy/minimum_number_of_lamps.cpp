#include <bits/stdc++.h>
using namespace std;

int findMinimumLamps(string s)
{
    // Write your code here.
    int lamps = 0;
    int n = s.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '.')
        {
            if (s[i - 1] == '.' && s[i + 1] == '.')
            {
                s[i] = '*';
                s[i+1]='l';
                s[i-1]='l';
                lamps++;
            }
        }
    }
    if (n >= 2 && s[0] == '.' && s[1] == '.')
        lamps++;
    if (n >= 2 && s[n - 1] == '.' && s[n - 2] == '.')
        lamps++;
    return lamps;
}
int main()
{
    string s = "....**..**";
    cout << findMinimumLamps(s);
}