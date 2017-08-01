#include <bits/stdc++.h>

using namespace std;
typedef long int ll;
struct Point
{
    ll x;ll y;
};

struct Mn
{
    int m;int n;
};
Mn w;
double convexHull(Point points[],ll num);
int orientation(Point p,Point q,Point r );
int collinear(Point co[],ll n);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;

       Point p[n];ll i=0;double f=0;Mn z;z.m=0;z.n=0;w.m=0;w.n=0;
       while(i<n)
       {
           cin>>p[i].x;cin>>p[i].y;
           z.m =(p[i].x<p[z.m].x)?i:z.m;
           z.n=(p[i].x>p[z.n].x)?i:z.n;
           i++;

       }
         cout<<z.m<<endl;
         cout<<z.n<<endl;
       if(n==1)
        printf("%.2f\n%d\n",0.00,1);
        if(n==2)
       {
           f=sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y))*2;
           printf("%.2f\n",f);
           if(p[0].x<p[1].x)
            printf("%d %d\n",1,2);
           else
            printf("%d %d\n",2,1);
       }
       else
        {  int c=0;
              c=collinear(p,n);
              cout<<w.m<<endl;
              cout<<w.n<<endl;
              cout<<"c:"<<c<<endl;
            if(c==1)
            {
                 f=sqrt((p[z.m].x-p[z.n].x)*(p[z.m].x-p[z.n].x)+(p[z.m].y-p[z.n].y)*(p[z.m].y-p[z.n].y))*2;
                 printf("%.2f\n",f);
                 printf("%d %d\n",z.m+1,z.n+1);
            }
             else if(c==2)
                {
                 cout<<"eneterd"<<endl;
                 f=sqrt((p[w.m].y-p[w.n].y)*(p[w.m].y-p[w.n].y))*2;
                 printf("%.2f\n",f);
                 printf("%d %d\n",w.m+1,w.n+1);
            }
           else if(c == 0)
            convexHull(p,n);

        }

   }
}
double convexHull(Point points[],ll num)
{

    vector<Point> hull;
    vector<int>seq;


    int l,i = 0;
    for ( i = 1; i < num; i++)
      {
        if (points[i].x < points[l].x)
            l = i;
      }

    int p = l, q;
    do
    {

        hull.push_back(points[p]);
        seq.push_back(p);

        q = (p+1)%num;
        for ( i = 0; i < num; i++)
        {

           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }


        p = q;

    } while (p != l);
  double f=0;
  cout<<"conti"<<endl;
    for ( i = 0; i < hull.size()-1; i++)
       {

           cout<<hull[i].x<<" "<<hull[i].y<<endl;
           cout<<f<<endl;
            f=f+sqrt((hull[i].x-hull[i+1].x)*(hull[i].x-hull[i+1].x)+(hull[i].y-hull[i+1].y)*(hull[i].y-hull[i+1].y));
       }
          f=f+sqrt((hull[0].x-hull[i].x)*(hull[0].x-hull[i].x)+(hull[0].y-hull[i].y)*(hull[0].y-hull[i].y));
       cout<<f<<endl;
       printf("%.2f\n",f);
       for( i=0;i<seq.size();i++)
       {
            if(hull[i].x==hull[i-1].x && hull[i].y==hull[i-1].y)
            continue;
            else
                printf("%d ",seq[i]+1);}
            printf("\n");
            return 0;

}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0)? 1: 2;
}
int collinear(Point co[],ll n)
{ int m=0;
  int i=0;int c=0,g=0;m=(co[1].y-co[0].y)/(co[1].x-co[0].x);int flag=m;
    for( i=1;i<n-1 && flag==m;i++)
    {
         if((co[i+1].x-co[i].x)!=0)
        {
        m=(co[i+1].y-co[i].y)/(co[i+1].x-co[i].x);g=1;}

    }
    if(i==n-1 && g!=0)
     c=1;
    else
    {  w.m=0,w.n=0;
        for( i=0;i<n && co[i].x==0;i++)
        {
            cout<<"collinea:"<<w.m<<"   "<<w.n<<endl;
            w.m =(co[i].y<co[w.m].y)?i:w.m;
            w.n=(co[i].y>co[w.n].y)?i:w.n;


        }
        if(i==n)
        c=2;

    }
    return c;
}

