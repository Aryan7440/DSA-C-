#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool paranthsis(string s)
{
    stack<char> p;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            p.push(s[i]);
            continue;
        }
        else if (p.empty())
        {
            return false;
        }
        else if (s[i] == ']' && p.top() == '[')
        {
            p.pop();
            continue;
        }
        else if (s[i] == ')' && p.top() == '(')
        {
            p.pop();
            continue;
        }
        else if (s[i] == '}' && p.top() == '{')
        {
            p.pop();
            continue;
        }
        // else return false;
    }
    return p.empty();
}

bool checkValidString(string s)   //((((***))))
{
    stack<char> bracket;
    stack<char> star;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            bracket.push(s[i]);
        }
        else if (s[i] == '*')
        {
            star.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!bracket.empty())
            {
                bracket.pop();
                continue;
            }
            if (!star.empty())
            {
                star.pop();
            }
            else
                return false;
        }
    }
    while (!star.empty() && !bracket.empty()) //
    {
        if (bracket.top() < star.top())
        {
            star.pop();
            bracket.pop();
        }
        else
            return false;
    }
    return bracket.empty();
}

bool checkValidString2(string s)
    {
        int maxopen=0;
        int minopen=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                maxopen++;
                minopen++;
            }
            else if(s[i]=='*')
            {
                maxopen++;
                minopen--;
            }
            else
            {
                maxopen--;
                minopen--;
            }
            minopen=max(0,minopen);
            if(maxopen<0)return false;
            
        }
        return minopen==0;
        
    }

int main()
{

    // string str = "[[(avalb{fawfc(V)})]]";
    // if (paranthsis(str) == true)
    // {
    //     cout << "balanced";
    // }
    // else
    // {
    //     cout << "not balanced" << endl;
    // }
    // stack <int> a;
    // cout<<a.empty();
    // cout<<a.pop();

    string s="()";
    cout<<checkValidString2(s);
    // cout<<s.size();
}