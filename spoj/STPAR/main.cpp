#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   scanf("%d",&n);
   while(n!=0)


   {
       int i=0;queue<int> q;int k;
       for(i=0;i<n;i++)
        {
            scanf("%d",&k);q.push(k);
        }
       stack<int> st;
       int c=1;
      while(!q.empty() || !st.empty())
       {
            if(!q.empty() && q.front()==c){
                q.pop();c++;
            }
          else
          {if( !st.empty() && st.top()==c)
            {

                c++;
                st.pop();
            }
           else{
                    if(!q.empty()){
                    //printf("Q\n");
                        int s=q.front();
                        st.push(s);
                        q.pop();
                    }

           else
           {
               break;
           }
       }}}



       if(c==n+1)
        cout<<"yes"<<endl;
       else
        cout<<"no"<<endl;
    cin>>n;
   }

}


