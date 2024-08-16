#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    MedianFinder()
    {
    }
    double findMedian()
    {
        int L = l.empty() ? 0 : l.top();
        int R = r.empty() ? 0 : r.top();
        double median = ((l.size()+r.size())%2==0)?((double)(L + R) / 2):R;
        return median;
    }

    void addNum(int num)
    {
        double mid=findMedian();
        if(num>mid)r.push(num);
        else l.push(num);
        while (l.size() < r.size())
        {
            l.push(r.top());
            r.pop();
        }
        while (r.size() < l.size())
        {
            r.push(l.top());
            l.pop();
        }
    }
};
int main()
{
    MedianFinder medianFinder ;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    cout<<medianFinder.findMedian()<<endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    cout<<medianFinder.findMedian()<<endl; // return 2.0
    medianFinder.addNum(3); 
    cout<<medianFinder.findMedian()<<endl;   
    medianFinder.addNum(4);  
    cout<<medianFinder.findMedian()<<endl;  
    medianFinder.addNum(5);  
    cout<<medianFinder.findMedian()<<endl;  
    medianFinder.addNum(6);  
    cout<<medianFinder.findMedian()<<endl;  
}