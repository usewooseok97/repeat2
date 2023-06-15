#include<stdio.h>

void point( int*x , int*y) //함수인건 알고있지
{
    int temp; // temp라는 변수로 만들어야 옮길수있음 물 옮길때 쓰는 물그릇이라생각하면됨
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int x =1;
    int y =2;
    point(&x,   &y); // 함수가 실행될거고 그럼 x랑 y 가 바뀜
    // 위 함수에서 * 요거 안하면 값이 x y에 저장이안되기때문에 *해줘야 x,y가바뀌어짐
    printf("x와 y값은 %d %d 입니다", x ,y);
    return 0;
}