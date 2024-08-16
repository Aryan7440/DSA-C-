#include<bits/stdc++.h>
using namespace std;


void display(vector<vector<int>> interval)
{
    for (auto i : interval)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
static bool comp(vector<int> v1,vector<int> v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if(intervals.size()==0)return 0;
        int count=0;
        sort(intervals.begin(),intervals.end(),comp);
        int temp=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(temp>intervals[i][0])count++;
            else temp=intervals[i][1];
        }
        return count;
        
    }
int main()
{
    vector<vector<int>> intervals={{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout<<eraseOverlapIntervals(intervals);

}