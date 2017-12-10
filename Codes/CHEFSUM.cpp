#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,n,in;
    int arr[100005];
    long long pre[100005],suf[100005],min=1000000000000;
    scanf("%d",&t);
    while(t--)
    {
        min=1000000000000;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            if(i==0) pre[0]=arr[i];
            else pre[i]=pre[i-1]+arr[i];
        }
        suf[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suf[i]=suf[i+1]+arr[i];
        }
        for(int i=0; i<n; i++)
        {
            if(pre[i]+suf[i]<min)
            {
                min=pre[i]+suf[i];
                in=i;
            }
        }
        printf("%d\n",(in+1));
    }
    return 0;
}
