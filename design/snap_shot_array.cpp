#include <bits/stdc++.h>
using namespace std;
class SnapshotArray
{
public:
    vector<vector<pair<int, int>>> arr;
    int snp;
    SnapshotArray(int length)
    {
        snp = 0;
        arr.resize(length);
        for (int i = 0; i < length; i++)
        {
            arr[i].push_back({0, 0});
        }
    }

    void set(int index, int val)
    {
        if (arr[index][arr[index].size()-1].first== snp)
            arr[index][snp].second = val;
        else
            arr[index].push_back({snp, val});
    }

    int snap()
    {
        snp++;
        return snp - 1;
    }

    int get(int index, int snap_id)
    {
        // return arr[index][snap_id];
        int l = 0, r = arr[index].size() - 1;
        int mid = l + (r - l) / 2;
        int ans = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (arr[index][mid].first > snap_id)
                r=mid-1;
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        return arr[index][ans].second;
    }
};
int main()
{
    // SnapshotArray snapshotArr(3);       // set the length to be 3
    // snapshotArr.set(0, 5);              // Set array[0] = 5
    // cout << snapshotArr.snap() << endl; // Take a snapshot, return snap_id = 0
    // snapshotArr.set(0, 6);
    // snapshotArr.set(0, 9);
    // cout << snapshotArr.get(0, 0) << endl; // Get the value of array[0] with snap_id = 0, return 5

    SnapshotArray a(1);
    cout<<a.snap()<<endl;
    cout<<a.snap()<<endl;
    a.set(0,4);
    cout<<a.snap()<<endl;
    cout<<a.get(0,1)<<endl;
    a.set(0,12);
    cout<<a.get(0,1)<<endl;
    cout<<a.snap()<<endl;
    cout<<a.get(0,3)<<endl;
}
// ["SnapshotArray","snap","snap","set","snap",   "get","set",   "get","snap","get"]
// [[1],[],[],[0,4],[],[0,1],[0,12],[0,1],[],[0,3]]