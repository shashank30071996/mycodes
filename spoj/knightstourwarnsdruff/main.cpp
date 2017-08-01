#include <bits/stdc++.h>

using namespace std;
#define n 5
static int px[8] = {1,1,2,2,-1,-1,-2,-2};
static int py[8] = {2,-2,1,-1,2,-2,1,-1};
bool neighbour(int x, int y, int xx, int yy);
bool limits(int x, int y);
bool isempty(int a[], int x, int y);

bool nextmove(int a[],int *x,int *y);
int getdegree(int a[], int x, int y);
void print(int a[]);
bool findclosetour();
int main()
{
    cout << "Hello world!" << endl;
    srand(time(NULL));
    while(!findclosetour())
    {
     cout<<"executing"<<endl   ;
    }

    return 0;
}
bool findclosetour()
{
    int a[n*n];memset(a,-1,sizeof(a));
    int sx=rand()%n;
    int sy=rand()%n;
    int x=sx,y=sy;
    a[y*n+x]=1;
    for(int i=1;i<n*n-1;i++)
            if(nextmove(a,&x,&y)==0)
            return false;

    if(!neighbour(x,y,sx,sy))
        return false;
        cout<<"print"<<endl;
  print(a);
  return true;
}

bool nextmove(int a[],int *x,int *y)
{
    int minindex=-1;int mindeg=n+1,c,nx,ny;
    int start=rand()%n;

    for(int count=0;count<n;count++)
    {
        int i=(start+count)%n;
        nx=*x+px[i];
        ny=*y+py[i];
        if((isempty(a,nx,ny))&& ((c=getdegree(a,nx,ny))<mindeg))
        {
            minindex=i;mindeg=c;
        }
    }
    if(minindex==-1)
        return false;
    nx= *x+px[minindex];
    ny= *y+py[minindex];
    a[ny*n+nx]=a[(*y)*n+(*x)]+1;
    *x=nx;
    *y=ny;
    return true;
}
int getdegree(int a[], int x, int y)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (isempty(a, (x + px[i]), (y + py[i])))
            count++;

    return count;
}
 bool isempty(int a[], int x, int y)
{
    return (limits(x, y)) && (a[y*n+x] < 0);
}
bool limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < n && y < n));
}
 bool neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < n; ++i)
        if (((x+px[i]) == xx)&&((y + py[i]) == yy))
            return true;

    return false;
}
void print(int a[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d\t",a[j*n+i]);
        printf("\n");
    }
}
