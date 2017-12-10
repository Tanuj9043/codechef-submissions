#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
long long st_fcall[400020],st_arr[400020];
 
void build_arr(int l, int r, int index)
{
    if(l==r)
    {
        st_arr[index]=0;
        return;
    }
 
    int mid=(l+r)>>1;
    build_arr(l,mid,2*index+1);
    build_arr(mid+1,r,2*index+2);
    st_arr[index]=0;
}
 
void build_fcall(int l, int r, int index)
{
    if(l==r)
    {
        st_fcall[index]=1;
        return;
    }
 
    int mid=(l+r)>>1;
    build_fcall(l,mid,2*index+1);
    build_fcall(mid+1,r,2*index+2);
    st_fcall[index]=0;
}
 
void inc_arr(int l, int r, int index, int i, int j, long long m)
{
    if(l>j || r<i) return;
    if(l>=i && r<=j)
    {
        st_arr[index]=(st_arr[index]+m)%MOD;
        return;
    }
    if(st_arr[index]!=0)
    {
        st_arr[2*index+1]=(st_arr[2*index+1]+st_arr[index])%MOD;
        st_arr[2*index+2]=(st_arr[2*index+2]+st_arr[index])%MOD;
        st_arr[index]=0;
    }
    int mid=(l+r)>>1;
    if(i>mid) inc_arr(mid+1, r, 2*index+2, i, j, m);
    else if(j<=mid) inc_arr(l, mid, 2*index+1, i, j, m);
    else
    {
        inc_arr(l, mid, 2*index+1, i, mid, m);
        inc_arr(mid+1, r, 2*index+2, mid+1, j, m);
    }
}
 
void inc_fcall(int l, int r, int index, int i, int j, long long m)
{
    if(l>j || r<i) return;
    if(l>=i && r<=j)
    {
        st_fcall[index]=(st_fcall[index]+m)%MOD;
        return;
    }
    if(st_fcall[index]!=0)
    {
        st_fcall[2*index+1]=(st_fcall[2*index+1]+st_fcall[index])%MOD;
        st_fcall[2*index+2]=(st_fcall[2*index+2]+st_fcall[index])%MOD;
        st_fcall[index]=0;
    }
    int mid=(l+r)>>1;
    if(i>mid) inc_fcall(mid+1, r, 2*index+2, i, j, m);
    else if(j<=mid) inc_fcall(l, mid, 2*index+1, i, j, m);
    else
    {
        inc_fcall(l, mid, 2*index+1, i, mid, m);
        inc_fcall(mid+1, r, 2*index+2, mid+1, j, m);
    }
}
 
long long query_arr(int l, int r, int index, int i)
{
    if(l==r) return st_arr[index];
    if(st_arr[index]!=0)
    {
        st_arr[2*index+1]=(st_arr[2*index+1]+st_arr[index])%MOD;
        st_arr[2*index+2]=(st_arr[2*index+2]+st_arr[index])%MOD;
        st_arr[index]=0;
    }
    int mid=(l+r)>>1;
    if(i>mid) return query_arr(mid+1, r, 2*index+2, i);
    return query_arr(l, mid, 2*index+1, i);
}
 
long long query_fcall(int l, int r, int index, int i)
{
    if(l==r) return st_fcall[index];
    if(st_fcall[index]!=0)
    {
        st_fcall[2*index+1]=(st_fcall[2*index+1]+st_fcall[index])%MOD;
        st_fcall[2*index+2]=(st_fcall[2*index+2]+st_fcall[index])%MOD;
        st_fcall[index]=0;
    }
    int mid=(l+r)>>1;
    if(i>mid) return query_fcall(mid+1, r, 2*index+2, i);
    return query_fcall(l, mid, 2*index+1, i);
}
 
int main()
{
    int t,n,q,x,l,r;
    long long m;
    scanf("%d",&t);
    while(t--)
    {
        pair<int,pair<int,int> > v[100005];
        scanf("%d %d",&n,&q);
        build_arr(0,n-1,0);
        build_fcall(0,q-1,0);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d %d",&x,&l,&r);
            v[i] = make_pair(x,make_pair(l-1,r-1));
        }
        for(int i=q-1; i>=0; i--)
        {
            if(v[i].first==1)
            {
                m = query_fcall(0,q-1,0,i);
                inc_arr(0,n-1,0,v[i].second.first,v[i].second.second,m);
            }
            else
            {
                m = query_fcall(0,q-1,0,i);
                inc_fcall(0,q-1,0,v[i].second.first,v[i].second.second,m);
            }
        }
        for(int i=0; i<n; i++) printf("%lld ",query_arr(0,n-1,0,i));
        printf("\n");
    }
    return 0;
}
