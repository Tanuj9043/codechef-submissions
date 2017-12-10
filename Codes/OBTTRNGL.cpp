#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,k,A,B,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&k,&A,&B);
        if(A>B) swap(A,B);
        B=B-A+1;
        A=1;
        B=min(B,2+k-B);
        if(k&1) printf("%d\n",B-A-1);
        else
        {
            if(B==((k>>1)+1)) printf("0\n");
            else printf("%d\n",B-A-1);
        }
    }
    return 0;
}
