#include<stdio.h>
#define n 20                            // n���� �ٲٸ� ���̾�ũ�� ���� ����

int main(void)
{
    int i,j,k;
    for (i=0 ;i<n; i++)                 // for�� 10�� �ݺ�
    {
        for(j=n-i-1; j>0; j--){
            printf("  ");               // ������ �����پ��
        }
                for(j=0; j<i; j++){
                printf(" ��");           // ���� �߽ɺ��� ���ʹ������� �þ �������� j=0; j<i; j++
                }
                    for(j=0; j<i-1; j++){
                    printf(" ��");       // ���� �߽ɺ��� �����ʹ������� �þ
                    }
    printf("\n");
    }
    for (i=1 ;i<n; i++)                  // ó�� �� ���� ���ַ��� i=1 ������
    {
        for(j=n-i; j<n; j++){            // ������ ���� �þ j=n-i; j<n; j++
            printf("  ");
        }
                for(j=n-i-1; j>0; j--){  // ���� �߽ɹ������� �پ��
                printf(" ��");
                }
                    for(j=n-i-2; j>0; j--){     //���� �߽ɹ������� �پ��
                    printf(" ��");
                    }
    printf("\n");
    }
    return 0;
}