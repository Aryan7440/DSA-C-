

#include <bits/stdc++.h> 
using namespace std;

int at(long long i,long long N)
{
	if((1<<i)& N)return 1;
	return 0;
}
bool checkPalindrome(long long N)
{
	// Write your code here.
	long long p=31;
	while(((1<<p)&N)==0)p--;

	long long r=0;
	while(p>r)
	{
		if(at(p,N)!=at(r,N))
		{
			return false;
		}
		r++;
		p--;
	}
	return true;
}

int main()
{
    long long N=5726623061;
    cout<<checkPalindrome(N);
}
