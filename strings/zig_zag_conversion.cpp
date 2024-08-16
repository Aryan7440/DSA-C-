#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows)
{
    string ans;
    int next = (2 * numRows) - 2;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < s.size(); j = j + next)
        {
            ans += s[j];
            int temp = j + next - (2 * i);
            if (i != 0 && i != numRows - 1 && temp < s.size())
            {
                ans += s[temp];
            }
        }
    }
    return ans;
}
int main()
{
    string s="PAYPALISHIRING";
    cout<<convert(s,3);
}