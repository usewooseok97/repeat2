#include<stdio.h>

int main()
{
    int x;
    int y;
    int tp = 0;
    int xp = 0;

     scanf("%d %d", &x, &y);
     	while (x > 0) 
    {
 		int t = x % 10;
 		x = x / 10;//x�� x/10 ����
 		tp = tp * 10 + t;
 	}
     	while (y > 0) 
    {
 		int a = y % 10;
 		y = y / 10;//y�� y/10 ����
 		xp = xp * 10 + a;
 	}
    if(tp>xp)
    {printf("%d",tp);}
    else{ printf("%d",xp);}
    return 0;
}