#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> arr;
    vector<int> tree;
    int size;
    int total_sum = 0;
    int create(int l, int r, int ind)
    {
        if (l == r)
            return tree[ind] = arr[l];
        int mid = l + (r - l) / 2;
        int left = create(l, mid, 2 * ind + 1);
        int right = create(mid + 1, r, 2 * ind + 2);
        return tree[ind] = left + right;
    }
    int findSum(int ind, int l, int r, int L, int R)
    {
        if (l == L && r == R)
            return tree[ind];
        int mid = L + (R - L) / 2;
        if (l <= mid && r > mid)
        {
            int left = findSum(2 * ind + 1, l, mid, L, mid);
            int right = findSum(2 * ind + 2, mid + 1, r, mid + 1, R);
            return left + right;
        }
        else if (r <= mid)
            return findSum(2 * ind + 1, l, r, L, mid);
        else if (l > mid)
            return findSum(2 * ind + 2, l, r, mid + 1, R);
        return 0;
    }
    int Rechange(int ind, int l, int r, int L, int R)
    {
        if (l == L && r == R)
            return tree[ind] = arr[l];
        int mid = L + (R - L) / 2;
        if (l <= mid && r > mid)
        {
            int left = Rechange(2 * ind + 1, l, mid, L, mid);
            int right = Rechange(2 * ind + 2, mid + 1, r, mid + 1, R);
            tree[ind] = left + right;
        }
        else if (r <= mid)
            tree[ind] = tree[2 * ind + 2] + Rechange(2 * ind + 1, l, r, L, mid);
        else if (l > mid)
            tree[ind] = tree[2 * ind + 1] + Rechange(2 * ind + 2, l, r, mid + 1, R);
        return tree[ind];
    }

public:
    SegmentTree(vector<int> array)
    {
        arr = array;
        size = array.size();
        tree.resize(4 * size);
        int total_sum = create(0, size - 1, 0);
    }
    int findSum(int l, int r)
    {
        return findSum(0, l, r, 0, size - 1);
    }
    void change(int ind, int val)
    {
        arr[ind] = val;
        total_sum = Rechange(0, ind, ind, 0, size - 1);
    }
};
int main()
{
    vector<int> arr = {1, 3, -2, 8, -7};
    SegmentTree seg(arr);
    cout << seg.findSum(2, 3) << endl;
    seg.change(2, 2);
    cout << seg.findSum(2, 3) << endl;
}