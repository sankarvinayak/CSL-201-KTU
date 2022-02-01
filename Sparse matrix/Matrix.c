#include <stdio.h>
int main()
{
    int i,j,row,col,k,ar[20][3],t,n;
    printf("Number of rows of matrix:");
    scanf("%d",&row);
     printf("Number of columns of matrix:");
    scanf("%d",&col);
     printf("Number of non zero elements of matrix:");
    scanf("%d",&n);
    if(n>row*col){
        printf("Number of elements cant be more than rows*cols\n");
    }
    else{
    for(i=0;i<n;i++){
        printf("Insert Element %d \n",i+1);
        printf("Row of element:");
        scanf("%d",&ar[i][0]);
        printf("Column of element:");
        scanf("%d",&ar[i][1]);
        printf("Value of element:");
        scanf("%d",&ar[i][2]);
    }
    printf("The given sparse mathrix is\n");
    printf("Row\t:");
    for(i=0;i<n;i++)
    printf("%d ",ar[i][0]);
    printf("\nColumn\t:");
    for(i=0;i<n;i++)
    printf("%d ",ar[i][1]);
    printf("\nValue\t:");
    for(i=0;i<n;i++)
    printf("%d ",ar[i][2]);
        printf("\nThe given mathrix is\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            t=0;
            for(k=0;k<n;k++){
                if(ar[k][0]==i&&ar[k][1]==j)
                {
                    printf("%d ",ar[k][2]);
                    t=1;
                }
            }
            if(t==0){
                printf("%d ",0);
            }
        }
        printf("\n");
    }
    }
    return 0;
}
