#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
 
const int N = 70;
const int M = 150;
const int Mod = 1000000007;
int n;
int val[N+1][M][M];
int xu[N+5];
 
int f()
{
	int i,j,k,l;
	scanf("%d",&n);
 
	memset(xu,0,sizeof xu);
	for(i=1;i<=n;i++) scanf("%d",&xu[i]);
	memset(val,0,sizeof val);
 
	val[0][xu[1]][xu[2]]=1;
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			for(k=0;k<M;k++)
			{
				if(val[i][j][k])
				{
					for(l=0; l<=j && l<=k; l++){
						val[i+1][k-l][xu[i+3]+l] = (val[i+1][k-l][xu[i+3]+l]+val[i][j][k])%Mod;}
				}
			}
		}
	}
	return val[N][0][0];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		printf("%d\n",f());
	}
	return 0;
}
