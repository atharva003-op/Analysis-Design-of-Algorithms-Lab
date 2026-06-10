#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int partition(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++)
        if(a[j]<p) swap(&a[++i],&a[j]);
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quickSort(int a[],int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,h);
    }
}
int main(){
    int n;
    printf("Enter n (>5000): ");
    scanf("%d",&n);
    if(n<=5000) return printf("Enter >5000\n"),0;
    int *a=malloc(n*sizeof(int));
    if(!a) return printf("Memory error\n"),0;
    srand(time(0));
    for(int i=0;i<n;i++) a[i]=rand()%100000;
    clock_t s=clock();
    quickSort(a,0,n-1);
    clock_t e=clock();
    printf("Time: %f sec\n",(double)(e-s)/CLOCKS_PER_SEC);
    free(a);
}
