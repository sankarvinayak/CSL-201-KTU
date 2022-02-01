# include <stdio.h>
int main()
{
    int ar[20],i,first,last,middle,n,s;
    printf("How many numbers you wish to enter ");
    scanf("%d",&n);
    printf("Enter the numbers in sorted order\n");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("Enter the number to search");
    scanf("%d",&s);
    first=0;
    last=n-1;
     while (first <= last) {
      if (ar[middle] < s)
         first = middle + 1;    
      else if (ar[middle] == s) {
         printf("%d is present at index %d.\n", s, middle+1);
         return 0;
      }
      else
         last = middle - 1;
      middle = (first + last)/2;
   }
    printf("Number not found \n");
    return 0;
}
