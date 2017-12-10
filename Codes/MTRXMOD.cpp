#include <bits/stdc++.h>
using namespace std;
 
int arr[1005]={0},A[1005][1005];
int n,q,p;
 
void calc()
{
    for(int i=0; i<n; i++) arr[i]=A[i][0];
    int idx=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            idx=i;
            break;
        }
    }
    arr[idx]*=-1;
    for(int i=idx+1; i<n; i++)
    {
        if(arr[i]-arr[idx]==A[i][idx] || arr[idx]-arr[i]==A[i][idx]){}
        else arr[i]*=-1;
    }
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    printf("\n");
    return;
}
 
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&A[i][j]);
            arr[i]=A[i][j];
        }
    }
    calc();
 
    while(q--)
    {
        scanf("%d",&p);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&A[i][p-1]);
            A[p-1][i]=A[i][p-1];
        }
        calc();
    }
    return 0;
}
