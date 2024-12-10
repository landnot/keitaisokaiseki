#include <stdio.h>
#include<string.h>
#include "readDictionary.h"

void readDictionary(words* data,int* num,char* file){//単語辞書の読み込み,numは要素数

    int j=0;
    
    FILE *d;
    d=fopen(file,"r");
    while(fscanf(d,"%s %s",data[j].kind,data[j].word)!=EOF){
 
        j++;

    }
    *num=j;



    fclose(d);


}



