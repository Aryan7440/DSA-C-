#include <bits/stdc++.h>
using namespace std;
vector<string> reorderLogs(vector<string> &A)
{
    int N = A.size();
    vector<string> digs, alp;
    for (int i = 0; i < N; i++)
    {
        string s = A[i];
        int n = s.size();
        int l = 0;
        while (s[l] != '-')
            l++;
        bool isDig = (s[l + 1] <= 'z' && s[l + 1] >= 'a');
        string str = s.substr(l + 1, n - l - 1);
        if (!isDig)
            digs.push_back(str);
        else
            alp.push_back(str);
    }
    sort(alp.begin(), alp.end());
    vector<string> ans;
    for (auto i : alp)
        ans.push_back(i);
    for (auto i : digs)
        ans.push_back(i);
    return ans;
}

int main()
{
    // vector<string> arr = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    vector<string> arr = {"qv4-tbojcv-yd", "uh9-lmtdpiunu", "ta9-5-3-5-5-1", "hn2-yawf-jw-zkw", "nc7-hdly-hrht", "ja7-6-5-7-0-4", "ld1-le-cmt-t-z", "hu2-wfkpj-jv", "iy0-hujr-wmrg-ca", "ia7-y-l-bnaz", "nr1-7-1-7-0-4", "gx0-sm-by-wd-ea"};
    vector<string> res = reorderLogs(arr);
    for (auto i : res)
        cout << i << endl;
    return 0;
}