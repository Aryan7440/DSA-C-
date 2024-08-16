#include<bits/stdc++.h>
using namespace std;
void findMaxSubArrayIndex()
{
    int n;
    int start = 0, end = 0, curr_max = 0, prev_max = 0, start_o = 0, i;
    cout << "enter NUMBER of elements:";
    cin >> n;
    vector<int> a(n);
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    prev_max = a[0];

    for (i = 0; i < n; i++)
    {
        curr_max += a[i];
        if (curr_max < 0)
        {
            start = i + 1;
            curr_max = 0;
        }
        else if (curr_max > prev_max)
        {
            end = i;
            start_o = start;
            prev_max = curr_max;
        }
    }
    cout << "start index=" << start_o << endl;
    cout << "end index=" << end << endl;
    int SUM=0;
    for (int i = start_o; i <= end; i++)
    {
        SUM+=a[i];
    }
    cout<<"sum is: "<<SUM<<endl;
    
}
int main()
{
    findMaxSubArrayIndex();
}