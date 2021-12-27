#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char output_filename[] = "Stock.txt";

int main()
{
    char filename[128] = {0};
    scanf(" %s", filename);
    FILE *amount_file = fopen(filename, "r");

    int people_num = 0, thisPeople;
    while (fscanf(amount_file, "%d", &thisPeople) != EOF)
        people_num += thisPeople;
    amount_file = NULL;
    fclose(amount_file);

    char foodname[128] = {0};
    int ingredient_count;
    scanf(" %s", filename);
    FILE *ingredient_file = fopen(filename, "r");
    FILE *stock_file = fopen(output_filename, "w");
    while (fscanf(ingredient_file, "%s %d", foodname, &ingredient_count) != EOF)
    {
        int stock_amount = ingredient_count * people_num;
        printf("%s %d\n", foodname, stock_amount);
        fprintf(stock_file, "%s %d\n", foodname, stock_amount);
    }
    ingredient_file = NULL;
    fclose(ingredient_file);
    fclose(stock_file);
    
    return 0;
}