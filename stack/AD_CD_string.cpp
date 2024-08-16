#include <bits/stdc++.h>
using namespace std;
int minLength(string s)
{
    stack<char> st;
    int count = 0;
    for (auto i : s)
    {
        if (i == 'A' || i == 'C')
            st.push(i);
        else if (!st.empty() && ((i == 'B' && st.top() == 'A') || (i == 'D' && st.top() == 'C')))
        {
            st.pop();
            count += 2;
        }
        else
        {
            while (!st.empty())
                st.pop();
        }
    }
    return s.size() - count;
}
int main()
{
    string s = "ACBBD";
    // string s="ABFCACDB";
    cout << minLength(s);
}