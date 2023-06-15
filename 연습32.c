#include<stdio.h>
int main()
{
    int i = 10; 
    int *p; // p 의 주소를 선언함
    p=&i;   // i의 주소를 p 에게 넘김 p는 i의 주소를알고있음 
    printf("i 의 값은 %d 이다", i);
    *p = 20;
    // p의 주소에 20을 넘김 즉 i의 주소가 담겨있는 p에게 주엇으므로 p는 i 에게 20을 넘겨줌
    printf(" i 의 값은 %d 이다", i);
    return 0 ;
}