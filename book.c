#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 10000001
#define book_size 10001
#define book_name_length 1025

const char obj[2] = ",";
char path[128]= "1147/";

typedef struct 
{
    char name[book_name_length];
    int count;
} Book;

void initializeBook (int , Book *);
void printB(Book );
int found(Book *, char *, int);
int compare(const void *, const void *);

int main(int argc, char *argv[])
{
    char filename[128]={0};
    scanf("%s",filename);
    FILE *in;
    in = fopen(filename, "r");

    // if (in == NULL) return 0;

    int size = 0;
    Book *books = (Book *) malloc(book_size * sizeof(Book));
    initializeBook(book_size, books);

    char *input = (char *) malloc(N * sizeof(char));
    char *token;
    Book temp;
    initializeBook(1, &temp);

    while(fgets(input, N, in) != NULL){
        // printf("%s", input);
        token = strtok(input, obj); // obj == ","
        // printf("%s ... ", token);
        strcpy(temp.name, token);
        token = strtok(NULL, obj);  
        // printf("%s ... ", token);
        temp.count = atoi(token);

        // string processing
        for (int i = 0 ; i < strlen(temp.name); i++)
            temp.name[i] = tolower(temp.name[i]);
        

        int idx = found(books, temp.name, size);
        
        if (idx == size)
        {
            books[size].count = temp.count; 
            strcpy(books[size].name, temp.name);
            size++;
        }
        else
        {
            books[idx].count += temp.count;
        }
    }
    // while(fscanf(in, "%[^\n]", input) != EOF){
    //     printf("%s", input);
    //     fgetc(in);
    // }

    qsort(books, size, sizeof(Book), compare);
    for (int i = 0 ; i < size ; i++)
        printB(books[i]);

    if (argc == 2)
    {
        printf("Output file to %s\n", argv[argc-1]);
        FILE *file = fopen(argv[argc-1], "w");
        for (int i = 0; i < size ; i++)
            fprintf(file, "%s,%d\n", books[i].name, books[i].count);
        fclose(file);
    }

    free(input);
    free(books);
    fclose(in);
    return 0;
}

void initializeBook (int n, Book *book)
{
    for (int i = 0; i < n ; i++)
        book[i].count = 0;
    return; 
}

void printB(Book book)
{
    printf("%s,%d\n", book.name, book.count);
}

int found(Book *books, char *name, int size)
{
    for (int idx = 0 ; idx < size ; idx++)
    {
        if (strcmp(books[idx].name, name) == 0)
            return idx;
    }
    return size;
}

int compare(const void *a, const void *b)
{
	Book *A = (Book *)a;
    Book *B = (Book *)b;
    return strcmp(A->name, B->name);
}