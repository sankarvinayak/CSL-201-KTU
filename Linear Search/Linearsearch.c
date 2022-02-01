# include <stdio.h> 
int main()
{
    int ar[20],i,n,s;
    printf("How many numbers you wish to enter :");
    scanf("%d",&n);
    printf("Enter the numbers\n");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("Enter the number to search :");
    scanf("%d",&s);
    for(i=0;i<n;i++){
        if(s==ar[i]){
            printf("Number found at position %d\n",i+1);
            return 0;
        }
    }
    printf("Number not Found\n");
    return 0;
}
