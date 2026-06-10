#include<stdio.h>
#define MAX 20
#define INF 999
int parent[MAX];
int find(int x)
{
    while(parent[x])
        x = parent[x];
    return x;
}
int main()
{
    int n,cost[MAX][MAX],i,j,a,b,u,v,min,edges=0,total=0;
    printf("Enter vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    while(edges < n-1)
    {
        min = INF;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a=i; b=j;
                }
        u = find(a);
        v = find(b);
        if(u != v)
        {
            parent[v] = u;
            printf("Edge %d: %d -> %d\n", ++edges, a, b);
            total += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    printf("Minimum cost = %d", total);
}
