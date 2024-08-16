#include <iostream>
using namespace std;

// Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.
void hello()
{
    cout << "HELLLO" << endl;
}

int sum(int a, int b)
{
    return a + b;
}

int compare(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else return 1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[], int size, int (*compare)(int, int))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // if (arr[j] > arr[j + 1])
            // {
            //     int temp = arr[j];
            //     arr[j] = arr[j + 1];
            //     arr[j + 1] = temp;
            //     // swap(arr[j], arr[j + 1]);
            // }
            if (compare(arr[j],arr[j+1])>0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    // int (*ptr)(int,int)=&sum;       //also =sum can be used
    // void (*p)();
    // p=hello;
    // p();
    // cout<<(*ptr)(2,3)<<endl;
    // cout<<(ptr)(4,3);

    int arr[5]={2,5,1,6,9};
    display(arr,5);
    bubble_sort(arr,5,compare);
    display(arr,5);

    // cout << compare(10, 90);
}