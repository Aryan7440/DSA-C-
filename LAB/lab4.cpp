// LAB 4 ARYAN SHUKLA IIITP  112115028

#include <bits/stdc++.h>
using namespace std;

void dis(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void qsort(vector<int> &v, int start, int stop, int &count)
{
    if (start >= stop)
        return;
    int l = start + 1, r = stop;
    int median = start + (stop - start) / 2;
    swap(v[median], v[start]);
    int pivot = start;
    while (l < r)
    {
        while (v[l] <= v[pivot] && l < stop)
        {
            l++;
        }
        while (v[r] > v[pivot])
        {
            r--;
        }
        if(l==r)l++;
        if (l < r)
        {
            swap(v[r], v[l]);
            count++;
        }
    }
    swap(v[r], v[pivot]);
    count++;
    dis(v);
    qsort(v, start, r - 1, count);
    qsort(v, r + 1, stop, count);
}
void display(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<int> v;
    int n;
    cout << "ENTER NUMBER OF INTEGERS:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // vector<int> v = {9, 5, 1, 3, 8, 7, 4, 6, 2};
    dis(v);
    int Scount = 0;
    qsort(v, 0, v.size() - 1, Scount);
    dis(v);
    cout << "TOTAL NUMBER OF SWAPS:" << Scount << endl;
    //-------------------------------------------------QUESTION 2-----------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------

    int m;
    cout << "enter number of columns: ";
    cin >> m;
    cout << "enter no of rows: ";
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(m));
    cout<<"ENTER ELEMENTS:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    unordered_map<int, int> frequncy;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            frequncy[arr[i][j]]++;
        }
    }
    for (auto i : frequncy)
    {
        cout << i.first << "->" << i.second << endl;
    }

    for (auto i : frequncy)
    {
        if (i.second >= 2)
        {
            count++;
            if (count > (n * m) / 2)
            {
                cout << "array is implicitly bound array!" << endl;
                break;
            }
        }
    }

    display(arr);
}
