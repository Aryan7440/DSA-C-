#include <bits/stdc++.h>
using namespace std;

// void generate(string num, string ds, int target, int i, vector<string> &ans, long long int eval, long long int prev)
// {
//     if (i == num.size() - 1)
//     {
//         if (eval == target)
//             ans.push_back(ds);
//         return;
//     }
//     long long int next = num[i + 1] - '0';
//     generate(num, ds + '+' + num[i + 1], target, i + 1, ans, eval + next, next);
//     generate(num, ds + '-' + num[i + 1], target, i + 1, ans, eval - next, -next);
//     generate(num, ds + '*' + num[i + 1], target, i + 1, ans, (eval - prev) + (prev * next), prev * next);
//     if ((int)(num[i] - '0') != 0)
//     {
//         if(prev>0)generate(num, ds + num[i + 1], target, i + 1, ans, (eval - prev) + (prev * 10 + next), (prev * 10 + next));
//         else generate(num, ds + num[i + 1], target, i + 1, ans, (eval - prev) + (prev * 10 - next), (prev * 10 - next));
//     }
// }
void generate(string num, string ds, int i, int target, long long int eval, long long int prev, vector<string> &ans)
{
    if (i == num.size())
    {
        if (eval == target)
            ans.push_back(ds);
        return;
    }
    string curr_s;
    long long n = 0;
    for (int j = i; j < num.size(); j++)
    {
        if (j > i && num[i] == '0')
            break;
        curr_s += num[j];
        n = n * 10 + num[j] - '0';
        if (i == 0)
            generate(num, ds + curr_s, j + 1, target, n, n, ans);
        else
        {
            generate(num, ds + '+' + curr_s, j + 1, target, eval + n, n, ans);
            generate(num, ds + '-' + curr_s, j + 1, target, eval - n, -n, ans);
            generate(num, ds + '*' + curr_s, j + 1, target, (eval - prev) + (prev * n), prev * n, ans);
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> ans;
    string ds = "";
    // generate(num, ds + num[0], target, 0, ans, (int)(num[0] - '0'), (int)(num[0] - '0'));
    generate(num, ds, 0, target, 0, 0, ans);
    return ans;
}

int main()
{
    vector<string> ans = addOperators("412345", 128);
    for (auto i : ans)
    {
        cout << i << endl;
    }

}