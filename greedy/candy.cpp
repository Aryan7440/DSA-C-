#include <bits/stdc++.h>
using namespace std;

// int caddy(vector<int> &ratings)
// {
//     int n=ratings.size();
//     vector<int> left(n,1);
//     for(int i=0;i<n;i++)
//     {
//         if(i+1<n && ratings[i+1]<ratings[i])
//         {
//             left[i]=left[i+1]+1;
//         }
//     }

//     int right=1;
//     int ans=0;
//     for(int j=n-1;j>=0;j--)
//     {
//         if(j-1>=0 && ratings[j-1]<ratings[j])
//         {
//             right=right+1;
//         }
//         else right=1;
//         left[j]=max(left[j],right);
//         ans=ans+left[j];
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> ratings={1,3,2,6,4,9,3,1};
//     caddy(ratings);
// }

int minCandy(int N, vector<int> &ratings)
{
    // code here
    vector<int> c(N, 1);
    for (int i = 1; i < N; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            c[i] = c[i - 1] + 1;
        }
    }
    vector<int> c2(N, 1);
    for (int i = N - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            c2[i] = c2[i + 1] + 1;
        }
    }
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        count = count + max(c[i], c2[i]);
    }
    return count;
}

int main()
{
    vector<int> ratings = {766, 469, 980, 480, 472, 80, 612, 559, 476, 250};
    cout<<minCandy(10,ratings);
}