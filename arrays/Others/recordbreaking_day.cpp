#include <iostream>
using namespace std;
int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}
int recordbreakaing(int arr[], int size)
{
    int max = arr[0];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        
        if (i == 0 && arr[i] > arr[i + 1])
        {
            count++;
        }
        else if (i == size - 1 && arr[size - 1] > max)
        {
            count++;
        }
        else
        {
            if (arr[i] > max && arr[i] > arr[i+1])
            {
                count++;
            }
        }
        max = Max(max, arr[i]);
    }
    return count;
}

int main()
{
    int a[]={1,2,0,7,2,0,2,9,2};
    int size=sizeof(a)/4;
    cout<<recordbreakaing(a,size);
}