#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    for (auto i : tokens)
    {
        if (i == "+")
        {
            int temp = s.top();
            s.pop();
            temp += s.top();
            s.pop();
            s.push(temp);
        }
        else if (i == "-")
        {
            int temp = s.top();
            s.pop();
            temp -= s.top();
            s.pop();
            s.push(temp);
        }
        else if (i == "*")
        {
            int temp = s.top();
            s.pop();
            temp *= s.top();
            s.pop();
            s.push(temp);
        }
        else if (i == "/")
        {
            int temp = s.top();
            s.pop();
            temp /= s.top();
            s.pop();
            s.push(temp);
        }
        else
        {
            s.push(stoi(i));
        }
    }
    return s.top();
}

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(tokens);
    cout<<stoi("10");
}