#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if(x<y)return gcd(y,x);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main(int argc, char const *argv[])
{
    cout<<gcd(12,36);
    return 0;
}
