#include <bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    if (n < m)
        return gcdOfStrings(str2, str1);
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (str1[i] != str2[j % m])
            return "";
        i++;
        j++;
    }
    if (n % m == 0)
        return str2;
    int k = m / 2;
    while (k > 0)
    {
        string a = str2.substr(0, k);
        // string b=str2.substr(k,k);
        // if(a==b)return str2.substr(0,k);

        for (int j = k; j <= m - k; j = j + k)
        {
            string b = str2.substr(j, k);
            if (a == b)
                return str2.substr(0, k);
        }
        k--;
    }
    return str2;
}
int main()
{
    string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX", str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    cout << gcdOfStrings(str1, str2);
}