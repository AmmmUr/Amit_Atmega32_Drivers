/*
***************************************************************************************************************
***************************************************************************************************************
**************************************       Name:عمار محمود محمد       ***************************************
**************************************       Group:D38 - Online         ***************************************
**************************************       Assignment:C Project       ***************************************
***************************************************************************************************************
***************************************************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define length 10 //number of entries in DataBase
#include "Headers.h"
uint8 Addc;
uint8 checkfull;
int main()
{
uint8 Operation,CheckAdd,grades[3],subjects[3],id,year,i,exist=0,cheack,list[length],counter;
char skip,number;
List:
    printf("\n------->(DataBase)<-------\n");
    printf("\n (1)-Add new entry to the database");
    printf("\n (2)-Display data of an entry using ID");
    printf("\n (3)-Check if ID exists");
    printf("\n (4)-Check if the database is full");
    printf("\n (5)-Delete entry using the ID");
    printf("\n (6)-the number of entries");
    printf("\n (7)-Get the list of IDs of the students");
    printf("\n (0)-Close the program\n");
    printf("\n Please pick the Operation: ");
    scanf("%d",&Operation);
    switch (Operation){
      case 1:
Add:
          for(Addc=0;Addc<length;Addc++){
                if(arr[Addc].student_ID==0){
                        printf("\nPlease enter the Student ID: ");
                        scanf("%u",&id);
                        exist=SDB_IsIdExist(id);
                        if(id==0){
                            printf("\nThe ID can't be Zero Please enter the ID again\n");
                            goto Add;
                        }
                        if(exist==1){
                            printf("\n The ID you entered already exists please enter again");
                            goto Add;
                        }
                        if(id>2150000000){
                           printf("\nThe ID can't be negative Please enter the ID again\n");
                           goto Add;
                        }
                        printf("Please enter the Student year: ");
                        scanf("%d",&year);
                        for (i=0;i<3;i++){
                        printf("Please enter Course %d ID: ",i+1) ;
                        scanf("%d",&subjects[i]);
                        printf("Please enter Course %d Grade: ",i+1) ;
                        scanf("%d",&grades[i]);
                        }
                        CheckAdd=SDB_AddEntry(id,year,grades,subjects);
                        if(CheckAdd == 1){
                        checkfull++;
                    printf("\nData is added successfully in Position (%d)\n ",Addc+1);
                    printf("\n\nPress (Enter) to go for the main List");
                    printf("\nor Enter (1) to Add another student: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Add;
                    else goto List ;
                }
                else{
                        arr[Addc].student_ID=0;
                        printf("\nSorry data not added please enter it again ");
                        printf("\nBe sure the (Grade from 0 to 100) or (Year less than 2023)\n");
                        goto Add;
                }
            }
         }
          printf("\nSorry DataBase is full ");
          printf("\n\nPress (Enter) to go for the main List");
          printf("\nor Enter (1) to Delete entry: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Delete;
                    else goto List ;
      case 2:
Display:
        printf("\nEnter the ID to Display : ");
        scanf("%d",&id);
        if(id==0){
            printf("\nThe ID can't be Zero Please enter the ID again");
            goto Display;
          }
        if(SDB_IsIdExist(id)){
        SDB_ReadEntry(id);
          printf("\n\nPress (Enter) to go for the main List");
          printf("\nor Enter (1) to Display another student data: ");
            scanf("%c",&skip);
            scanf("%c",&number);
            if(number=='1')goto Display;
            else goto List ;
        }
        else{
        printf("\n The ID you entered is not exists");
        printf("\n\nPress (Enter) to go for the main List");
        printf("\nor Enter (1) to Display another student data ,(2)to go for the ID List: ");
         scanf("%c",&skip);
         scanf("%c",&number);
         if(number=='1')goto Display;
         else if(number=='2')goto IDList;
         else goto List ;
        }

      case 3:
Exist:
          printf("\nPlease enter the ID to check : ");
          scanf("%d",&id);
          exist=SDB_IsIdExist(id);
          if(id==0){
            printf("\nThe ID can't be Zero Please enter the ID again");
            goto Exist;
          }
          if(exist==1){
            printf("\n The ID you entered is (exists)\n");
            printf("\n\nPress (Enter) to go for the main List");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                        goto List;
          }
          else {
          printf("\n The ID you entered (not exists)\n");
          printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Display the IDs : ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto IDList;
                    else goto List ;
          }
    case 4:
        cheack=SDB_isFull();
        if(cheack==1){
            printf("\n---(DataBase is full)---\n\n");
            printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Delete entry: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Delete;
                    else goto List ;
        }
        else{
            printf("\n---(Database is not full. There is %d position(s) full out of %d )---\n\n",checkfull,length);
            printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Add entry , (2) to Delete entry: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Add;
                    else if (number=='2') goto Delete;
                    else goto List ;
        }
    case 5:
Delete :
    printf("\nPlease enter the ID to Delete : ");
    scanf("%d",&id);
    if(id==0){
      printf("\nThe ID can't be Zero Please enter the ID again");
      goto Delete;
        }
        if(SDB_IsIdExist(id)){
           SDB_DeleteEntry(id);
           checkfull--;
           printf("\n\nPress (Enter) to go for the main List.");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                        goto List ;
        }
        else{
            printf("\nThe Id you entered not exists ");
            printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Add entry or (2) to Delete entry , (3) to Display the ID List: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Add;
                    else if (number=='2') goto Delete;
                    else if (number=='3') goto IDList;
                    else goto List ;
        }
    case 6:
    counter=SDB_GetUsedSize();
    printf("\n---( There is %d place(s) used out of %d )---\n\n",counter,length);
            printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Add entry or (2) to Delete entry , (3) to Display the ID List: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Add;
                    else if (number=='2') goto Delete;
                    else if (number=='3') goto IDList;
                    else goto List ;
    case 7:
IDList:
    for(i=0;i<length;i++){
        list[i]=0;
    }
    SDB_GetIdList(&list[0],&counter);
    printf("\nThere is (%d) ID(s) Found",counter);
    for(i=0;i<length;i++){
        if(list[i]!=0){
           printf("\n==[ ID (%d) in position %d ]==",list[i],i+1);
        }
    }
    printf("\n\nPress (Enter) to go for the main List");
            printf("\nor Enter (1) to Add entry , (2) to Delete entry: ");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                    if(number=='1')goto Add;
                    else if (number=='2') goto Delete;
                    else goto List ;

    case 0 :
    printf("\n\n \tHave a nice day\n\n");
    return 0;
    default :
        printf("\n\nInvalid !! \nPress (Enter) to go for the main List:");
                    scanf("%c",&skip);
                    scanf("%c",&number);
                        goto List ;
}
}

bool SDB_AddEntry(uint8 id,uint8 year,uint8*g,uint8*c){
if(*g<101&&*(g+1)<101&&*(g+2)<101&&year<2023){
    arr[Addc].student_ID=id;
    arr[Addc].student_year=year;
    arr[Addc].course1_ID=c[0];
    arr[Addc].course2_ID=c[1];
    arr[Addc].course3_ID=c[2];
    arr[Addc].course1_grade=g[0];
    arr[Addc].course2_grade=g[1];
    arr[Addc].course3_grade=g[2];
    return 1;
}
else return 0;
}
void SDB_ReadEntry(uint8 id){
uint8 i;
    for(i=0;i<length;i++){
            if(id==arr[i].student_ID){
                    printf("\nStudent ID   : %d",arr[i].student_ID);
                    printf("\nStudent Year : %d",arr[i].student_year);
                    printf("\nCourse 1 ID  : %d",arr[i].course1_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course1_grade);
                    printf("\nCourse 2 ID  : %d",arr[i].course2_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course2_grade);
                    printf("\nCourse 3 ID  : %d",arr[i].course3_ID);
                    printf("\nCourse 1 Grade : %d",arr[i].course3_grade);
             }
    }
}
bool SDB_IsIdExist(uint8 id){
    uint8 i;
    for(i=0;i<length;i++){
            if(id==arr[i].student_ID){
                return true;
            }
}
return false;
}
bool SDB_isFull(void){
    if(checkfull==length) return true;
    else return false ;
}
void SDB_DeleteEntry(uint8 id){
    int i;
    for(i=0;i<length;i++){
        if(arr[i].student_ID==id){
        arr[i].student_ID=0;
        arr[i].student_year=0;
        arr[i].course1_ID=0;
        arr[i].course2_ID=0;
        arr[i].course3_ID=0;
        arr[i].course1_grade=0;
        arr[i].course2_grade=0;
        arr[i].course3_grade=0;
        printf("\nThe entry is deleted successfully from position (%d)",i+1);
        }
    }

}

uint8 SDB_GetUsedSize(void){
    uint8 i,count=0;
    for(i=0;i<length;i++){
            if(arr[i].student_ID!=0){
                count++;
            }
    }
    return count;

}
void SDB_GetIdList(uint8*list,uint8*count){
        uint8 i;
        *count=0;
    for(i=0;i<length;i++){
            if(arr[i].student_ID!=0){
                list[i]=arr[i].student_ID;
                *count+=1;
            }
    }
}
