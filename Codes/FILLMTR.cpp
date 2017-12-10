#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,n,q,x,y,val;
    bool f=0;
    pair<pair<int,int>,int> z;
    scanf("%d",&t);
    while(t--)
    {
        vector<pair<pair<int,int>,int> > B;
        int arr[100005];
        bool vis[100005];
        f=0;
        scanf("%d %d",&n,&q);
        for(int i=0; i<=n; i++)
        {
            arr[i]=0;
            vis[i]=false;
        }
        for(int i=0; i<q; i++)
        {
            scanf("%d %d %d",&z.first.first,&z.first.second,&z.second);
            z.first.first--;z.first.second--;
            if(z.first.second<z.first.first) swap(z.first.second,z.first.first);
            B.push_back(z);
        }
        sort(B.begin(),B.end());
        for(int i=0; i<q; i++)
        {
            x=B[i].first.first;
            y=B[i].first.second;
            val=B[i].second;
            if(vis[x]==0 && vis[y]==0)
            {
                vis[x]=1;vis[y]=1;
                if(val==1)
                {
                    if(x==y)
                    {
                        f=1;
                        break;
                    }
                    arr[y]=1;
                }
            }
            else if(vis[x]==0 && vis[y]!=0)
            {
                vis[x]=1;
                if(val==0) arr[x]=arr[y];
                else arr[x]=(arr[y]+1)%2;
            }
            else if(vis[x]!=0 && vis[y]==0)
            {
                vis[y]=1;
                if(val==0) arr[y]=arr[x];
                else arr[y]=(arr[x]+1)%2;
            }
            else
            {
                if((val==0 && arr[x]!=arr[y])||(val==1 && arr[x]==arr[y]))
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==1)
        {
            printf("no\n");
        }
        else printf("yes\n");
    }
    return 0;
}
