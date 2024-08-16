#include <iostream>
using namespace std;

void terniary_search(int arr[], int l, int r, int x)
{
    // int m1=(r-l)/3,m2=2*(r-l)/3;
    int flag=-1;
    while (r >= l)
    {
        int m1 =l+ (r - l) / 3, m2 =l+ (2 * (r - l) / 3);
        
        if (arr[m1] == x || arr[m2] == x)
        {
            (arr[m1] == x) ? flag=m1 : flag= m2;
            break;
        }
        if (x > arr[m1] && x < arr[m2])
        {
            l = m1 + 1;
            r = m2 - 1;
        }
        if (x < arr[m1])
        {
            r = m1 - 1;
        }
        if (x > arr[m2])
        {
            l = m2 + 1;
        }
    }
    cout << flag;
}

int main()
{
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    terniary_search(arr, 0, 9, 54);
}