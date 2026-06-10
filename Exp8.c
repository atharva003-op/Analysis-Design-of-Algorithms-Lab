#include <stdio.h>
int s[10], x[10], n, d;
void subset(int k, int sum) {
    if(sum == d) {
        for(int i = 0; i < k; i++)
            if(x[i]) printf("%d ", s[i]);
        printf("\n");
        return;
    }
    if(k == n || sum > d) return;
    x[k] = 1;
    subset(k + 1, sum + s[k]);
    x[k] = 0;
    subset(k + 1, sum);
}
int main() {
    int i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements (in increasing order): ");
    for(i = 0; i < n; i++)
        scanf("%d", &s[i]);
    printf("Enter target sum: ");
    scanf("%d", &d);
    subset(0, 0);
    getchar();   
    getchar();   
    return 0;
}
