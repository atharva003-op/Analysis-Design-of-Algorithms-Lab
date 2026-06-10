#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
            if(a[j] < a[min]) min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}
int main()
{
    int n;
    printf("Enter number (>5000): ");
    scanf("%d", &n);
    if(n <= 5000) return printf("Enter value > 5000\n"), 0;
    int *a = malloc(n * sizeof(int));
    if(!a) return printf("Memory error\n"), 0;
    for(int i = 0; i < n; i++) a[i] = rand() % 10000;
    clock_t s = clock();
    selectionSort(a, n);
    clock_t e = clock();
    printf("Time: %f seconds\n", (double)(e - s)/CLOCKS_PER_SEC);
    free(a);
}
