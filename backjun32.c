#include<stdio.h>

int main()
{
    int s,n;
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {for(s=1; n-i-s>0; s++)
    {
        printf(" ");
    }
    for(int j=0; j<=i; j++)
        {
            printf("*");
        }
    for (int j = 0; j<i; j++)
        {
            printf("*");
        }
        printf("\n");}
for(i=1; i<n; i++)
    {for(s=0; s<i; s++)
    {
        printf(" ");
    }
    for(int j=0; n-j-i>0; j++)
        {
            printf("*");
        }
    for (int j = 0; n-j-i-1>0; j++)
        {
            printf("*");
        }
        printf("\n");}
return 0;
    }
