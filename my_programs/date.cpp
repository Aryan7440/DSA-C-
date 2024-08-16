#include <iostream>
#include <vector>
using namespace std;

vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int date_days(int dd, int mm, int yyyy)
{
    int time = 0;
    for (int i = 0; i <= yyyy; i++)
    {
        if (i % 4 == 0 && i % 100 != 0)
            time++;
        else if (i % 4 == 0 && i % 400 == 0)
            time++;
        time = time + 365;
    }
    for (int i = 1; i < mm; i++)
    {
        time=time+month[i];
    }
    time=time+dd;
}