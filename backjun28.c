#include<stdio.h>
#include<string.h>
int main()
{
    int k =1;
    char aa[10000];

scanf("%[^\n]s", aa);                   // 엔터 치기 전까지 문자 받겠다

    for (int i = 0; i < sizeof(aa); i++)
    {
        if(aa[i] == ' ')                 // 공백일때 문자 숫자 늘리고 공백에 1을 넣어 같은곳세는거 방지
        {   k++;
            aa[i] = 1;
        }
        
        if(aa[i+1] == 0)                    // 필요수 이상 세면 정지
        {
            break;
        }
    }
        printf("%d", k);
    return 0;

}