#include<stdio.h>
#include<limits.h>
# define number 5
int main(void)
{   
    int i, max, index, min;
    int array[number]; //배열 정의  array[number] 넘버는 사전에 정의해둠
    max = 0;           // max min에 0을넣는건 처음에 비교할때랑 출력할때 시작숫자가있어야해서 넣음
    index =0;
    for(i=0;i<number;i++)
    {
    scanf("%d",&array[i]); // array[i]는 i칸을 생성하고 그안에 값을 넣겠다
        if(max<array[i])
        {
            max = array[i];
            index = i;    // index에 i를넣는건 주소값(0,1,2,3,4)을 i가 갖고있어서이다
        }
    }
    printf(" 5개 배열중 가장큰값은 %d 이고, 위치는 %d번째입니다", max , index+1);
    min = INT_MAX ;
    for(i=0;i<number;i++)
    {
    scanf("%d",&array[i]);
        if(min>array[i])
        {
            min = array[i];
            index = i;
        }
    }
    printf(" 5개 배열중 가장작은값은 %d 이고, 위치는 %d번째입니다", min , index+1);
    
    return 0;
}
