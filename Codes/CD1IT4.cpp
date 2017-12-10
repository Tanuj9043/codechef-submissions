#include <iostream>
#include <stdio.h>
using namespace std;
 
#define MOD 1000000007
int dp[1005][1005];
 
int paths(int n, int m)
{
    if(dp[1][1]==-1) return	0;
 
    for(int i=1; i<=m; i++)
    {
        if(dp[1][i]==-1) break;
        else dp[1][i]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(dp[i][1]==-1) break;
        else dp[i][1]=1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            if(dp[i][j]==-1) continue;
            dp[i][j]=0;
 
            if(dp[i-1][j]!=-1) dp[i][j]=dp[i-1][j]%MOD;
            if(dp[i][j-1]!=-1) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
        }
    }
    if(dp[n][m]==-1) return 0;
    return dp[n][m];
}
 
int main()
{
    int n,m,p,i,j;
    scanf("%d %d %d",&n,&m,&p);
    while(p--)
    {
        scanf("%d %d",&i,&j);
        dp[i][j]=-1;
    }
    printf("%d\n",paths(n,m));
	return 0;
}
