#include <stdio.h>
#include<string.h>
#include "output.h"
//未使用
void output(words* result,int num,int max){
    int i;
    for(i=0;i<num;i++){
        printf("%s",result[i].word);
    }
    printf("\n");
        for(i=0;i<num;i++){
        printf("  |  ");
    }
    printf("\n");
    for(i=0;i<num;i++){
        switch (result[i].k)
        {
        case -1:
        printf("start ");
        break;
        case 0:
        
        default:
            break;
        }

    }



}


