#include<iostream>
#include<string>
using namespace std;


int main()
{
    string a="110111";
    string b="110111";
    // if (a>b)
    // {
    //     cout<<a;
    // }
    // else
    //     cout<<b;
    int max=0,i=0,max_index=0;
    while (i<2*a.size())
    {
        if (a[i%a.size()]=='1')
        {
            int j=1;
            while (a[(i+j)%a.size()]=='1')
            {
                j++;
                if (max<j)
                {
                    max=j;
                    max_index=i%a.size();
                }
                
            } 
            i=i+j;
        }
        else i++;
        // i=i+j;
    }
    cout<<"index="<<max_index<<endl;
    cout<<"max= "<<max<<endl;
    
    
    
}