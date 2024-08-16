#include <iostream>
#include <vector>
using namespace std;

int sqrt(long long int n)
{
    int start = 1;
    int stop = n / 2;
    int mid = (stop - start) / 2;
    int res = 0;
    while (start <= stop)
    {
        mid=start+(stop - start) / 2;
        if (mid * mid == n)
        {
            res = mid;
            break;
        }
        else if (mid * mid < n)
        {
            start = mid + 1;
            res = mid;
        }
        else
        {
            stop = mid - 1;
        }
    }
    return res;
}

int main()
{
    cout << sqrt(2) << endl;
}