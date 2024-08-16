#include <bits/stdc++.h>
using namespace std;

vector<int> previous_least_element_index(const std::vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);

    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            result[i] = st.top();
        }
        st.push(i);
    }

    return result;
}
vector<int> next_least_element_index(const std::vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, n);

    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return result;
}
int main()
{
    vector<int> arr = {3, 2, 1, 4};
    vector<int> result = previous_least_element_index(arr);
    vector<int> result2 = next_least_element_index(arr);

    // Print the result
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result2[i] << " ";
    }

    return 0;
}
