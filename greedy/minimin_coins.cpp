#include <bits/stdc++.h>
using namespace std;

vector<int> minPartition(int N)
{
    vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> output;
    for (int i = 0; i < notes.size(); i++)
    {
        if (N == 0)
            break;
        else if (N % notes[i] == N)
            continue;
        else
        {
            int temp = N / notes[i];
            for (int j = 0; j < temp; j++)
            {
                N = N % notes[i];
                output.push_back(notes[i]);
            }
            // i--;
        }
    }
    return output;
}

int main()
{
    vector<int> ans = minPartition(43);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}