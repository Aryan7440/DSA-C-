#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;
    char ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (letters[mid] <= target)
            l = mid + 1;
        else
        {
            ans = letters[r];
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<char>letters={'c','f','j'};
    cout<<nextGreatestLetter(letters,'c');
}