#include <bits/stdc++.h>

using namespace std;
int part(int arr[],int l,int r);void quicksort(int arr[],int l,int r);void swap(int *a,int *b);
int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
     {

       cin>>arr[i];
    }
    int a=5;int b=6;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    quicksort(arr,0,n-1);
    for(i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p = part(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}

int part(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return(i+1);
}
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
