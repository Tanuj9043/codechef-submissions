#include <iostream>
#include <stdio.h>
using namespace std;
 
#include<stdlib.h>
#include<math.h>
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
 
#define M 1000000007
#define ll long long
 
ll pw(ll a,ll b, ll md){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2,md);
  r = (r*r)%md;
  if(b%2) r = (r*a)%md;
  return r;
}
 
int main(){
  int T, N;
  int B;
  ll p, add;
 
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    B = 0;
    p = 0; add = 1;
    while(N){
      if(N%2) p += add;
      add = (add*10) % (M-1);
      N /= 2;
    }
    p = (p*2)%(M-1);
    printf("%d\n",(int)pw(2,p,M));
  }
 
  return 0;
}
