#include <bits/stdc++.h>
using namespace std;
long long matrixSumQueries(int n, vector<vector<int>> &queries)
{
    int cols = n;
    int rows = n;
    unordered_set<int> row,col;
    long long sum = 0;
    for (int i = queries.size() - 1; i >= 0; i--)
    {
        if (rows <= 0 || cols <= 0)
            break;
        int type = queries[i][0];
        int ind = queries[i][1];
        int val = queries[i][2];
        if (type && col.find(ind)==col.end())
        {
            if (rows <= 0)
                break;
            sum += rows * val;
            cols--;
            col.insert(ind);
        }
        else if(type==0 && row.find(ind)==row.end())
        {
            if (cols <= 0)
                break;
            sum += cols * val;
            rows--;
            row.insert(ind);
        }
        // if(q=n*n)break;
    }
    return sum;
}
int main()
{
    vector<vector<int>> queries={{0,6,30094},{0,7,99382},{1,2,18599},{1,3,49292},{1,0,81549},{1,1,38280},{0,0,19405},{0,4,30065},{1,4,60826},{1,5,9241},{0,5,33729},{0,1,41456},{0,2,62692},{0,3,30807},{1,7,70613},{1,6,9506},{0,5,39344},{1,0,44658},{1,1,56485},{1,2,48112},{0,6,43384}};
    cout<<matrixSumQueries(8,queries);
}