#include<stdio.h>

int main()
{
    int a, sum = 0;
    int b[100];

    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%1d",&b[i]); // 정수 1자리씩 입력받아야할떄 %(원하는정수 자리수)d
    }
    for(int i = 0; i < a; i++)
    {
        sum = sum+b[i];
    }
    printf("%d", sum);
    return 0;
}