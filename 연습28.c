#include<stdio.h>
#include<limits.h>
# define number 5
int main(void)
{   
    int i, max, index, min;
    int array[number]; //�迭 ����  array[number] �ѹ��� ������ �����ص�
    max = 0;           // max min�� 0���ִ°� ó���� ���Ҷ��� ����Ҷ� ���ۼ��ڰ��־���ؼ� ����
    index =0;
    for(i=0;i<number;i++)
    {
    scanf("%d",&array[i]); // array[i]�� iĭ�� �����ϰ� �׾ȿ� ���� �ְڴ�
        if(max<array[i])
        {
            max = array[i];
            index = i;    // index�� i���ִ°� �ּҰ�(0,1,2,3,4)�� i�� �����־�̴�
        }
    }
    printf(" 5�� �迭�� ����ū���� %d �̰�, ��ġ�� %d��°�Դϴ�", max , index+1);
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
    printf(" 5�� �迭�� ������������ %d �̰�, ��ġ�� %d��°�Դϴ�", min , index+1);
    
    return 0;
}
