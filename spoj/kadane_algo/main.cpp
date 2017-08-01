#include <bits/stdc++.h>

using namespace std;
 int row; int col;

void maxsubarray(int ** a);
int kadane(int *arr,int *s,int *f,int n);

int main()
{
    cout << "Hello world!" << endl;
    cin>>row;cin>>col;
    int a[row][col];
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cin>>a[i][j];

    }


    int maxsum=INT_MIN,sum=0,finalleft,finalright,finaltop,finalbottom;
    int l,r,s,f,temp[row];
    for(l=0;l<col;l++)
    {   memset(temp,0,sizeof(temp));
        for(r=l;r<col;r++)
        {
            for(i=0;i<row;i++)
                temp[i]=temp[i]+a[i][r];
            sum=kadane(temp,&s,&f,row);
            if(maxsum<sum)
            {
                maxsum=sum;
                finalleft=l;
                finalright=r;
                finaltop=s;
                finalbottom=f;
            }
        }
    }
    printf("maxsum is %d  finalleft:%d  finalright:%d  finaltop:%d  finalbottom:%d  ",maxsum,finalleft,finalright,finaltop,finalbottom);
}


int kadane(int *arr,int *s,int *f,int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *f = -1;

    // local variable
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *s = local_start;
            *f = i;
        }
    }

     // There is at-least one non-negative number
    if (*f != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *s = *f = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *s = *f = i;
        }
    }
    return maxSum;
}
