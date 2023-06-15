#include<stdio.h>

int main()               // 구구단 프로그램
{
    int i ,j ;
    int gugudan[10][10]; // 배열 여러줄 만드는형식 int 배열이름 [][]
    for(i=1;i<=9;i++)
    {
        printf("\n[%d 단] \n", i);  // 1~9 단을 의미함
        for(j=1;j<=9;j++)
        {
            gugudan[i][j]= i*j ;    // i가 1단이면 1 * j(123456789) 표시
            printf("%d * %d = %d \n", i , j ,gugudan[i][j]); // 배열 출력시 숫자값을 나타낼때도 %d 표시
        }
    }
    return 0;
}