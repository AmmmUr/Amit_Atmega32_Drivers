/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 2-1
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,result;
    char oper;

    printf("Please enter the first number:");
    scanf("%d",&num1);//

    printf("Please enter the operator ( + , - , * , / ) :");
    scanf("%s",&oper);

    printf("Please enter the second  number:");
    scanf("%d",&num2);

    if(oper=='+'){
        result=num1+num2;
            printf("The result = %d",result);
    }
        else if(oper=='-'){
        result=num1-num2;
            printf("The result = %d",result);
    }
            else if(oper=='*'){
        result=num1*num2;
            printf("The result = %d",result);
    }
            else if(oper=='/'){
       float result=(float)num1/num2;
            printf("The result = %f",result);
    }
    else{
            printf("You entered a wrong operator");
    }

    return 0;
}
