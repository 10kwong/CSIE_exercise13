#include "survey.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_avg(char s[])
{
    char filename[128];
    strcpy(filename,s);
    FILE* fp;
    fp = fopen(filename, "r");
    int k=0, input;
    double total=0;
    double avg;
    while(fscanf(fp, "%d", &input)!=EOF)
    {
        total+=input;
        k++;
        //printf("%.2f %d\n", total, k);
    }
    avg=total/k;
    printf("%.2lf", avg);
    fclose(fp);
}