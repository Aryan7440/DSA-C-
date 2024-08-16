#include <iostream>
using namespace std;

class copying1
{

public:
    int a;
    int *ptr;

    copying1(int A, int *o)
    {
        a = A;
        ptr = new int(*o);
    }
    copying1()
    {
        a = 0;
        ptr = new int(0);
    }
    ~copying1()
    {
        delete ptr;
    }
    void shallow(copying1 &obj)
    {
        a = obj.a;
        ptr = obj.ptr;
    }
    void deep(copying1 &obj)
    {
        a = obj.a;
        ptr = new int;
        *ptr = *(obj.ptr);
    }
    void display()
    {
        cout << a << endl;
        cout << *ptr << endl;
    }
};

class c
{
public:
    c()
    {
        inte = NULL;
    }
    c(int &n)
    {
        inte = &n;
        // *inte = n;
    }

    int *inte;
};

int main()
{
    copying1 b, a_shallow, a_deep;
    b.a = 15;
    *b.ptr = 30;
    b.display();
    cout<<endl;

    a_shallow.shallow(b);
    a_deep.deep(b);
    cout<<endl;

    *(a_shallow.ptr) = 45;
    a_shallow.a=150;
    b.display();
    cout<<endl;

    *(a_deep.ptr) = 60;
    b.display();
    cout<<endl;

    cout << "\n";
    a_deep.display();
    cout<<endl;


    cout << "\n";
    a_shallow.display();
    cout<<endl;

    // int p = 90;
    // c a;
    // c b(p);

    // a.inte = &p;
    // cout << *(a.inte) << endl;
    // cout << *(b.inte) << endl;

    // *a.inte = 45;
    // cout << *(a.inte) << endl;
    // cout << *(b.inte) << endl;
    // cout << p << endl;
}
