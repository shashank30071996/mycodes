#include <bits/stdc++.h>

using namespace std;

struct box
{
    int h;int w;int d;
};
void stacking(box b[],int n);
int compare (const void *a, const void * b);
int compare (const void *a, const void * b)
{
    return ( (*(box *)b).d * (*(box *)b).w ) -
           ( (*(box *)a).d * (*(box *)a).w );
}
int main()
{

    int n;
    cin>>n;
    while(n)
    {

        box b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i].h;
            cin>>b[i].w;
            cin>>b[i].d;
        }
        stacking(b, n);
        cin>>n;
    }
    return 0;
}

void stacking(box b[],int n)
{
   box rot[6*n];
   int index=0;
   int i,j;
   for(i=0;i<n;i++)
   {
       rot[index]=b[i];
       index++;
       rot[index].h=b[i].h;
       rot[index].w=b[i].d;
       rot[index].d=b[i].w;
       index++;
       rot[index].h=b[i].w;
       rot[index].w=b[i].h;
       rot[index].d=b[i].d;
       index++;
       rot[index].h=b[i].w;
       rot[index].w=b[i].d;
       rot[index].d=b[i].h;
       index++;
       rot[index].h=b[i].d;
       rot[index].w=b[i].w;
       rot[index].d=b[i].h;
       index++;
       rot[index].h=b[i].d;
       rot[index].w=b[i].h;
       rot[index].d=b[i].w;
       index++;
   }
   n=6*n;
   qsort(rot,n,sizeof(rot[0]),compare);
   int maxh[n];
   for(i=0;i<n;i++)
    maxh[i]=rot[i].h;
   for ( i = 1; i < n; i++ )
  {

      for ( j = 0; j < i; j++ ){
         if ( rot[i].w < rot[j].w &&
              rot[i].d < rot[j].d &&
              maxh[i] < maxh[j] + rot[i].h
            )
         {
              maxh[i] = maxh[j] + rot[i].h;
         }
      }
  }

  int mx=-1;
  for(i=0;i<n;i++)
  {

     if(mx<maxh[i])
    mx=maxh[i];}
    cout<<mx<<endl;

}
