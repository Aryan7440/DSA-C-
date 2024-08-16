#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 1;
        int num = 0;
        while (i < n)
        {
            if (arr[i] < arr[i - 1])
            {
                num = max(num, (arr[i] + arr[i - 1] + 1) / 2);
            }
            i++;
        }
        int flag = 1;
        i = 1;
        while (i < n)
        {
            if (abs(arr[i] - num) < abs(arr[i - 1] - num))
            {
                cout << -1 << endl;
                flag = 0;
                break;
            }
            i++;
        }
        if (flag)
            cout << num << endl;
    }
}