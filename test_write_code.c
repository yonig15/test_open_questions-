#include <stdio.h>   
#include <stdlib.h> 
#include <conio.h>
#include <string.h>

#pragma warning(disable:4996)



char divleft(char str[100]) {

    int strLength = strlen(str);

    if (strLength == 1) return;

    char str1[50];
    //char* pstr = str1 + (strLength / 2);

    strncpy(str1, str, strLength/2);
    str1[strLength/2] = NULL;

    printf("%s\n", str1);

    divleft(str1);
}

int Add222(int num) {

    printf("%d\n", num);

    return (num < 100) ? Add222(num + 1) : printf("Done");
}


int main1_1_3()
{

    ////Question 1
    //puts("******Question 1***********");
    //char str[100];
    //printf("plese enter a string:");
    //gets(str);
    //char str1[50];
    //char str2[50];
    //int strLength = strlen(str);

    //char* pstr = str + (strLength/2);

    // strncpy(str1, str, strLength/2);
    // str1[strLength / 2] = NULL;
 
    // strcpy(str2, pstr);

    //printf("%s\n", str1);
    //printf("%s\n", str2);


    ////Question 2
    //puts("******Question 2***********");
    //printf("plese enter a string:");
    //char str[100];
    //gets(str);
    //divleft(str);


    ////Question 3
    //puts("******Question 3***********");
    //Add222(1);

    return 0;

}

