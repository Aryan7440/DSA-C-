#include <bits/stdc++.h>
using namespace std;

string util(int columnNumber)
{
    if (columnNumber <= 26)
    {
        int c = 64 + columnNumber;
        string res = "";
        res.push_back(c);
        return res;
    }
    int num = columnNumber / 26;
    char c;
    int rem = columnNumber % 26;
    if (rem == 0)
        c = 'Z';
    else
        c = 64 + rem;
    string help = util(num);
    help.push_back(c);
    return help;
}
string convertToTitle(int columnNumber)
{
    return util(columnNumber);
}
int main()
{
    cout<<convertToTitle(52);
}
