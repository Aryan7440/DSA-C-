#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int i = 0, j = 0;
    vector<vector<int>> ans;
    while (i < firstList.size() && j < secondList.size())
    {
        if (firstList[i][1] < secondList[j][0])
        {
            i++;
        }
        else if (secondList[j][1] < firstList[i][0])
        {
            j++;
        }
        else
        {
            int start = max(firstList[i][0], secondList[j][0]);
            int stop = min(firstList[i][1], secondList[j][1]);
            ans.push_back({start, stop});
            if (secondList[j][1] > firstList[i][1])
                i++;
            else
                j++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}}, secondList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> output=intervalIntersection(firstList,secondList);
    for(auto i:output)
    {
        cout<<"["<<i[0]<<","<<i[1]<<"], ";
    }
}