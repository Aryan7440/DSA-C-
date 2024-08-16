#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string convertString(string str)
{
    if (islower(str[0]))
        str[0] = toupper(str[0]);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (islower(str[i + 1]))
            {
                str[i + 1] = toupper(str[i + 1]);
            }
        }
    }
    return str;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        string a;
        getline(cin,a);

        string b=convertString(a);
        cout<<b;
        
    }
}