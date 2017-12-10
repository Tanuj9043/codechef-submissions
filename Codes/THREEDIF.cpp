#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define MOD 1000000007
 
int main()
{
    ll t,a,b,c,ans;
 
    cin >> t;
 
    while(t--)
    {
        ll v[3];
        cin >> a >> b >> c;
        v[0]=a;
        v[1]=b;
        v[2]=c;
        sort(v,v+3);
        v[0] = v[0]%MOD;
        v[1] = v[1]%MOD;
        v[2] = v[2]%MOD;
        ans = (((v[0]*(v[1]-1))%MOD)*(v[2]-2))%MOD;
        if(ans<0) ans+=MOD;
        cout << ans << endl;
    }
 
    return 0;
}
