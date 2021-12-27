#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct
{
    char name[10];
    long int id;
    long int income;
    char S[1000005];
} Pumpkin;
 
int main() {
    int T;
    scanf("%d", &T);
    int N, I, G;
    long tempID;
    int tempLenS, pair;
    char tempS[1000002];
    for (int i = 0; i < T; i++) {
        scanf("%d%d%d", &N, &I, &G);
        Pumpkin *pumpkin = (Pumpkin *)malloc(sizeof(Pumpkin) * N);
 
        for (int j = 0; j < N; j++) {
            scanf("%s%ld%ld%d%s", pumpkin[j].name, &pumpkin[j].id, &pumpkin[j].income, &tempLenS, pumpkin[j].S);
        }
 
        for (int j = 0; j < I; j++) {
            scanf("%ld%d%s", &tempID, &tempLenS, tempS);
            pair = -1;
            for (int k = 0; k < N; k++) {
                if (pumpkin[k].id == tempID && (strcmp(pumpkin[k].S, tempS) == 0)) {
                    printf("True\n");
                    pair = 1;
                    break;
                }
            }
            if (pair == -1) {
                printf("False\n");
            }
        }
 
        for (int j = 0; j < G; j++) {
            scanf("%ld", &tempID);
            for (int k = 0; k < N; k++) {
                if (tempID == pumpkin[k].id) {
                    printf("%s %ld\n", pumpkin[k].name, pumpkin[k].income);
                    break;
                }
            }
        }
        free(pumpkin);
    }
    return 0;
}