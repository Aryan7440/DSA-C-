#include <iostream>
using namespace std;



int digits(long int n)
{
    int ans=0;
    while(n>0)
    {
        ans++;
        n=n/10;
    }
    return ans;
}

long int power(long int a,int b)
{
    int ans=1;
    for (int i = 0; i < b; i++)
    {
        ans=ans*a;
    }
    
    return (ans);
}


long int check_armstrong(long int n)
{
    long int ans=0,a=n;
    int d=digits(n);
    while (a > 0)
    {
        ans = ans + power(a % 10,d);
        a = a / 10;
    }
    if (ans==n)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    long int n;
    cin >> n;
    (check_armstrong(n)==1) ? cout<<"armstrong":cout<<"not armstrong";
    cout<<endl;

    for (int i = 1; i <= 10000; i++)
    {
        if (check_armstrong(i)==1)
        {
            cout<<i<<endl;
        }
        
    }
    
    
}
