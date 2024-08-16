#include <bits/stdc++.h> 
using namespace std;
vector<int> findNonRepeating(vector<int> a)
{
	// Write Your Code Here.
	int res=a[0];
	for(int i=1;i<a.size();i++)res=res^a[i];

	int count=0;
	int i=0;
	while(((1<<count)&res )==0)count++;

	int num=1;
	for(auto i:a)
	{
		if(((1<<count)&i)!=0)num=num^i;
	}
	num=num^1;

	int num2=num;
	for(auto i:a)num2=num2^i;

	return {num,num2};
}
// 0011
// 0110

int main()
{
    vector<int> a={3 ,6 ,2 ,2 ,5 ,5};
    vector<int> ans=findNonRepeating(a);
    cout<<ans[0]<<" "<<ans[1];
}