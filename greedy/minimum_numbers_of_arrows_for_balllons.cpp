#include <bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int arrows = 1;
    int prev = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > prev)
        {
            arrows++;
            prev=points[i][1];
        }
        else prev=min(prev,points[i][1]);
    }

    return arrows;
}

int main()
{
    vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    cout << findMinArrowShots(points);
}