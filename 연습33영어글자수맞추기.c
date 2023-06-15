#include<stdio.h>

int main(void)  
{
    char input[500]  ; //char 문자열 변수를 선언 499알파벳쓰기가능
    gets(input);
    /* gets는 엔터를 치면 입력받은걸실행하겠다는 의미
    여기서는 ()안에 input안의 값을 엔터치면실null행하겠다는의미로볼수있다*/
    int count=0 ;
    while (input[count] != '\0') // \0 은 널(null)을 의미 널이 나올때까지 실행하겠다는의미이다
    {
       count ++ ;
    }
    printf("문자열의 길이는 %d 입니다", count);
    printf("입력하신 문자열은 %s 입니다", input);

    
    return 0;
}
