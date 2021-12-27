#include <stdio.h>
#include <stdlib.h>
 
#include "survey.h"
//#include "survey.c"
//survey.c 在 自己的電腦上需要保留就好，上傳時千萬別留著。（如果是用devC++的話）
int main() {
    char s[128]={0};
    scanf("%s", s);
    //輸入檔名后傳給survey.c
    print_avg(s);
    return 0;
}