#include <bits/stdc++.h>
using namespace std;
public
int parseI(String S, int i)
{
    int num = 0;
    int n = S.length();
    while (i < n && S.charAt(i) != '.')
    {
        num = num * 10 + (S.charAt(i) - '0');
    }
    return num;
}
public
int compareVersion(String version1, String version2)
{
    int i = 0, j = 0;
    int n = version1.length(), m = version2.length();
    while (i < n && j < m)
    {
        if (parseI(version1, i) == parseI(version2, j))
        {
            while (i < n && version1.charAt(i) != '.')
                i++;
            i++;
            while (j < m && version2.charAt(j) != '.')
                j++;
            j++;
        }
        else if (parseI(version1, i) <= parseI(version2, j))
            return -1;
        else
            return 1;
    }
    if (i == n)
    {
        while (j < m)
        {
            if (parseI(version2, j) > 0)
                return -1;
            while (j < m && version2.charAt(j) != '.')
                j++;
        }
        if (j == m)
            return 0;
    }
    if (j == m)
    {
        while (i < n)
        {
            if (parseI(version1, i) > 0)
                return 1;
            while (i < n && version1.charAt(i) != '.')
                i++;
        }
        if (i == n)
            return 0;
    }
    return 0;
}
int main()
{
}