#include <iostream>
#include<string>

using namespace std;
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	while(num--)
	{
		string a;
		cin>>a;
		int start,stop;
		cin>>start>>stop;
		for(int i=0;i<stop-start;i++)
		{
			for(int j=start;j<stop-i;j++)
			{
				if(a[j]<a[j+1])
				{
					char temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;

				}
				
			}

		}
		cout<<a<<endl;
	}
}