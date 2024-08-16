#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    for (int i = 0; i < 16; i++)
    {
        int r = ((1 << i) & n) != 0 ? 1 : 0;
        int l = ((1 << (31 - i)) & n) !=0 ? 1 : 0;

        if (r != l)
        {
            if (r == 1)
            {
                n = n & (~(1 << i));
                n = n | (1 << (31 - i));
            }
            else
            {
                n = n & (~(1 << (31 - i)));
                n = n | (1 << (i));
            }
        }
    }
    return n;
}
int main()
{
    uint32_t n=43261596;
    cout<<reverseBits(n);
}