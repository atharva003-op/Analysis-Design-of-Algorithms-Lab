#include <stdio.h>
int main()
{
    int a[10][10], indeg[10] = {0}, topo[10];
    int n, i, j, k = 0, count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1)
                indeg[j]++;
        }
    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            if(indeg[i] == 0)
            {
                topo[k++] = i + 1;
                indeg[i] = -1;
                for(j = 0; j < n; j++)
                    if(a[i][j] == 1)
                        indeg[j]--;
                count++;
                break;
            }
        }
        if(i == n) break; // cycle case
    }
    if(count != n)
        printf("Topological ordering not possible");
    else
    {
        printf("Topological order: ");
        for(i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }
    return 0;
}
