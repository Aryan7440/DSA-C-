#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
    int max_freq;
    unordered_map<int, stack<int>> stacks;
    unordered_map<int, int> freq;

public:
    FreqStack()
    {
        max_freq = 0;
    }
    void push(int val)
    {
        freq[val]++;
        if (freq[val] > max_freq)
            max_freq = freq[val];
        stacks[freq[val]].push(val);
    }

    int pop()
    {
        int temp = stacks[max_freq].top();
        stacks[max_freq].pop();
        if (stacks[max_freq].empty())
            max_freq--;
        freq[temp]--;
        return temp;
    }
};

int main()
{
    FreqStack *freqStack = new FreqStack();
    freqStack->push(5); // The stack is [5]
    freqStack->push(7); // The stack is [5,7]
    freqStack->push(5); // The stack is [5,7,5]
    freqStack->push(7); // The stack is [5,7,5,7]
    freqStack->push(4); // The stack is [5,7,5,7,4]
    freqStack->push(5); // The stack is [5,7,5,7,4,5]
    cout<<freqStack->pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout<<freqStack->pop()<<endl;   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout<<freqStack->pop()<<endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout<<freqStack->pop()<<endl;   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
}