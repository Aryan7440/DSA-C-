#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int *getProductArrayExceptSelf(int *arr, int n) // 1st
{
    int product = 1;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
            continue;
        }
        product = product * (arr[i] % mod);
        product = product % mod;
    }
    int *ans = new int[n];
    if (zeros > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 && zeros == 1)
                ans[i] = product;
            else
                ans[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans[i] = product / arr[i];
        }
    }
    return ans;
}

vector<int> prefix(vector<int> &v)
{
    int product = 1;
    vector<int> ans(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        ans[i] = product;
        product = product * v[i];
    }
    return ans;
}
vector<int> suffix(vector<int> v)
{
    vector<int> ans(v.size());
    int product = 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans[i] = product;
        product = product * v[i];
    }
    return ans;
}
vector<int> product_except_self(vector<int> v)
{
    vector<int> pre = prefix(v);
    vector<int> suf = suffix(v);
    vector<int> ans(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        ans[i] = pre[i] * suf[i];
    }
    return ans;
}

vector<int> get_Product_array_except_self(vector<int> v)
{
    vector<int> output(v.size());
    int product = 1;
    for (int i = 0; i < v.size(); i++)
    {
        output[i] = product;
        product = (product % mod) * (v[i] % mod);
        product = product % mod;
    }
    product = 1;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        output[i] = ((product % mod) * (output[i] % mod));
        product = (product % mod) * (v[i] % mod);
        product = product % mod;
    }
    return output;
}
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 4, 5, 1, 6, 0};
    int n = arr.size();
    // int *ans = getProductArrayExceptSelf(arr, n);
    display(arr);
    vector<int> s = suffix(arr);
    display(s);
    vector<int> p = prefix(arr);
    display(p);
    vector<int> ans = product_except_self(arr);
    display(ans);
    vector<int> ans2 = get_Product_array_except_self(arr);
    display(ans2);
}
