#include <stdio.h>
int size;
int hashTable(int key){
 int i ;
 i = key%size ;
 return i;
}
int linearProbing(int key,int j){
 int i ;
 i = (key+j)%size ;
 return i ;
}
int quadraticProbing(int key, int j){
 int i ;
 i = (key+(j*j))%size ;
 return i ;
}
void main()
{
    int key,a[20],hash[20],i,n,s,op,j,k ;
    printf ("\nEnter the table size ");
    scanf ("%d",&size);
    printf ("Enter the number of Employees having number: ");
    scanf ("%d",&n);
    for (i=0;i<size;i++)
        hash[i]=-1 ;
    printf ("\nEnter employees' numbers:\n");
    for (i=0;i<n;i++){
        printf("number of employee %d:",i+1);
        scanf("%d",&a[i]);
    }
    do
    {
        printf("\n\n1.Linear Probing\n2.Quadratic Probing \n3.Exit \nEnter your option: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                for (i=0;i<size;i++)
                    hash[i]=-1 ;
                for(k=0;k<n;k++)
                {
                    key=a[k] ;
                    i = hashTable(key);
                    j=1;
                    while (hash[i]!=-1)
                    {
                        i = linearProbing(key,j);
                        j++;
                    }
                    hash[i]=key ;
                }
                printf("\nThe Employee numbers are: ");
                for (i=0;i<size;i++)
                {
                    if (hash[i]!=-1){
                        printf("\n  Employee %d: %d",i+1,hash[i]);
                    }else{
                        printf("\n  Employee %d: nil",i+1);
                    }
                }
                break ;
            case 2:
                for (i=0;i<size;i++)
                    hash[i]=-1 ;
                for(k=0;k<n;k++){
                    j=1;
                    key=a[k] ;
                    i = hashTable(key);
                    while (hash[i]!=-1){
                        i = quadraticProbing(key,j);
                        j++ ;
                    }
                    hash[i]=key ;
                }
                printf("\nThe Employee numbers are: ");
                for (i=0;i<size;i++){
                    if (hash[i]!=-1){
                        printf("\n  Employee %d: %d",i+1,hash[i]);
                    }else{
                        printf("\n  Employee %d: nil",i+1);
                    }   
                }
            break ;
        }
    } while(op!=3);
}