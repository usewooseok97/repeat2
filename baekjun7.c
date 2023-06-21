#include<stdio.h>

    int num1, num2, num3 ;
    int gold = 0 ;

int samenum(){
    if(num1 == num2){return num1;}
    if(num1 == num3){return num1;}
    if(num3 == num2){return num3;}
};

int bignum(){
    if(num1 > num2 && num1 > num3) {return num1 ;}
    if(num2 > num1 && num2 > num3) {return num2 ;}
    if(num3 > num1 && num3 > num2) {return num3 ;}

};
int main()
{
    scanf("%d %d %d",&num1, &num2, &num3);
    if(num1 == num2 && num1 == num3 && num2 == num3){
        gold = 10000 + num1 * 1000;
        printf("%d", gold);
    }
    else if(num1 == num2 || num1 == num3 || num2 == num3){
        gold = 1000 + samenum()* 100 ;
        printf("%d", gold);
    }
    if(num1 != num2 && num1 != num3 && num2 != num3){
        gold = bignum()  * 100 ;
        printf("%d", gold);
    }
}