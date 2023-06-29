#include<stdio.h>

int main()
{
    int a[7]={1,1,2,2,2,8};
    int b[7];
    int p[7];

    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i<6; i++)
    {
        p[i]= a[i] - b[i];
        printf("%d ", p[i]);
    }
    return 0;
}