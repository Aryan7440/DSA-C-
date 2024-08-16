#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    int i=n-1;
    while(i>=0 && ans.size()<C)
    {
        int l=i,r=i;
        ans.push_back(A[i]+B[i]);
        while(ans.size()<C && i-1>=0 && A[i-1]+B[i-1]<=max(A[i]+B[r],B[i]+A[l]))
        {
            if(ans.size()<C &&  A[i]+B[r-1]<A[l-1]+B[i])
            {
                if(ans.size()<C)ans.push_back(A[l-1]+B[i]);
                l--;
            }
            else
            {
                if(ans.size()<C)ans.push_back(A[i]+B[r-1]);
                r--;
            }
        }
        i--;
    }
    return ans;
}
int main()
{
    vector<int> A ={59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 },B = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 };
    int C = 10;
    // vector<int> A ={12,54 },B = {12,54  };
    // int C = 1;
    // 96 (96,93)
    // 96 (96,)
    vector<int> ans=solve(A,B,C);
    for(auto i:ans)cout<<i<<" ";


}