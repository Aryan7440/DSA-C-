#include <iostream>
#include <vector>
using namespace std;
vector<int> printArrayAfterKOperations(vector<int> &Arr, int N, int K)
{
    int Max = Arr[0];
    int Min = Arr[0];
    for (int i = 0; i < N; i++)
    {
        Max = max(Max, Arr[i]);
        Min = min(Min, Arr[i]);
    }
    for (int i = 0; i < N; i++)
    {
        Arr[i] = Max - Arr[i];
    }
    Max = Max - Min;
    K--;
    if (K % 2 == 0)
    {
        return Arr;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            Arr[i] = Max - Arr[i];
        }
        return Arr;
    }
}
// vector<int> printArrayAfterKOperations(vector<int> &Arr, int N, int K)
// {
//     while (K > 0)
//     {
//         int Max = Arr[0];
//         for (int j = 0; j < Arr.size(); j++)
//         {
//             Max=max(Arr[j],Max);
//         }
//         for (int i = 0; i < Arr.size(); i++)
//         {
//             Arr[i]=Max-Arr[i];
//         }
//         K--;
//     }
//     return Arr;
// }

int main()
{
    vector<int> a = {20, 15, 10, 5};
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    a = printArrayAfterKOperations(a, a.size(), 2);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
