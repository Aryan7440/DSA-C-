#include <bits/stdc++.h>
using namespace std;
int monotoneIncreasingDigits(int n)
{
    string num = to_string(n) ;
    int s = num.size();
    string ans;
    // bool flag = 0;
    int l=-1;
    for (int i = 1; i < s; i++)
    {
        if (num[i] < num[i - 1])
        {
            int ptr = i - 1;
            while (ptr >= 0 && num[ptr] >= num[ptr+1])
                ptr--;
            num[ptr + 1] = num[ptr + 1] - 1;
            l=ptr+1;
            break;
        }  
    }
    if( l!=-1)for(int i=l+1;i<s;i++)num[i]='9';
    return stoi(num);
}
int main()
{
    int a=332;
    cout<< monotoneIncreasingDigits(331);

}