// write a program to implement bubble sort which performs the following operations
//  a)  takes int to be sorted as input from the user
//  b) performs bubble sort over the entered int
//  c) shows the list of int obtained during each pass
//  d) print the total number of swapping operations performed in the complete sorting process

// 2)suppose that 1 year is divided into 4 seasons spring, summer ,fall and winter by considering the following dates from which a season starts
// create a prog that reads the month and day from the user , the user will enter the name of the month as a string followed by name of day witihn the month as an int


// march 20 - spring
// june 21 - summer
// sep 22 -fall
// dec 21  - winter
#include <bits/stdc++.h>
using namespace std;

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(vector<int> &arr, int &count)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
        display(arr);
    }
}

void season(string month, int date)
{
    unordered_map<string, int> mp = {{"january", 0},//31
                                   {"february", 31},//59
                                   {"march", 59},//90
                                   {"april", 90},//120
                                   {"may", 120},//151
                                   {"june", 151},//181
                                   {"july", 181},//212
                                   {"august", 212},//243
                                   {"september", 243},//273
                                   {"october", 273},//304
                                   {"november", 304},//334
                                   {"december", 334}};//365
    int day = mp[month] + date;

    if(day>=79 && day<172)
    {
        cout<<"spring"<<endl;
    }
    else if(day>=172 && day<265)
    {
        cout<<"summer"<<endl;
    }
    else if(day>= 265 && day<354)
    {
        cout<<"fall"<<"fall";
    }
    else cout<<"winter"<<endl;

    return;

}
int main()
{
    // vector<int> arr;
    // int n;
    // cout << "ENTER NUMBER OF INTEGERS:";
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     arr.push_back(temp);
    // }

    // display(arr);
    // int count = 0;
    // bubble_sort(arr, count);
    // display(arr);

    // cout << "count is:" << count << endl;


    string month;
    cout<<"ENTER NAME OF THE MONTH"<<endl;
    cin>>month;
    int day;
    cout<<"ENTER DAY"<<endl;
    cin>>day;
    cout<<"season is:";
    season(month,day);
}