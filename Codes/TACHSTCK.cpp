#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n,d,a;
    vector<ll> v;
    cin >> n >> d;
 
    for(int i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
 
    sort(v.begin(),v.end());
 
    int res=0;
    for(int i=0; i<n-1;)
    {
        if(v[i+1]-v[i] <= d)
        {
            res++;
            i+=2;
        }
        else i++;
    }
 
    cout << res;
    return 0;
}
