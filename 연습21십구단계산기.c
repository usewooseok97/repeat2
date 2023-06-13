#include<stdio.h>

int main(void){

    int  y, z, sum=0 ;
    char o ;
    while(1){
    printf("십구단 숫자를 입력해주세요");
    scanf("%d",&z);
    for(y=1; y<=19; y++)
    {
     printf("%d *%d 의 값은 %d 입니다\n", z,y,z * y);
    }
    y=0;
    getchar();
    printf("프로그램을 종료하시겠습니까?(y/n)");
    scanf("%c", &o);
    if ( o == 'n' || o =='N')
    {
      continue;
    }
    else if( o == 'y' || o == 'Y')
      {
        break;
    }
    else{
      printf("잘못입력되었습니다.\n");
    }
    }
    return 0;
}