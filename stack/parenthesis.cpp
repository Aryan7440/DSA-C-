#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minimumParentheses(string pattern)
{
    stack<char> s;
    int count = 0;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (pattern[i] == '(')
        {
            s.push(pattern[i]);
        }
        else
        {
            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                count++;
            }
        }
    }
    while (!s.empty())
    {
        count++;
        s.pop();
    }
    return count;
}

int main()
{
    string s="(()))(((";
    int a=minimumParentheses(s);
    cout<<a;
}