#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    int t;
    string s;
    scanf("%d",&t);
 
    while(t--)
    {
        cin >> s;
        vector<pair<int,char> > v(26,make_pair(0,'-'));
 
        for(int i=0; s[i]!='\0'; i++)
        {
            v[s[i]-'a'].first++;
            v[s[i]-'a'].second=s[i];
        }
 
        sort(v.begin(),v.end());
 
        char c[1000010];
        c[0]=v[25].second;
        v[25].first--;
 
        int i=0,flag=0;
 
        while(1)
        {
            sort(v.begin(),v.end());
 
            if(v[25].first==0) break;
 
            int k=25;
            while(c[i]==v[k].second) k--;
 
            if(v[k].first<=0)
            {
                flag=1;
                break;
            }
 
            i++;
            c[i]=v[k].second;
            v[k].first--;
        }
 
        if(flag==1)
        {
            cout << -1 << endl;
            continue;
        }
        c[i+1]='\0';
        cout << c << endl;
    }
    return 0;
}
