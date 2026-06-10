#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0,*t=malloc((r-l+1)*sizeof(int));
    while(i<=m && j<=r) t[k++]=a[i]<=a[j]?a[i++]:a[j++];
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++) a[i]=t[k++];
    free(t);
}
void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n;
    printf("Enter n (>5000): "); scanf("%d",&n);
    if(n<=5000) return printf("Enter >5000\n"),0;
    int *a=malloc(n*sizeof(int));
    if(!a) return printf("Memory error\n"),0;
    srand(time(0));
    for(int i=0;i<n;i++) a[i]=rand()%100000;
    clock_t s=clock();
    for(int i=0;i<1000;i++) mergeSort(a,0,n-1);
    clock_t e=clock();
    printf("Time: %f sec\n",(double)(e-s)/CLOCKS_PER_SEC/1000);
    free(a);
}
