#include <iostream>
#include <string>
using namespace std;

char sary[] = "IVXLCDM";
int ary[] = {1, 5, 10, 50, 100, 500, 1000};


int value(char chr)
{
    for (int i = 0; i < 7; i++)
    {
        if (chr == sary[i])
        {
            return ary[i];
        }
    }
    return -1;
}

int romanToInt(string s)
    {
        int i = 0;
        int sum = 0;
        while (i < s.size())
        {
            if(value(s[i])<value(s[i+1]))
            {
                sum = sum + (value(s[i + 1]) - value(s[i]));
                i = i + 2;
            }
            else
            {
                sum = sum + value(s[i]);
                i++;
            }
        }
        return sum;
    }


int main()
{

    string std="MCMXCIV";
    (value(std[1])<value(std[2])) ? cout<<(value(std[1 + 1]) - value(std[1])): cout<<"false";
    cout<<romanToInt(std);
    


    
    
    
}