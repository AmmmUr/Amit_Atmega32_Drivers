/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 2-2
 */
// Note: the code with // i used for check
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NoD=0,num,test,rem,mult=1,result=0;
    printf("please enter the number:");
    scanf("%d",&num);
    int num1=num;
     test=num;
    while(num1 != 0){  //to find the number of digits
        num1=num1/10;
        NoD++;
    }
        while(num != 0){
            rem=(num%10);
            for(int count=NoD;count>0;count--){
                 mult =rem*mult;
                    //printf("mult=%d\n",mult);
            }
        result=result+mult;
        //  printf("result=%d\n",result);
        num=num/10;
        mult=1;
    }
        // printf("test =%d , result= %d\n",test,result);

    if(test==result){
        printf("The number you entered is Armstrong number");
    }
    else{
         printf("The number you entered not Armstrong number");
    }

    return 0;
}
