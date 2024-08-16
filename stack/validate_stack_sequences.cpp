#include <bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0, j = 0;

    int n = popped.size();
    while (j < n && i < n)
    {
        while (i < n && pushed[i] != popped[j])
        {
            st.push(pushed[i++]);
        }
        if(i!=n)st.push(pushed[i++]);
        while (j < n && !st.empty() && popped[j] == st.top())
        {
            st.pop();
            j++;
        }
        // if (i!=n && j!=n &&pushed[i] != popped[j])
        //     return false;
    }
    while (j < n && !st.empty() && popped[j] == st.top())
    {
        st.pop();
        j++;
    }
    return j == n;
}
int main()
{
    // vector<int> pushed = {0,2,1}, popped = {0,1,2};
    // vector<int> pushed = {1, 0}, popped = {1, 0};
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 3, 5, 1, 2};
    cout << validateStackSequences(pushed, popped);
}