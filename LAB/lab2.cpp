// 1. write a program for merge sort which performs following task
// a. takes integers to be sorted as input from the user
// b.performs merge sort over the entered integers
// c. shows the complete list of integers obtained during each split and merge operation
// 2. write a program which performs following operations
// a. take a string as input from the user
// b. print the substring as well as their length which are alphabetically sortd
// c. print the alphabetically sorted substring of highest length
// d. if no alphabetically sorted substring is present then print the meassage

#include <bits/stdc++.h>
using namespace std;
void print_subsrtings(string s, vector<string> &subs)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            string temp;
            for (int k = i; k <= j; k++)
            {
                temp.push_back(s[k]);
            }
            subs.push_back(temp);
        }
    }
}

void alphabetically(vector<string> subs, vector<string> &alphasubs)
{
    for (int i = 0; i < subs.size(); i++)
    {
        string temp = subs[i];
        sort(temp.begin(), temp.end());
        if (temp == subs[i])
        {
            alphasubs.push_back(temp);
        }
    }
}
void alpha_lengths(vector<string> &alphasubs)
{
    if (alphasubs.size() == 0)
    {
        cout << "NO ALPHABETICALLY SORTED SUBSTRINGS" << endl;
        return;
    }
    string max_string;
    int max_length = 0;
    for (int i = 0; i < alphasubs.size(); i++)
    {
        cout << alphasubs[i] << endl;
        cout << alphasubs[i].length() << endl;
        if (alphasubs[i].length() > max_length)
        {
            max_length = alphasubs[i].length();
            max_string = alphasubs[i];
        }
        cout << endl;
    }

    cout << "STRING OF MAX LENGTH IS:";
    cout << max_string;
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge_array(vector<int> &a, int start, int mid, int stop)
{
    int i = start, j = mid + 1, k = start;
    // int n = a.size(), m = b.size();
    vector<int> result(a.size());
    while (i <= mid && j <= stop)
    {
        if (a[i] < a[j])
        {
            result[k] = a[i];
            i++;
        }
        else
        {
            result[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        result[k] = a[i];
        i++;
        k++;
    }
    while (j <= stop)
    {
        result[k] = a[j];
        j++;
        k++;
    }

    for (int i = start; i <= stop; i++)
    {
        a[i] = result[i];
    }

    display(a);
}

void merge_sort(vector<int> &arr, int start, int stop)
{
    if (start >= stop)
        return;
    int mid = start + (stop - start) / 2;

    merge_sort(arr, start, mid);

    merge_sort(arr, mid + 1, stop);

    merge_array(arr, start, mid, stop);
}

int main()
{
    // int n;
    // cout << "enter number of integers to be input: ";
    // cin >> n;
    // vector<int> a(n);
    // // vector<int> a = {12, 65, 48, 35, 12, 68, 43, 7, 1, 0};
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cin >> a[i];
    // }
    // cout << endl;
    // display(a);
    // merge_sort(a, 0, a.size() - 1);

    string s ;
    cout<<"ENTER STRING: ";
    cin>>s;
    vector<string> subs;
    print_subsrtings(s,subs);
    vector<string> alphasubs;
    alphabetically(subs,alphasubs);
    alpha_lengths(alphasubs);
}
