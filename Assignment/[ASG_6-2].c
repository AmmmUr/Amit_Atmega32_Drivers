/*
***************************************************************************************************************
***************************************************************************************************************
**************************************       Name:عمار محمود محمد       ***************************************
**************************************       Group:D38 - Online         ***************************************
**************************************       Assignment: 6-2            ***************************************
***************************************************************************************************************
***************************************************************************************************************
 */
#include <stdio.h>
#include <string.h>
struct Comp{
    float real;
    float imaginary;
};
void add(struct Comp*,struct Comp*);
int main()
{
    struct Comp num1;
    struct Comp num2;
    printf("--->Adding 2 Complex Numbers<---\n");
    printf("\nEnter the first real number: ");
    scanf("%f",&num1.real);
    printf("Enter the first imaginary number: ");
    scanf("%f",&num1.imaginary);
    printf("\nEnter the second real number: ");
    scanf("%f",&num2.real);
    printf("Enter the second imaginary number: ");
    scanf("%f",&num2.imaginary);

    printf("\n----->( the sum )<-----");
    struct Comp *ptr1=&num1;
    struct Comp *ptr2=&num2;
    add(ptr1,ptr2);
    return 0;
}
void add(struct Comp*p1,struct Comp*p2){
    static struct Comp sum;
    sum.real=p1->real+p2->real;
    sum.imaginary=p1->imaginary+p2->imaginary;
    printf("\n   = %.2f + %.2f i",sum.real,sum.imaginary);
}
