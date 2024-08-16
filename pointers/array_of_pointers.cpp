#include <iostream>
using namespace std;

int main()
{
    //  https://www.geeksforgeeks.org/pointer-array-array-pointer/?ref=lbp
    int(*p)[6]; // 6 arrays whose 1st element is pointed by p[0],p[1].......
    int(*pt)[6];
    int b[6][6] = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36}};
    int a[] = {1, 2, 3, 4, 5, 6};
    p = &a;
    pt = b;
    int *ptr = a;

    for (int i = 0; i < 6; i++)
    {
        // printf("%d ", pt++);                   //24 intervals b[0],b[1]...
        // printf("%d ", pt+i);                   //24 intervals b[0],b[1]...
        // printf("%d ", b[i]);                   //24 intervals b[0],b[1]...
    }
    cout << endl;

   
    // cout<<(p[0][0])<<endl;             //p[0]=a
    // printf("%d \n",p[0]);                //address 0f a or value of p[0]
    // printf("%d \n",p[1]);                //address 0f a or value of p[1]
    // printf("%d \n",a);                   //address 0f a or value of p[0]
    for (int i = 0; i < 6; i++)
    {
        // printf("%d ",a+i);                    //prints address in 4 intervals
        // printf("%d ",ptr++);                    //prints address in 4 intervals
        // printf("%d ",*p+i);                   //prints address in 4 intervals
        // printf("%d ",p[0]+i);                 //prints address in 4 intervals
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        // printf("%d ", p + i); // prints address in 24 intervals
        // printf("%d ",p[i]);                       //prints address in 24 intervals
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        // printf("%d ",*(*p+i));                        //prints value of array
    }
}