#include <iostream>
#include <vector>

using namespace std;

void computeLPS(string pattern, vector<int> &lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearchAll(string text, string pattern, int l, int r)
{
    vector<int> occurrences;
    int n = text.length();
    int m = pattern.length();

    if (m == 0)
    {
        return occurrences; // Empty pattern, invalid input
    }

    if (r >= n || l < 0 || l > r)
    {
        return occurrences; // Invalid range indices
    }

    vector<int> lps(m, 0);
    computeLPS(pattern, lps);

    int i = l; // Index in the text
    int j = 0; // Index in the pattern

    while (i <= r && i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;

            if (j == m)
            {
                occurrences.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return occurrences;
}

int main()
{
    string text = "ababcababcabcaba";
    string pattern = "aba";
    int l = 0;  // Starting index (zero-based)
    int r = 11; // Ending index (zero-based)

    vector<int> occurrences = KMPSearchAll(text, pattern, l, r);

    if (!occurrences.empty())
    {
        cout << "Pattern found at indices: ";
        for (int idx : occurrences)
        {
            cout << idx << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Pattern not found in the given range." << endl;
    }

    return 0;
}
