#include <iostream>
#include <vector>
#include <string>
using namespace std;
void one_n(int n)
{
    if (n == 0)
        return;
    one_n(n - 1);
    cout << n << endl;
}

void n_one(int n)
{
    if (n < 0)
        return;
    cout << n << endl;
    n_one(n - 1);
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

void reverse(vector<int> &arr, int start, int stop)
{
    if (start == stop)
        return;
    swap(arr[start], arr[stop]);
    reverse(arr, start + 1, stop - 1);
}

void reverse_2(vector<int> &arr,int i)
{
    if(i<arr.size()/2)
    {
        swap(arr[i],arr[arr.size()-1-i]);
    }
    else return;
    reverse_2(arr,i+1);
}
void display(vector<int> arr, int i)
{
    if (i < 0)
        return;
    display(arr, i - 1);
    cout << arr[i] << " ";
}

bool palindrome(string s,int i=0)
{

    if(i<s.size()/2)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            return false;
        }
    }
    else return true;
    return palindrome(s,i+1);
}
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void print_name(string s, int n)
{
    if (n == 0)
        return;
    cout << s << endl;
    print_name(s, n - 1);
}

int sum_of_first_n_numbers(int n)
{
    if (n == 0)
        return 0;
    return n + sum_of_first_n_numbers(n - 1);
}

int main()
{
    // vector<int> arr={1,2,3,4,5};
    // display(arr,arr.size()-1);
    // cout<<endl;
    // reverse(arr,0,arr.size()-1);
    // reverse_2(arr,0);
    // display(arr,arr.size()-1);

    // cout<<fib(7);
    // 1,1,2,3,5,8,13

    // print_name("ARYAN_SHUKLA", 5);

    // one_n(5);
    // n_one(5);

    // cout << sum_of_first_n_numbers(5);

    // string s="ABBCCBBAg";
    // cout<<palindrome(s);
}
