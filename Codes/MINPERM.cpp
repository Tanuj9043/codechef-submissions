#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n&1)
        {
            for(int i=1; i<=n-4; i+=2)
            {
                printf("%d %d ",i+1,i);
            }
            printf("%d %d %d",n-1,n,n-2);
        }
        else
        {
            for(int i=1; i<=n-1; i+=2)
            {
                printf("%d %d ",i+1,i);
            }
        }
        printf("\n");
    }
    return 0;
}
