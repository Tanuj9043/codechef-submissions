#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,l;
    char s[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        l=strlen(s);
        int arr[10]={0};
        for(int i=0; i<l; i++) arr[s[i]-'0']++;
        for(int i=65; i<=90; i++)
        {
            if(i/10==i%10)
            {
                if(arr[i/10]>1) printf("%c",(char)(i));
            }
            else
            {
                if(arr[i/10]>0 && arr[i%10]>0) printf("%c",(char)(i));
            }
        }
        printf("\n");
    }
    return 0;
}
