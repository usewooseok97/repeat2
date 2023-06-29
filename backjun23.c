#include<stdio.h>

int main()
{   int i ;
    int n = 0;
    char alp[100] = {0};
    scanf("%s", &alp[n]);
    for(i=0;i<100;i++)
    {
        if(alp[i] != 0 ) {n++;}
    }
    printf("%d", n);
    return 0;
}