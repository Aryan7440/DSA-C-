#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> v1, vector<int> v2)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size())
    {
        ans.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        ans.push_back(v2[j]);
        j++;
    }
    return ans[ans.size() / 2];
}

int median(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return median(b, a);
    int n1 = a.size();
    int n2 = b.size();
    int start = 0, stop = n1;

    while (start <= stop)
    {
        int p1 = (start + stop)>>1;
        int p2 = (n1 + n2 + 1) / 2 - p1;
        int l1 = (p1 == 0) ? INT_MIN : a[p1 - 1];
        int l2 = (p2 == 0) ? INT_MIN : b[p2 - 1];

        int r1 = (p1 == n1) ? INT_MAX : a[p1];
        int r2 = (p2 == n2) ? INT_MAX : b[p2];

        if(l1<=r2 && l2<=r1)
        {
            if((n1+n2)%2==0)
            {
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else
            {
                return max(l1,l2);
            }
        }
        else if(l1>r2)
        {
            stop=p1-1;
        }
        else
        {
            start=p1+1;
        }
    }
    return 0.0;
}

int main()
{
    vector<int> a = {1,3};
    vector<int> b = {2}; // 0  1  2  3  3  5  6  7  7  8
    // vector<int> a = {1, 2, 3, 7, 8, 9};
    // vector<int> b = {0, 3, 5, 6, 7}; // 0  1  2  3  3  5  6  7  7  8
    cout << brute(a, b)<<endl;
    cout << median(a, b)<<endl;

}