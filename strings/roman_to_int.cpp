#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                res += 4;
                i++;
                continue;
            }
            if (s[i + 1] == 'X')
            {
                res += 9;
                i++;
                continue;
            }
            else
            {
                res += 1;
                continue;
            }
        }
        if (s[i] == 'V')
            res += 5;
        if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                res += 40;
                i++;
                continue;
            }
            if (s[i + 1] == 'C')
            {
                res += 90;
                i++;
                continue;
            }
            else
            {
                res += 10;
                continue;
            }
        }
        if (s[i] == 'L')
            res += 50;
        if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                res += 400;
                i++;
                continue;
            }
            if (s[i + 1] == 'M')
            {
                res += 900;
                i++;
                continue;
            }
            else
            {
                res += 100;
                continue;
            }
        }
        if (s[i] == 'D')
            res += 500;
        if (s[i] == 'M')
            res += 1000;
    }
    return res;
}

int main()
{
    string s1("MCMXCIV");
    cout<<romanToInt(s1);

    return 0;
}