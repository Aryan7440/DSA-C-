#include <iostream>
#include <vector>
using namespace std;

vector<long long> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
    vector<long long> ans;
    long prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    for(int i=0;i<q;i++)
    {
        long left=((queries[i][0]-1)/n)*prefix[n]+prefix[(queries[i][0]-1)%n];
        long right=((queries[i][1]/n)*prefix[n])+prefix[(queries[i][1])%n];
        ans.push_back(right-left);     
    }
    return ans;
    
}

int main()
{
    // vector<vector<long long>> qu={}


}

