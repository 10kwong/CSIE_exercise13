#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 10000001

int main()
{
    char filename[128]={0};
    scanf("%s",filename);
    FILE *in;
    in = fopen(filename, "r");
    if (in == NULL) return 0;

    char *key = (char *) malloc(N * sizeof(char));
    char *text = (char *) malloc(N * sizeof(char));
    
    fscanf(in, "%s", key);
    while(fscanf(in, "%s", text) != EOF){
        for (int i = 0; i < strlen(key); i++)
        {
            char k = key[i];
            char t = text[i];

            if (k == t) printf("0");
            else printf("1");
        }
        printf("\n");
    }

    free(key);
    free(text);
    return 0;
}
