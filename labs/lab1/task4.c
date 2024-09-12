#include <stdio.h>

int main()
{
    float a,b,c,x;
    
    scanf("%f%f%f", &a, &b, &c);
    x = (c-b)/a;
    printf("x=%.1lf", x);

    return 0;
}
