#include<stdio.h>
#define n 20                            // n값만 바꾸면 다이아크기 변동 가능

int main(void)
{
    int i,j,k;
    for (i=0 ;i<n; i++)                 // for문 10번 반복
    {
        for(j=n-i-1; j>0; j--){
            printf("  ");               // 공백이 점점줄어듬
        }
                for(j=0; j<i; j++){
                printf(" ★");           // 별이 중심부터 왼쪽방향으로 늘어남 오름차순 j=0; j<i; j++
                }
                    for(j=0; j<i-1; j++){
                    printf(" ★");       // 별이 중심부터 오른쪽방향으로 늘어남
                    }
    printf("\n");
    }
    for (i=1 ;i<n; i++)                  // 처음 빈 공간 없애려고 i=1 로지정
    {
        for(j=n-i; j<n; j++){            // 공백이 점점 늘어남 j=n-i; j<n; j++
            printf("  ");
        }
                for(j=n-i-1; j>0; j--){  // 별이 중심방향으로 줄어듦
                printf(" ★");
                }
                    for(j=n-i-2; j>0; j--){     //별이 중심방향으로 줄어듦
                    printf(" ★");
                    }
    printf("\n");
    }
    return 0;
}