#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
 
using	namespace	std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k,m,a;
        cin >> n >> k >> m;
 
        int A[100000];
        for(int i=0; i<n; cin >> A[i++]){}
 
        for(int i=0; i<n; i++)
        {
            cin >> a;
            A[i] -= a;
        }
 
        multiset<int> s;
        for(int i=0; i<k+m; i++)
        {
            cin >> a;
            s.insert(a);
        }
 
        sort(A,A+n);
 
        long long int ans=0;
        auto x=s.begin();
 
        for(int i=0; i<n; i++)
        {
            if(s.empty() or *s.begin() > A[i])
				ans += A[i];
			else
			{
				x = s.upper_bound(A[i]);
				x--;
 
				ans += A[i] - (*x);
				s.erase(x);
			}
        }
        cout << ans << endl;
    }
    return 0;
}
