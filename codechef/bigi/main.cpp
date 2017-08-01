#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		int a[200];
		int size=1;a[0]=1;int i,d,temp;ll p=1;
		while(p<=n)
		{
			i=0;temp=0;
		while(i<size)
		{


			ll pro=a[i]*p+temp;
		     d=pro%10;
		     a[i]=d;
			temp=pro/10;
			i++;
		}
		while(temp)
		{
		  d=temp%10;
		  a[size]=d;
		  temp=temp/10;size++;
		}
		p++;
		}
		for(i=size-1;i>=0;i--)
		cout<<a[i];
		cout<<endl;
	}

	return 0;
}

