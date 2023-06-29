#include<stdio.h>
#include<string.h>

int main()
{   
    int n, x;
    char a[100];
    char b[100];

    scanf("%s", &a);
    n = strlen(a);
    for(int i=0; i<n; i++)
    {
        b[n-i-1] = a[i];
    }
    for(int i=0; i<n; i++)
    {if(b[i] == a[i])
    { x = 1; }
    else{ x = 0;}}
    printf("%d", x);
}