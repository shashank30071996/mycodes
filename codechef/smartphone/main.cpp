#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void quicksort( ll  arr[],ll left,ll right);
int main()
{
    ll n;
    cin>>n;
    ll a[n];ll i;
    for( i=0;i<n;i++)
        cin>>a[i];
      quicksort(a,0,n-1);
      for( i=0;i<n;i++)
        cout<<a[i]<<endl;
      if(n%2==0)
      i=(n-1)/2;
      else
        i=n/2;
      ll p;ll cost;
      cost=max((a[i]*(n-i)),a[i+1]*(n-i-1));
      cost=max(cost,a[i-1]*(n-i+1));
      if(cost==a[i])
        p=n-i;
      else
         p=n-i-1;
      cout<<(cost)<<endl;



}


void quicksort(ll arr[], ll left, ll right) {
      ll i = left, j = right;
      ll tmp;
      ll pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quicksort(arr, left, j);
      if (i < right)
            quicksort(arr, i, right);
}
