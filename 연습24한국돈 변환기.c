#include <stdio.h>

int main()
{
   int input,a,b,c,d,e,f,g,h;
   printf("얼마를 입력할까요 ? ");
   scanf("%d",&input);
   a = input/50000; //50000으로 입력받은 금액을 나눈 몫 오만원개수
   b = input%50000/10000;//50000원짜리갯수를 제외하고 만원짜리갯수
   c = input%10000/5000;//만원 짜리 갯수를 제외하고 오천원짜리 갯수
   d = input%5000/1000;//오천원 짜리 갯수를 제외하고 천원짜리 갯수
   e = input%1000/500;//천원 짜리 갯수를 제외하고 오백원짜리 갯수
   f = input%500/100;//오백원짜리 갯수를 제외하고 백원짜리 갯수
   g = input%100/50;//백원짜리 갯수를 제외하고 오십원짜리 갯수
   h = input%50/10;//오십원짜리 갯수를 제외하고 십원짜리 갯수
   printf("오만원권 = %d\n",a);
   printf("만원권 = %d\n",b);
   printf("오천원권 = %d\n",c);
   printf("천원권 = %d\n",d);
   printf("오백원권 = %d\n",e);
   printf("백원권 = %d\n",f);
   printf("오십원 = %d\n",g);
   printf("십원 = %d\n",h);
}