#ifndef H_DEFINE//#インクルードガード…複数回ファイルがincludeされるのを防ぐ
#define H_DEFINE//#

#define MAX_WORDS 30//最大単語数
#define MAX_LENGTH 45//一単語当たりの最大文字数



typedef struct
{//単語と品詞のセット
    char word[MAX_LENGTH];
    char kind[6]; 
}words;

typedef struct{//遷移可能な品詞対
    char pre[6];
    char now[6];
}relation;


#endif//#