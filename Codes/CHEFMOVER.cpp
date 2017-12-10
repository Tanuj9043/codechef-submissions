#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
    int t;
    long long n,d,avg,balance,sum,ans,temp_sum,temp_n;
    long long arr[100005];
    bool f;
    scanf("%d",&t);
    while(t--)
    {
        sum=0,ans=0,f=1;
        scanf("%lld %lld",&n,&d);
 
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
            sum+=arr[i];
        }
        if(sum%n!=0)
        {
            printf("-1\n");
            continue;
        }
 
        avg=sum/n;
 
        for(int i=0; i<d; i++)
        {
            temp_sum=0,temp_n=0;
            for(int j=i; j<n; j+=d)
            {
                temp_sum+=arr[j];
                temp_n++;
            }
            if(temp_sum%temp_n!=0)
            {
                f=0;
                break;
            }
            if(temp_sum/temp_n!=avg)
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            printf("-1\n");
            continue;
        }
 
        for(int i=0; i<d; i++)
        {
            balance=0;
            for(int j=i; j<n; j+=d)
            {
                arr[j] = arr[j]-balance;
                balance = avg-arr[j];
                if(balance<0) ans+=(-1*balance);
                else ans+=balance;
            }
            if(balance!=0)
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n",ans);
    }
}
