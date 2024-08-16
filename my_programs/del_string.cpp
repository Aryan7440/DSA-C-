#include<iostream>
using namespace std;



bool backspace(string str1,string str2)
{
    string astr1,astr2;

    for (int i = 0; i < str1.size();i++ )
    {
        if (str1[i]=='#')
        {
            astr1.pop_back();

        }
        else
        {
            astr1=astr1+str1[i];

        }
        
    }
    for(int i=0;i<str2.size();i++)
    {
        if (str2[i]=='#')
        {
            astr2.pop_back();

        }
        else
        {
            astr2=astr2+str2[i];

        }
        
    }
    if (astr1==astr2)
    {
        return true;
    }
    else return false;
    
}
// string backspace(string str1)
// {
//     string astr1,astr2;

//     for (int i = 0; i < str1.size();i++ )
//     {
//         if (str1[i]=='#')
//         {
//             astr1.pop_back();

//         }
//         else
//         {
//             astr1=astr1+str1[i];

//         }
        
//     }
//     return astr1;
    
// }
 
// Driver code
int main()
{
    string str;
    getline(cin,str);
    // cout<<backspace(str);
 
    return 0;
}