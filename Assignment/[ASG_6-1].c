/*
***************************************************************************************************************
***************************************************************************************************************
**************************************       Name:عمار محمود محمد       ***************************************
**************************************       Group:D38 - Online         ***************************************
**************************************       Assignment: 6-1            ***************************************
***************************************************************************************************************
***************************************************************************************************************
 */
#include <stdio.h>
#include <string.h>
struct StudentData{
    char StudentName [30] ;
    int StudentAge;
    int StudentDegree;
    int StudentSection;
};
void Print(struct StudentData*);
int main()
{
    unsigned int StudentNum;
    struct StudentData sd[5]={"Ammar Mahmoud Mohamed",21,95,1,
                               "Mohamed Ali Khalid",21,89,1,
                               "Mohamed Salah Hamed",20,99,2,
                               "Mostafa Mohamed Hassan",20,92,2,
                               "Sarah Ali Khalid",20,88,3};
    printf("Please Enter the Student Number( 1 -> 5 ): ");
    scanf("%d",&StudentNum);
    while(StudentNum>0 && StudentNum<6){
    printf("\n----->( Data of Student %d )<-----",StudentNum);
    struct StudentData *ptr=&sd[StudentNum-1];
    Print(ptr);
    return 0;
    }
    printf("You entered a wrong number");

    return 0;
}
void Print(struct StudentData* pointer){
    printf("\nStudent Name: %s",pointer->StudentName);
    printf("\nStudent Age: %d",pointer->StudentAge);
    printf("\nStudent Degree: %d",pointer->StudentDegree);
    printf("\nStudent Section: %d",pointer->StudentSection);
}
