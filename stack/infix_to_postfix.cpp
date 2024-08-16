#include <iostream>
#include <stack>
using namespace std;

bool isoperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }

    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
string infix_to_postfix(string &s)
{
    stack<char> sign;
    string ans;

    int i = 0;
    while (i < s.length())
    {
        // if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')
        if (isalpha(s[i])|| isdigit(s[i]))
        {
            ans = ans + s[i];
            i++;
        }
        else if (s[i] == '(')
        {
            sign.push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while (sign.top() != '(')
            {
                ans = ans + sign.top();
                sign.pop();
            }
            sign.pop();
            i++;
        }

        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^')
        {

            if (!sign.empty() && precedence(s[i]) <= precedence(sign.top()))
            {
                ans = ans + sign.top();
                sign.pop();
            }
            else
            {
                sign.push(s[i]);
                i++;
            }
        }
    }
    while (!sign.empty())
    {
        ans += sign.top();
        sign.pop();
    }
    return ans;
}

void reverse(string &a)
{
    for (int i = 0; i < a.length() / 2; i++)
    {
        swap(a[i], a[a.length() - 1 - i]);
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(')
        {
            a[i] = ')';
        }
        else if (a[i] == ')')
        {
            a[i] = '(';
        }
    }
}

void infix_to_prefix(string s)
{
    stack<char> sign;
    string ans;
    reverse(s);
     int i = 0;
    while (i < s.length())
    {
        // if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')
        if (isalpha(s[i])|| isdigit(s[i]))
        {
            ans = ans + s[i];
            i++;
        }
        else if (s[i] == '(')
        {
            sign.push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while (sign.top() != '(')
            {
                ans = ans + sign.top();
                sign.pop();
            }
            sign.pop();
            i++;
        }

        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {

            if (!sign.empty() && precedence(s[i]) < precedence(sign.top()))
            {
                ans = ans + sign.top();
                sign.pop();
            }
            else
            {
                sign.push(s[i]);
                i++;
            }
        }
        else if (s[i]=='^')
        {
            if (!sign.empty() && precedence(s[i]) <= precedence(sign.top()))
            {
                ans = ans + sign.top();
                sign.pop();
            }
            else
            {
                sign.push(s[i]);
                i++;
            }
        }
        
    }
    while (!sign.empty())
    {
        ans += sign.top();
        sign.pop();
    }
    reverse(ans);
    cout<<ans<<endl;

}

int main()
{
    string a = "a+b*(c^d-e)^(f+g*h)-i";
    string b="x+y*z/w+u";
    // cout<<a<<endl;
    // stack<int> st;
    infix_to_postfix(a);
    infix_to_prefix(b);
    // cout<<precedence(st.top());
    // cout << b;
    // reverse(a);
    cout << a;
}