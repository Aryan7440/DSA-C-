#include<iostream>
#include<string>
using namespace std;


int main()
{
    // int *ptr;
    // ptr=new  int;
    // *ptr=5;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;


    char *ptr;
    // char a[6]="aryan";
    // ptr=new char[6];
    // ptr=a;
    // cout<<(ptr)<<endl;
    // delete []ptr;


    ptr=new char[12];
    char p[]="aryanshukla";             //ptr="aryanshukla"  will be wrong becase its a string literal(in data segment) while p[]makes a copy in stack
    ptr=p;
    
    cout<<ptr[5];

    // string *ptr;
    // ptr=new string[20];
    // *ptr="aryanshukla";
    // cout<<*ptr;


}