#include<stdio.h>
#define n 10

int main(void)
{
    int i,j;
    for (i=0 ;i<n; i++)
    {
        for(j=n-i-1; j>0; j--){
            printf("  ");
        }
                for(j=0; j<i; j++){
                printf(" ¡Ú");
                }
                    for(j=0; j<i-1; j++){
                    printf(" ¡Ú");
                    }

    printf("\n");
    }
    return 0;
}