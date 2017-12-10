#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n,m,check=0,ans=0,cnt=0;
    int h;
 
    pair< long long, long long > v[100000 + 5];
 
    cin >> n >> m >> h;
 
    for(int i=0; i<h; i++)
    {
        cin >> v[i].second >> v[i].first;
    }
 
    sort(v,v+h);
 
    for(int i=0; i<h; i++ )
    {
        if (cnt + v[i].second < n * m)
            ans += v[i].second * v[i].first, cnt += v[i].second;
        else
        {
            ans += (n * m - cnt) * v[i].first;
            cout << ans << "\n";
            return 0;
        }
    }
 
    cout << "Impossible\n";
    return 0;
}
