#include <vector>
#include <iostream>
using namespace std;
void display(vector<int> v)
{
    for (auto i : v)
    {
        cout << i<<" ";
    }
    cout << endl;
}
int main()
{
    vector<int> v={1,2,3,45,6,7};
    display(v);
    v.erase(v.begin()+3,v.begin()+5);
    // cout << sizeof(v)/4<<endl;
    // cout<<"size:"<<v.size()<<endl;

    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    display(v);
    // cout<<"size:"<<v.size()<<endl;
    cout << sizeof(v)/4<<endl;
}