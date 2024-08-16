#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveAnswers(string answerKey, int k)
{
    int l = 0, r = 0, Tcount = 0, Fcount=0, len = INT_MIN;
    while (r < answerKey.size())
    {
        // answer[r]++;
        if (answerKey[r] == 'T')
            Tcount++;
        else
            Fcount++;

        while (min(Fcount, Tcount) > k)
        {
            if (answerKey[l] == 'T')
                Tcount--;
            else
                Fcount--;
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}
int main()
{
    string answerKey="TTFTTFTT";
    cout<<maxConsecutiveAnswers(answerKey,1);
}