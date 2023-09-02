/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 3-2 recursive method
 */
#include <stdio.h>
#include <stdlib.h>
int Fibonacci(int);
int main()
{
    int num,i;
    printf("Please enter the number of terms:");
    scanf("%d",&num);
    printf("\nFibonacci Series: ");
for (i=0;i<num;i++){
    printf("%d ",Fibonacci(i));
    }
    return 0;
}
int Fibonacci(int num){
    if(num==0){ return 0;}
       else if (num==1){ return 1;}
           else {
            return Fibonacci(num-1)+Fibonacci(num-2);
           }
}
