#include <bits/stdc++.h>
using namespace std;
vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int i = 0;
    int n = words.size();
    vector<string> ans;
    while (i < n)
    {
        int spaces = 0;
        int count = words[i].size();
        int start = i;
        i++;
        while ((count + spaces + words[i].size() + 1) <= maxWidth)
        {
            spaces++;
            count += words[i].size();
            i++;
        }
        int word_count = i - start;
        int extra_spaces = maxWidth - count;

        int remainingSpaces;
        int left = 0;
        int rest = 0;
        if (word_count != 1)
        {
            left = extra_spaces % (word_count - 1);
            rest = extra_spaces / (word_count - 1);
        }
        else
        {
            rest = extra_spaces;
            left = 0;
        }
        string str;
        while (str.size() < maxWidth)
        {
            str = str + words[start];
            start++;
            string r(rest + (left > 0), ' ');
            left--;
            if (str.size() < maxWidth)
                str = str + r;
        }
        ans.push_back(str);
    }
    int k = 0;
    string last = ans.back();
    ans.pop_back();
    string temp;
    while (k < last.size())
    {
        while (k<last.size() && last[k] != ' ')
        {
            temp.push_back(last[k]);
            k++;
        }
        if(temp.size()<maxWidth)temp.push_back(' ');
        while (k<last.size() &&last[k] == ' ')
            k++;
    }

    while (temp.size() < maxWidth)
        temp.push_back(' ');
    ans.push_back(temp);
    return ans;
}
int main()
{
    vector<string> words = {"a"};
    int maxWidth = 1;
    // vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    // int maxWidth = 16;
    // vector<string> words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    // int maxWidth = 20;
    vector<string> ans = fullJustify(words, maxWidth);
    for (auto i : ans)
    {
        cout << "|" << i << "|" << endl;
    }
}