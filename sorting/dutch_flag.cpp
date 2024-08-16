#include <iostream>
#include <vector>
using namespace std;

void DNF(vector <int> &v)
{
    int l=0;
    int m=0;
    int r=v.size()-1;
    while(m<=r)
    {
        if(v[m]==0)
        {
            swap(v[m],v[l]);
            m++;
            l++;
        }
        else if(v[m]==1)
        {
            m++;
        }
        else 
        {
            swap(v[m],v[r]);
            // m++;
            r--;
        }
    }
}
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> a={0 ,1 ,2, 1, 2, 1, 2};
    display(a);
    DNF(a);
    display(a);
}