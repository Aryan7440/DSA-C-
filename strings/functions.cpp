#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word)
{
    if (word.size() <= 1)
        return true;
    if (isupper(word[0]))
    {
        int u_count = 0;
        int l_count = 0;
        for (int i = 1; i < word.size(); i++)
        {
            if (isupper(word[i]))
                u_count++;
            else
                l_count++;
            if (u_count && l_count)
                return false;
        }
    }
    else
    {
        for(int i=1;i<word.size();i++)if(isupper(word[i]))return false;
    }

    return true;
}
int main()
{
    cout << detectCapitalUse("ffffffffffffffffffffF");
}