/*
Name:عمار محمود محمد
Group:D38 - Online
Assignment: 1-2
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,toggle,nth,bt;
    printf("Please enter the number:");
    scanf("%d",&num);
    printf("Please nth bit to toggle (0-31):");
    scanf("%d",&nth);
    bt=(1<<nth);
    toggle=(num^bt);
    printf("Bit toggled successfully.\n");
    printf("\nThe number before toggling:%d (in decimal)",num);
    printf("\nThe number after toggling:%d (in decimal)",toggle);
    return 0;
}
