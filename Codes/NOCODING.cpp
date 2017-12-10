#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        long long ans=2;
 
        for(int i=1; i<a.size(); i++)
        {
            ans += (a[i] - a[i-1] + 26) % 26 + 1;
        }
 
        cout << ((ans<=(11*a.size()))?"YES":"NO") << endl;
    }
    return 0;
}
