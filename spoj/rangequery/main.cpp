#include <bits/stdc++.h>

using namespace std;
int parent(int i);void insert(int val);void swap(int *a,int *b);
int extractmin();void decreasekey(int i,int newval);void remove(int i);void heapify(int i);void print();
int heapsize;
int capacity;
int *heap;int n;
int main()
{
    cout << "Hello world!" << endl;

    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    heap=new int[n];
    heapsize=0;
    capacity=n;
    for(int i=0;i<n;i++)
        insert(a[i]);
     print();
     extractmin();
     print();
    return 0;
}
void print()
{
     for(int i=0;i<n;i++)
        cout<<heap[i]<<endl;
}
void insert(int val)
{
    if(heapsize==capacity)
        printf("overflow");
    else if(heapsize==0)
    {
        heapsize++;heap[0]=val;
    }
    else
    {
        int i=heapsize;heapsize++;heap[i]=val;
        while(i!=0 && heap[parent(i)]>heap[i])
        {
            swap(&heap[parent(i)],&heap[i]);
            i=parent(i);
        }

    }
}
 int parent(int i) { return (i-1)/2; }
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;*b=t;
}
void decreasekey(int i,int newval)
{
    heap[i]=newval;
    while(i!=0 && heap[parent(i)]>heap[i])
    {
        swap(&heap[parent(i)],&heap[i]);
        i=parent(i);
    }
}
void remove(int i)
{
    decreasekey(i,INT_MIN);
    extractmin();
}
void heapify(int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<heapsize && heap[l]<heap[smallest])
        smallest=l;
    if(r<heapsize && heap[r]<heap[smallest])
        smallest=r;
    if(smallest!=i)
    {
        swap(&heap[i],&heap[smallest]);
        heapify(smallest);
    }
}

int extractmin()
{
    if(heapsize<=0)
        return INT_MAX;
    if(heapsize==1)
    {
        heapsize--;
       return heap[0];
    }
  else{  int root=heap[0];
    heap[0]=heap[heapsize-1];
    heapsize--;
    heapify(0);
    return root;
}
}
