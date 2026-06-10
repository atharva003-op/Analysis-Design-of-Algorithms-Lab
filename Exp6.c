#include<stdio.h>
int n, w[10], p[10];
int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}
int knap(int i, int m)
{
    if(i > n) return 0;
    if(w[i] > m)
        return knap(i+1, m);
    return max(knap(i+1, m), p[i] + knap(i+1, m - w[i]));
}
int main()
{
    int m, i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity: ");
    scanf("%d", &m);
    printf("Enter profit and weight:\n");
    for(i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &w[i]);
    printf("Maximum profit = %d", knap(1, m));
    return 0;
}
