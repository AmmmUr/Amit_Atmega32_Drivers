/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 1-1
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Please enter the number:");
    scanf("%d",&num);
                         /*اذا افترضنا ان المستخدم ادخل الرقم 5 فعند القسمة على 2 سيكون الناتج 2 بدلا من 2.5

                        لانة يتم تخزينة في انتجر فعند ضربة في 2 لن يعود الرقم الى 5 فعند المقارنة مع ال5 ستكون النتيجة 0*/
    if((num/2)*2==num) {
         printf("\nThe number is odd=0");
         printf("\nThe number is even=1");
    }
    else{
        printf("\nThe number is odd=1");
        printf("\nThe number is even=0");
    }
    return 0;
}
