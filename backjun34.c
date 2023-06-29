#include <stdio.h>
#include<string.h>

int main(void)
{
    char str[10000];
    int al[26];
 
    scanf("%s",&str);
    int size = strlen(str);

    for(int i=0; i<size; i++){
        if(str[i]<96){          //대문자
            al[str[i]-65]++;
        }else if(str[i]>96){    //소문자
            al[str[i]-97]++;
        }
    }
     int max=0;    //알파벳 개수의 최대값 구하기
    char c;       //가장 많은 알파벳 저장하기위한 변수
    //가장 많이 사용된 알파벳 찾기위한 반복문
    for(int i=0; i<26; i++){
        if(al[i]!=0 && max<al[i]){
            max=al[i];
            c = i+65;
        }
    }
    //max와 같은 개수로 사용된 알파벳이 있다면 c에 ? 저장
    for(int i=0; i<26; i++){
        if(al[i]!=0 && max==al[i] && i!=c-65){
            c = '?';
            break;
        }
    }
    //결과 출력
    printf("%c",c);
    return 0;
}