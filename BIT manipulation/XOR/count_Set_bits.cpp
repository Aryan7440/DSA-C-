#include <bits/stdc++.h>
using namespace std;
int count_bits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x & (x - 1);
        count++;
    }
    return count;
}
int least_set_bit(int x)
{
    for (int i = 0; i < 32; i++)
    {
        int a = 1 << i;
        if ((a & x) != 0)
            return i;
    }
    return -1;
}
int max_set_bits(int x)
{
    int i = 0;
    while ((1 << i) <= x)
    {
        i++;
    }
    return i - 1;
}
int countSetBits(int n)
{
    if(n==0)return 0;
    int x = max_set_bits(n);
    int m=pow(2, x);
    int ans =(x * m/2)+ (n-m) + countSetBits(n-m);
    return ans;
}
int main()
{
    // for(int i=0;i<8;i++)
    // {
    //     bitset<8> a=i;
    //     cout<<a<<endl;
    // }
    bitset<32> a = 20033;
    cout << a << endl;
    // cout << count_bits(8) << endl;
    // cout << least_set_bit(8);
    // cout << countSetBits(8);
}
// 4c1=4

// 4c2=6
// 4c3=4
// 4c4=1
