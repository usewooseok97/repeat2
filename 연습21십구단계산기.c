#include<stdio.h>

int main(void){

    int  y, z, sum=0 ;
    char o ;
    while(1){
    printf("�ʱ��� ���ڸ� �Է����ּ���");
    scanf("%d",&z);
    for(y=1; y<=19; y++)
    {
     printf("%d *%d �� ���� %d �Դϴ�\n", z,y,z * y);
    }
    y=0;
    getchar();
    printf("���α׷��� �����Ͻðڽ��ϱ�?(y/n)");
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
      printf("�߸��ԷµǾ����ϴ�.\n");
    }
    }
    return 0;
}