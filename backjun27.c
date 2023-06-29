#include<stdio.h>
#include<string.h>

int main()
{
    int n , m;
    char x[20];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %s", &m,x);
    for ( int j = 0; j < strlen(x); j++)
    {
        for(int b=0 ; b<m; b++)
            {
                printf("%c", x[j]);
            }
    }
    printf("\n");
    }
    return 0 ;
    }