
#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
    int t,n,c;
    bool f;
    int arr[105];
    scanf("%d",&t);
    while(t--)
    {
        f=1,c=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]>7) f=0;
            if(arr[i]==7) c++;
        }
        if(f==0 || arr[0]!=1 || n<13 || c==0)
        {
            printf("no\n");
            continue;
        }
 
        if(arr[0]!=arr[n-1])
        {
            printf("no\n");
            continue;
        }
        for(int i=1; i<n/2; i++)
        {
            if(arr[i]==arr[n-i-1] && arr[i]>=arr[i-1]) continue;
            else
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            printf("no\n");
            continue;
        }
        printf("yes\n");
    }
}
