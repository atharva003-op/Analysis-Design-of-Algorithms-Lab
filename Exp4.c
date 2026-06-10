#include<stdio.h>
#define INF 999
int main()
{
    int c[10][10], d[10], v[10]={0};
    int i,j,n,s,u,min;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    printf("Enter source vertex: ");
    scanf("%d",&s);
    for(i=1;i<=n;i++)
        d[i]=c[s][i];
    v[s]=1;
    for(i=1;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
            if(!v[j] && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        v[u]=1;
        for(j=1;j<=n;j++)
            if(!v[j] && d[u]+c[u][j] < d[j])
                d[j]=d[u]+c[u][j];
    }
    for(i=1;i<=n;i++)
        printf("Shortest distance from %d to %d = %d\n",s,i,d[i]);
    return 0;
}
