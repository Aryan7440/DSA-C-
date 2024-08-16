#include<bits/stdc++.h>
using namespace std;

int naive(string text,string pattern)
{
    int n=text.size(),m=pattern.size();
    for(int i=0;i<n-m;i++)
    {
        int k=i;
        for(int j=0;j<m;j++)
        {
            if(text[k++]!=pattern[j])break;
            if(j==m-1)return i;
        }
    }
    return -1;
}

int main()
{
    string text="avaaabcddddd",pattern="vaa";
    cout<<naive(text,pattern);
}