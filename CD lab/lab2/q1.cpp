#include <bits/stdc++.h>
using namespace std;
bool isDelimiter(string s)
{
    char ch = s[0];
    if (ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return true;
    return false;
}
bool isOperator(string s)
{
    char ch = s[0];
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return true;
    return false;
}
bool validIdentifier(string str)
{
    if ((str[0] >= '0' && str[0] <= '9') || isDelimiter(str))
        return false;
    return true;
}
bool isKeyword(string str)
{
    vector<string> keyword = {"if", "else", "while", "do", "break", "continue", "int", "double", "float", "return", "char", "case", "char", "sizeof", "long", "short", "typedef", "switch", "unsigned", "void", "goto", "static", "struct"};
    for (auto i : keyword)
        if (str == i)
            return true;
    return false;
}
bool isInteger(string str)
{
    int len = str.size();
    if (len == 0)
        return (false);
    for (int i = 0; i < len; i++)
    {
        if ((str[i] == '-' && i > 0) || str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isRealNumber(string str)
{
    int i, len = str.size();
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if ((str[i] == '-' && i > 0) || str[i] < '0' || str[i] > '9')
            return false;
        if (str[i] == '.' && !hasDecimal)
            hasDecimal = true;
        else
            false;
    }
    return hasDecimal;
}
void parse(string str, int &count)
{
    int left = 0, right = 0;
    int len = str.size();

    while (right <= len && left <= right)
    {
        if(str[left]=='/' && str[left+1]=='/')
        {
            right=len-1;
            string subStr = str.substr(left, (right - left));
            cout<<" comment: "<<subStr<<endl;
            break;
        }
        while (right < len && str[right] != ' ')
            right++;
        string subStr = str.substr(left, (right - left));

        if (isDelimiter(subStr))
        {
            cout << subStr << " is a delimiter" << endl;
            count++;
        }

        else if (isOperator(subStr))
        {
            cout << subStr << " is an operator " << endl;
            count++;
        }

        else if (isDelimiter(subStr) == false && left != right || (right == len - 1 && left != right))
        {
            // char *subStr = subString(str, left, right - 1);
            // string subStr = str.substr(left, (right - left));

            if (isKeyword(subStr) == true)
            {
                cout << subStr << " IS A KEYWORD " << endl;
                count++;
            }
            else if (isInteger(subStr) == true)
            {
                cout << subStr << " IS A INTEGER " << endl;
                count++;
            }

            else if (isRealNumber(subStr) == true)
            {
                cout << subStr << " IS A NUMBER " << endl;
                count++;
            }

            else if (validIdentifier(subStr) == true)
            {
                cout << subStr << " IS A VALID iDENTIFIER " << endl;
                count++;
            }
            else if (validIdentifier(subStr) == false)
                cout << subStr << " IS A NOT A VALID IDENTIFIER " << endl;
        }
        right++;
        left = right;
    }
    return;
}
int main()
{
    vector<string> str;
    // string temp = "int a = 1b + 4 ;";
    // str.push_back(temp);
    // int count = 0;
    // parse(temp, count);
    while (true)
    {
        string temp;
        getline(cin, temp);
        if (temp.empty())
            break;
        str.push_back(temp);
    }
    int count = 0;
    for (auto i : str)
    {
        parse(i, count);
    }
    cout << "token Count:" << count << endl;
}