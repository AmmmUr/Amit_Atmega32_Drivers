/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 3-1
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int , int );
int main()
{
    int x,y;
    printf("Please enter the first number:");
    scanf("%d",&x);

    printf("Please enter the second number:");
    scanf("%d",&y);
    swap(x,y);
    return 0;
}
void swap(int x, int y){
   printf("\nBefore swapping\n X = %d  Y = %d",x,y);
   x=y+x;
   y=x-y;
   x=x-y;
   printf("\nAfter swapping\n X = %d  Y = %d",x,y);
}
