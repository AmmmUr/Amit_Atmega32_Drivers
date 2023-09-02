/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 3-2 iterative method
 */
#include <stdio.h>
#include <stdlib.h>
void Fibonacci(int);
int main()
{
    int num;
    printf("Please enter the number of terms:");
    scanf("%d",&num);
    printf("\nFibonacci Series: ");
    Fibonacci(num);
    return 0;
}
void Fibonacci(int num){
static int sum1=0,sum2=1,result=0,i;
    for (i=0;i<num;i++){
        printf("%d ",result);
           result=sum1+sum2;
           sum2=sum1;
           sum1=result;
    }
}
