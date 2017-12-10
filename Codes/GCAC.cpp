#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
    int t;
    int n,m,jobs_recieved,no_job_companies,index,ms;
    long long total_salaries;
    int minSalary[1005], offeredSalary[1005], maxJobOffers[1005], n_j_c[1005];
    char qual[1005][1005];
 
    scanf("%d",&t);
    while(t--)
    {
        jobs_recieved=0,no_job_companies=0,total_salaries=0;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%d",&minSalary[i]);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&offeredSalary[i],&maxJobOffers[i]);
            n_j_c[i]=0;
        }
 
        for(int i=0; i<n; i++)
        {
            scanf("%s",&qual[i]);
        }
 
        for(int i=0; i<n; i++)
        {
            index=-1;
            ms=minSalary[i];
            for(int j=0; j<m; j++)
            {
                if(maxJobOffers[j]>0 && offeredSalary[j]>=ms && qual[i][j]=='1')
                {
                    ms=offeredSalary[j];
                    index=j;
                }
            }
            if(index!=-1)
            {
                jobs_recieved++;
                n_j_c[index]=1;
                maxJobOffers[index]--;
                total_salaries+=ms;
            }
        }
 
        for(int i=0; i<m; i++)
        {
            if(n_j_c[i]==0) no_job_companies++;
        }
 
        printf("%d %lld %d\n",jobs_recieved,total_salaries,no_job_companies);
    }
}
