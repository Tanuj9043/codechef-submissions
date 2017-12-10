#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;
        int n = a.length();
        for(int i= 0; i< n ; i++)
		{
			if(a[i] != b[i])
				cout<<"B";
			else
			{
				if(a[i] == 'B')
					cout<<'W';
				else
					cout<<'B';
			}
		}
		cout<<endl;
    }
    return 0;
}
