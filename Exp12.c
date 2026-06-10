#include <stdio.h>
#include <stdlib.h>
int isSafe(int **b,int n,int r,int c){
    for(int i=0;i<c;i++) if(b[r][i]) return 0;
    for(int i=r,j=c;i>=0&&j>=0;i--,j--) if(b[i][j]) return 0;
    for(int i=r,j=c;i<n&&j>=0;i++,j--) if(b[i][j]) return 0;
    return 1;
}
int solve(int **b,int n,int c){
    if(c==n) return 1;
    for(int r=0;r<n;r++){
        if(isSafe(b,n,r,c)){
            b[r][c]=1;
            if(solve(b,n,c+1)) return 1;
            b[r][c]=0; // backtrack
        }
    }
    return 0;
}
int main(){
    int n;
    printf("Enter number of queens: ");
    scanf("%d",&n);
    int **b=malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) b[i]=calloc(n,sizeof(int));
    if(!solve(b,n,0)) printf("No solution\n");
    else
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%s ",b[i][j]?"Q":"#");
            printf("\n");
        }
    for(int i=0;i<n;i++) free(b[i]);
    free(b);
}
