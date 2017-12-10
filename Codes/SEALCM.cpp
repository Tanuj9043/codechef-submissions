#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD 1000000007
 
bool p[1010]={0};
int primes[170], F[1010][5];
int cnt=0;
 
void sieve()
{
    p[0]=1,p[1]=1;
	for(int i=2; i<=1000; i++)
    {
        if(p[i]==0)
        {
            primes[cnt++]=i;
            for(int j=2*i; j<=1000; j+=i) p[j]=1;
        }
    }
}
 
ll powmod(ll a, ll b)
{
    if(!a) return 0;
    if(b==1) return a;
 
    ll res = 1;
    while(b)
    {
        if(b&1) res*=(a%MOD);
        res%=MOD;
 
        a*=a;
        if(a>MOD) a%=MOD;
        b>>=1;
    }
    return res%MOD;
}
 
int main()
{
	sieve();
	for(int i=0; i<1010; i++)
    {
        for(int j=0; j<5; j++) F[i][j]=1;
    }
 
    for(int i=1; i<=1000; i++)
    {
        int num=i, in=0;
        for(int j=0; j<cnt; j++)
        {
            int p=1;
            while(num%primes[j]==0)
            {
                p*=primes[j];
                num/=primes[j];
            }
            if(p>1) F[i][in++] = p;
        }
    }
 
    int t,n,m,L,R;
    scanf("%d",&t);
 
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&L,&R);
        ll res=0,A=0,B=0,C=0,D=0;
        int p,q,r,s;
 
        for(int i=L; i<=R; i++)
        {
            p=F[i][0];
            q=F[i][1];
            r=F[i][2];
            s=F[i][3];
 
            A=powmod(m-m/p,n)+powmod(m-m/q,n)+powmod(m-m/r,n)+powmod(m-m/s,n);
            A%=MOD;
 
            B=powmod(m-m/p-m/q+m/(p*q),n)+powmod(m-m/q-m/r+m/(q*r),n)+powmod(m-m/r-m/s+m/(r*s),n)+powmod(m-m/p-m/r+m/(p*r),n)+powmod(m-m/p-m/s+m/(p*s),n)+powmod(m-m/q-m/s+m/(q*s),n);
            B%=MOD;
 
            C=powmod(m-m/p-m/q-m/r+m/(p*q)+m/(q*r)+m/(p*r)-m/(p*q*r),n)+powmod(m-m/p-m/q-m/s+m/(p*q)+m/( p*s)+m/(q*s)-m/(p*q*s),n)+powmod(m-m/s-m/q-m/r+m/(s*q)+ m/(s*r)+m/(q*r)-m/(s*q*r),n)+powmod(m-m/p-m/r-m/s+m/( p*r)+m/(p*s)+m/(r*s)-m/(p*r*s),n);
            C%=MOD;
 
            D=powmod(m-m/p-m/q-m/r-m/s+m/(p*q)+m/(q*r)+ m/(p*r)+m/(r*s)+m/(p*s)+m/(q*s)-m/(p*q*r)-m/(q*r*s)-m/(p*q*s)-m/(p*r*s)+m/(p*q*r*s),n);
            D%=MOD;
 
            res+=(powmod(m,n)-A+B-C+D+2*MOD)%MOD;
            res%=MOD;
        }
        printf("%lld\n",res);
    }
	return 0;
}
