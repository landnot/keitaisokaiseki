#include <stdio.h>
#include <string.h>
#include "define.h"
#include "readDictionary.h"
#include "check.h"


void out(words* results,int n,FILE* a);

int main(int argc, char *argv[]){
    int i,dictioNUM,inputNum;
    char input[MAX_WORDS][MAX_LENGTH];
    int j=0;


    words dictionary[MAX_WORDS];
    readDictionary(dictionary,&dictioNUM,argv[1]);//単語辞書の読み込み(dictionary〇.txt)
    FILE *a;
    a=fopen(argv[2],"r");
    while (fscanf(a,"%s",input[j])!=EOF)//入力文の読み込み(input〇.txt)
    {
       // printf("%s\n",input[j]);
        j++;

    }
    inputNum=j;
    fclose(a);

    a=fopen(argv[4],"w");


    words result[inputNum+2];
    strcpy(result[0].kind,"start");strcpy(result[0].word," ");
    out(result,1,a);

    for(i=1;i<inputNum+1;i++){
        result[i]=check(dictionary,input[i-1],dictioNUM);//単語辞書から品詞を付与する
      
        if(typeCheck(result[i-1].kind,result[i].kind,argv[3])==1){//規則の読み込み(relation.txt)と前後の単語が規則に沿うかのチェックを行う
            out(result,i+1,a);
          
        }else{
            fprintf(a,"incorrect\n");
            fclose(a);
            return 0;
            break;
        }

    }

    strcpy(result[inputNum+1].kind,"end");strcpy(result[inputNum+1].word,".");
        if(typeCheck(result[inputNum].kind,result[inputNum+1].kind,argv[3])==1){
            out(result,inputNum+2,a);
           // printf("yes\n");
        }else{
            fprintf(a,"incorrect\n");
            fclose(a);
            return 0;
        }
   // out(result,inputNum+2,a);
    fprintf(a,"correct sentence\n");
    fclose(a);

    return 0;

}


void out(words* results,int n,FILE* a){//resultsの内容を書き出す
    int i;int space[n];
    for(i=0;i<n;i++){
        if(strlen(results[i].word)>4)//単語の文字数が4より大きい場合,spaceの大きさを文字数+2とする
        space[i]=strlen(results[i].word)+2;
        else space[i]=6;
        fprintf(a,"%-*s",space[i],results[i].word);//%-*s…左寄せ
    }
    fprintf(a,"\n");
    for(i=0;i<n;i++){
        fprintf(a,"%-*s",space[i],"|");
    }
    fprintf(a,"\n");
    for(i=0;i<n;i++){
        fprintf(a,"%-*s",space[i],results[i].kind);
    }
    fprintf(a,"\n\n");

}