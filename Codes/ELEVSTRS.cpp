#include <bits/stdc++.h>
using namespace std;
 
#define sqrt 1.41421
 
int main()
{
    int t;
    float n,v1,v2,t1,t2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%f %f %f",&n,&v1,&v2);
        t1 = (sqrt*n)/v1;
        t2 = (2*n)/v2;
        if(t1>t2) printf("Elevator\n");
        else printf("Stairs\n");
    }
    return 0;
}
