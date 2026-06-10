#include<stdio.h>
#define MAX 10
#define INF 999
int main()
{
    int cost[MAX][MAX], visited[MAX]={0};
    int n,i,j,edges=0,min,u,v,total=0,s;
    
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    printf("Enter cost matrix : \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    printf("Enter the source node: ");
    scanf("%d",&s);
    visited[s] = 1;   // start from source node
    while(edges < n-1)
    {
        min = INF;
        for(i=1;i<=n;i++)
        {
            if(visited[i])
            {
                for(j=1;j<=n;j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("Edge %d: %d -> %d  cost = %d\n", edges+1, u, v, min);
        visited[v] = 1;
        total += min;
        edges++;
    }
    printf("Minimum cost = %d\n", total);
    return 0;
}
