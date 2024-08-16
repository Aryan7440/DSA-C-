#include <bits/stdc++.h>
using namespace std;

void display(vector<int> a)
{
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
void merge(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int gap = ceil((float)(m + n) / 2);
    int i = 0, j = gap - 1;

    while (gap > 1)
    {
        i = 0;
        j = gap - 1;
        while (j < m + n)
        {
            if (i < n && j < n)
            {
                if (a[i % n] > a[j % n])
                {
                    swap(a[i % n], a[j % n]);
                }
                i++;
                j++;
            }
            else if (i < n && j < m + n)
            {
                if (a[i % n] > b[j % n])
                {
                    swap(a[i % n], b[j % n]);
                }
                i++;
                j++;
            }
            else
            {
                if (b[i % n] > b[j % n])
                {
                    swap(b[i % n], b[j % n]);
                }
                i++;
                j++;
            }
        }
        gap = ceil((float)gap / 2);
    }
}

int main()
{
    vector<int> a = {0,2,6,8,9};
    vector<int> b = {1,3,5,7};
    merge(b,a);
    display(a);
    display(b);
    // cout<<ceil((float)7/2);
    // cout<<3%4;
}