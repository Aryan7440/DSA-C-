#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int *new_dynamic_ptr(int size)
{
    int *a = (int *)calloc(size, 4);
    return a;
}

int* new_dyn_pointer(int size)
{
    int *ptr= new int[5];
    return ptr;
}

void display(int* ptr,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<ptr+i<<" ";
    }cout<<endl;
    
}
int main()
{
    int n;
    cin >> n;
    int *p = new_dynamic_ptr(n);
    int *pt=new_dyn_pointer(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pt[i] ;
    }

    display(pt,n);
    display(p,n);
    

    // cout << *(p + 6);              //out of pointer
    // free(p);
    delete [] pt;
    // cout << *(pt + 4);

    // char n[6] = "aryan";
    // string x = "shukla";
    // char a = 'a';
    // // cin>>n;
    // char *p ;
    // p=n;
    // cout << p<<endl;                                          // it will print the whole string as cout function takes addres and prints upto null character
    // cout << strlen(n) << " " << x.size();

    return 0;
}