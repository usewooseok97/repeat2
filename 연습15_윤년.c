# include<stdio.h>

int main(void)
{
    int year = 2023;
    if ( ((year % 4 == 0) && (year % 100 !=0)) || (year % 400 ==0))
    // 만약 4로나누고나머지가 0이면서 100으로 나누고나머지가 0이 아니거나 400으로나누고 나머지가 0 이면 반환함
    {
        printf(" %d is 윤년! \n", year );
    }
    else
    {
        printf( " %d is not 윤년!!! \n", year );
    }
    return 0;
}