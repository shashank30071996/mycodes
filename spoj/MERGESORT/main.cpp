#include <bits/stdc++.h>

using namespace std;
void mergesort(int arr[],int l,int r);
void merging(int arr[],int l,int m,int r);
void print(int arr[],int n);
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
    mergesort(arr,0,n-1);
    print(arr,n);

    return 0;
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merging(arr,l,m,r);
    }
}

void merging(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int i=0,j=0,k=l;
    int a[n1];int b[n2];
    for(i=0;i<n1;i++)
        a[i]=arr[l+i];
    for(i=0;i<n2;i++)
        b[i]=arr[m+1+i];
        i=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];i++;
        }
        else
        {
            arr[k]=b[j];j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=a[i];i++;k++;
    }
    while(k<n2)
    {
        arr[k]=b[j];j++;k++;
    }

}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
