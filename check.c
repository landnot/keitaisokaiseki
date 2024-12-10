#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "check.h"
words check(words* data,char* what,int n){//dataは辞書,whatは調べたい単語,nは辞書の単語数
    int i;words a;
    strcpy(a.word,what);
    for(i=0;i<n;i++){
        if(strcmp(what,data[i].word)==0)
        strcpy(a.kind,data[i].kind);
    }
    return a;

}

void readRelation(relation **r,int* aa,char* file){
    FILE *re;
    re=fopen(file,"r");
    int n,i;
    fscanf(re,"%d",&n);
    *aa = n;
    *r=(relation*)malloc(n*sizeof(relation));

    for(i=0;i<n;i++){

        fscanf(re,"%s %s",(*r)[i].pre,(*r)[i].now);

    }
    fclose(re);
    return;

}

int typeCheck(char* pre,char* now,char* file){
    int n;//rの要素数
    relation *r;readRelation(&r,&n,file);//遷移可能な品詞対のリスト
    int i=0;
    //printf("%d\n",n);
    //printf("%d %d\n",pre,now);
    for(i=0;i<n;i++){
        //printf("%d %d\n",r[i].pre,r[i].now);
        if((strcmp(r[i].pre,pre)==0)&&(strcmp(r[i].now,now)==0))//rの中の組み合わせに当てはまるものがあれば1,そうでなければ0を返す
        return 1;
    }
    return 0;
    
  
}