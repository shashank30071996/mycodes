#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        cin>>m;
        priority_queue<int> pq;
        queue< pair<int,int> > q;

        int i;int k;
        for(i=0;i<n;i++)
        {
            cin>>k;q.push(make_pair(k,i));pq.push(k);
        }k=0;
        while(!q.empty())
		{
			int first=q.front().first;
			int second=q.front().second;
			q.pop();
			if(first!=pq.top())
			{
				q.push(make_pair(first,second));
			}
			else
			{
				k++;
				pq.pop();
				if(second==m)break;
			}
		}
		printf("%d\n",k);
    }

}
