#include <stdio.h>
int main() {
    int n, m, i, j, w[50], p[50], x[50] = {0};
    float ratio[50], profit = 0;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the objects' weights: ");
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the objects' profits: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        ratio[i] = (float)p[i] / w[i];
    }
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    // Sort items by profit/weight ratio (descending)
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(ratio[i] < ratio[j]) {
                float r = ratio[i]; ratio[i] = ratio[j]; ratio[j] = r;
                int t = w[i]; w[i] = w[j]; w[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
    int curW = 0;
    // Greedy selection (only full items)
    for(i = 0; i < n; i++) {
        if(curW + w[i] > m) break;
        x[i] = 1;
        curW += w[i];
        profit += p[i];
    }
    printf("Optimal solution for greedy method: %.1f\n", profit);
    printf("Solution vector for greedy method: ");
    for(i = 0; i < n; i++)
        printf("%d\t", x[i]);
    return 0;
}
