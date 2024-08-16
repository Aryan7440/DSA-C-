#include <bits/stdc++.h>
using namespace std;
unordered_set<char>var,ter;
void find_var_ter(vector<string> prd,unordered_set<char>&var,unordered_set<char>&ter)
{
    for(auto p:prd)
    {
        for(auto c:p)
        {
            if(c=='=')continue;
            else if(c<='Z' && c>='A')var.insert(c);
            else ter.insert(c);
        }
    }
}


int main()
{
    vector<string> prd = { "E=TR",
                           "R=+TR",
                           "R=#",
                           "T=FY ",
                           "Y=*FY",
                           "Y=#",
                           "F= i ",
                           "F=(E)" };
}