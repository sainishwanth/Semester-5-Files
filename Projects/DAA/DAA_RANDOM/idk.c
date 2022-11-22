#include <stdio.h>

int main() 
{
    double num1,num2,num3;
    printf("enter first number:");
    scanf("%lf",&num1);
    printf("enter second number:");
    scanf("%lf",&num2);
    printf("enter third number:");
    scanf("%lf",&num3);
    if(num1>=num2&&num1>=num3)printf("%lf is the larget number",num1);
    if(num2>=num1&&num2>=num3)printf("%lf is the larget number",num2);
    if(num3>=num1&&num3>=num2)printf("%lf is the larget number",num3);
    return 0;
}