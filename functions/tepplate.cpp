#include <iostream>
using namespace std;

// template <class T>
// T product(T a,T b)
// {
//     return a*b;
// }

void isort(int arr[], int size)
{
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < key)
            {
                break;
            }
            else
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <class T>
void insert_sort(T t[],int size)
{
   int key;
    for (int i = 1; i < size; i++)
    {
        key = t[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (t[j] < key)
            {
                break;
            }
            else
            {
                swap(t[j], t[j + 1]);
            }
        }
    } 
}
template <class T, class U>
U product(T a, U b)
{
    return a * b;
}

int main()
{
    cout<<product(1.2,2.3)<<endl;
    cout<<product(1.2,2)<<endl;

    // int a[] = {9, 8, 7, 6, 5, 4, 4, 3, 2, 1};
    // int s = sizeof(a) / sizeof(a[0]);
    // isort(a, s);
    // for (int i = 0; i < s; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // char c[]={'d','y','i','r','w','m','m'};
    // insert_sort(c,sizeof(c));
    // for (int i = 0; i < sizeof(c); i++)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    
}
