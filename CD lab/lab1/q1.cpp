#include <bits/stdc++.h>
using namespace std;

bool comment(vector<string> &str)
{
    int n = str.size();
    if (str.size() == 1)
    {
        if (str[0][0] == '/' && str[0][1] == '/')
            return true;
    }

    if (str[0][0] == '/' && str[0][1] == '*' && str[n - 1][str[n - 1].size() - 2] == '*' && str[n - 1][str[n - 1].size() - 1] == '/')
        return true;

    return false;
}

int main()
{
    vector<string> str;
    while (true)
    {
         string temp;
        cin.clear();
        cin.sync();
        getline(cin, temp);

        if(temp.size()==0)break;
        if (temp[temp.size() - 2] == '*' && temp[temp.size() - 1] == '/')
        {
            str.push_back(temp);
            break;
        }
        str.push_back(temp);
        if(str.size()==1 && str[0][0]=='/' && str[0][1]=='/')
        {
            break;
        }
    }
    if (comment(str))
        cout << "IT is a comment " << endl;
    else
        cout << "IT is not a comment" << endl;
}