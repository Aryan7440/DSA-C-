#include <bits/stdc++.h>
using namespace std;

/*
S → xP’
P’ → QzP’ / xP’ / ∈
Q → yR’
R’ → wR’ / ∈
*/

// int E(), Edash(), T(), Tdash(), F();
int S(), Pdash(), Q(), Rdash();
int c = 0;
string str="";
int S()
{
    if (str[c] == 'x')
    {
        cout << "S -> xP'" << endl;
        c++;
        if (Pdash())
            return 1;
        return 0;
    }
    return 0;
}
int Pdash()
{
    if (Q())
    {
        cout << "P' -> QzP'" << endl;
        if (str[c] == 'z')
        {
            c++;
            if (Pdash())
                return 1;
            return 0;
        }
        return 0;
    }
    else if (str[c] == 'x')
    {
        cout << "P' -> xP'" << endl;
        if (Pdash())
        {
            return 1;
        }
        return 0;
    }
    else
    {
        cout << "P' -> #" << endl;
        return 1;
    }
    return 0;
}
int Q()
{
    if (str[c] == 'y')
    {
        cout << "Q -> yR'" << endl;
        c++;
        if (Rdash())
        {
            return 1;
        }
        return 0;
    }
    return 0;
}
int Rdash()
{
    if (str[c] == 'w')
    {
        cout << "R' -> wR'" << endl;
        c++;
        if (Rdash())
            return 1;
        return 0;
    }
    else
    {
        cout << "S'-> #" << endl;
        return 1;
    }
    return 0;
}

int main()
{
    cout << "ENTER STRING: " << endl;
    cin >> str;
    int l = str.length();
    // str += '$';
    str.push_back('$');
    if (S() && str[c] == '$')
    {
        cout << "------------------------------------" << endl;
        cout << "  STRING IS SUCCESFULLY PARSED      " << endl;
        cout << "------------------------------------" << endl;
        return 0;
    }
    else
    {
        cout << "------------------------------------" << endl;
        cout << "  STRING IS NOT SUCCESFULLY PARSED      " << endl;
        cout << "------------------------------------" << endl;
        return 0;
    }
}