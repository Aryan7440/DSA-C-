#include <bits/stdc++.h>
using namespace std;
bool ischar(char c)
{
    if (c <= 'z' && c >= 'a')
        return true;
    return false;
}
void print(char e1, char s, char e2, int &n)
{
    string l = "", r = "";
    if (ischar(e1) && ischar(e2))
    {
        l = "R" + to_string(n);
        // to_string(n)
        n--;
        r = "R" + to_string(n);
        n--;
        cout << "MOV " << l << ", " << e1 << endl;
        cout << "MOV " << r << ", " << e2 << endl;
    }
    else if ((ischar(e1) && !ischar(e2)) || (!ischar(e1) && ischar(e2)))
    {
        if ((!ischar(e1) && ischar(e2)))
        {
            l = "R";
            l.push_back(e1);
            r = "R" + to_string(n);
            n--;
            cout << "MOV " << r << ", " << e2 << endl;
        }
        else
        {
            l = "R" + to_string(n);
            n--;
            r = "R";
            r.push_back(e2);
            cout << "MOV " << l << ", " << e1 << endl;
        }
    }
    else
    {
        // l = "R" + e1;
        l = "R";
        l.push_back(e1);
        // r = "R" + e2;
        r = "R";
        r.push_back(e2);
    }

    /*-------------------------------*/

    if (s == '/')
        cout << "DIV " << l << " " << r << endl;
    else if (s == '*')
        cout << "MUL " << l << " " << r << endl;
    else if (s == '+')
        cout << "ADD " << l << " " << r << endl;
    else
        cout << "SUB " << l << " " << r << endl;
}
void target_code(string exp)
{
    int e = 0;
    for (auto c : exp)
    {
        if (c != '/' && c != '*' && c != '+' && c != '-' && c != '=')
        {
            e++;
        }
    }
    e++;
    int i = 0;
    while (i < exp.size())
    {
        if (exp[i] == '/')
        {
            print(exp[i - 1], exp[i], exp[i + 1], e);
            exp.erase(i - 1, 3);
            exp.insert(i - 1, 1, to_string(e+2)[0]);
            i=0;
        }
        i++;
    }
    i = 0;
    while (i < exp.size())
    {
        if (exp[i] == '*')
        {
            print(exp[i - 1], exp[i], exp[i + 1], e);
            exp.erase(i - 1, 3);
            exp.insert(i - 1, 1, to_string(e + 2)[0]);
            i=0;
        }

        i++;
    }
    i = 0;
    while (i < exp.size())
    {
        if (exp[i] == '+')
        {
            print(exp[i - 1], exp[i], exp[i + 1], e);
            exp.erase(i - 1, 3);
            exp.insert(i - 1, 1, to_string(e + 2)[0]);
            // i=0;
        }
        i++;
    }
    i = 0;
    while (i < exp.size())
    {
        if (exp[i] == '-')
        {
            print(exp[i - 1], exp[i], exp[i + 1], e);
            exp.erase(i - 1, 3);
            exp.insert(i - 1, 1, to_string(e + 2)[0]);
            i=0;
        }
        i++;
    }
    cout << "ADD " << "R3" << " " << "R7" << endl;
    cout << "MOV "
         << exp[0]
         << ", "
         << "R1" << endl;
}
int main()
{
    string exp;
    // string exp = "a=b+c*d+e/f";
    cout<<"ENTER EXPRESSION: ";
    cin>>exp;
    target_code(exp);
}