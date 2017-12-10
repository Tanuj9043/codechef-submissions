#include <iostream>
#include <stdio.h>
using namespace std;
 
bool all_same(int a[], int b[])
{
    for(int i=0; i<27; i++)
    {
        if((a[i]!=0 && b[i]!=0)||(a[i]==0 && b[i]==0)) continue;
        else return false;
    }
    return true;
}
 
bool unique_count(int a[], int b[])
{
    for(int i=0; i<27; i++)
    {
        if(a[i]!=0 && b[i]==0 && a[i]>1) return true;
    }
    return false;
}
 
bool B_unique_count(int a[], int b[])
{
    int ans=0;
    for(int i=0; i<27; i++)
    {
        if(a[i]==0 && b[i]!=0) ans++;
    }
    return ans;
}
 
int main()
{
    int T;
    char s[505],t[505];
    scanf("%d",&T);
    while(T--)
    {
        int a[27]={0},b[27]={0};
        scanf("%s %s",&s,&t);
        for(int i=0; s[i]!='\0'; i++) a[s[i]-'a']++;
        for(int i=0; t[i]!='\0'; i++) b[t[i]-'a']++;
 
        if(all_same(a,b))
        {
            printf("B\n");
            continue;
        }
 
        if(unique_count(a,b)) printf("A\n");
        else
        {
            if(B_unique_count(a,b)==0) printf("A\n");
            else printf("B\n");
        }
    }
}

