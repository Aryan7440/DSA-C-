// 1.write a program which performs following operations
// a) takes no. of int to be sorted as input from the users
// b) takes int as input from the users
// c) perform insertion sort over the entered int
// d) print out the sequence of numbers obtaind in each pass during sorting process

// 2. write a prog which takes no. of days as input from the users  your program should convert given no. of days in dd/mm/yyyy where all months have 30 days

#include <iostream>
#include<vector>
using namespace std;

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void insertion_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                display(arr); // real time movement
            }
        }
    }
}

void date(int days)
{
    int year = days / 365;
    days = days % 365;
    int month = days / 30;
    days = days % 30;
    cout << "DATE: " << days << ":" << month << ":" << year << endl;
}

int main()
{

    // vector<int> a;
    // int n;
    // cout << "enter number of integers ";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     a.push_back(temp);
    // }
    // display(a);
    // insertion_sort(a);


    int days;
    cout<<"enter number of days: ";
    cin>>days;
    date(days);
}