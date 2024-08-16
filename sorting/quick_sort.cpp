#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int> &v, int start, int stop)
{
    if (start >= stop)
        return;
    int l = start + 1, r = stop;
    int pivot = start;
    while (l <= r)
    {
        if (v[pivot] > v[l])
        {
            swap(v[pivot], v[l]);
            pivot = l;
            l++;
        }
        else // if (v[pivot]<v[l])
        {
            swap(v[l], v[r]);
            r--;
        }
    }
    sort(v, start, pivot - 1);
    sort(v, pivot + 1, stop);
}

void qsort(vector<int> &v, int start, int stop)
{
    if (start >= stop)
        return;
    int l = start + 1, r = stop;
    int pivot = start;
    while (l <= r)
    {
        while (v[l] <= v[pivot] && l<=stop)
        {
            l++;
        }
        while (v[r] > v[pivot])
        {
            r--;
        }
        if(l<=r)swap(v[r], v[l]);
    }
    swap(v[r],v[pivot]);
    qsort(v, start, r - 1);
    qsort(v, r + 1, stop);
}
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {2,2,1,3,4,4,1};
    display(a);
    qsort(a, 0, a.size() - 1);
    display(a);
}