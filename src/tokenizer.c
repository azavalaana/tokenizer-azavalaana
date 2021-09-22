#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "history.c"
#define true 1
#define false 0

/* Return true (non-zero) if c is a whitespace characer ('\t' or ' '). */ 
int space_char(char c)
{
    if(c == ' ' || c == '\t' || c == '\0') 
        return true;
    return false;
}

/* Return true (non-zero) if c is a non-whitespace character (not tab or space). */
int non_space_char(char c)
{
    if(c != ' ' && c != '\t' && c != '\0') 
        return true;
    return false;
}

/* Returns a pointer to the first character of the next space-separated word in zero-terminated str. */
char *word_start(char *str)
{
    while(!non_space_char(*str))
    {
        str++;
    }
    return str;
}

/* Returns a pointer to the first space character in zero-terminated str. */
char *word_terminator(char *str)
{
    while(non_space_char(*str))
    {
        str++;
    }
    return str;
}

/* Counts the number of words in the string argument. */
int count_words(char* str)
{
    char *p = str;
    int words = 0;
    
    while (*p)
    {
        if(space_char(*p++))
            words++;
    }
    words++;

    return words;
    
}

/* Returns a fresly allocated new string containing <len> chars from <inStr> */
char* copy_str(char* inStr, short len)
{
    char* copy = NULL;
    char* pointer = inStr;
    
    copy = (char*)malloc((len + 1) * sizeof(char)); //allocate extra memory for '0\'
    copy[len] = '\0'; //add '\0' to the end of the string
    
    int plc = 0; 
    while(*pointer != '\0') {
        copy[plc++] = *pointer++;
    }
    return copy;
}

/* Helper method to copy_str using pointer arithmetic*/
int string_length(char *str)
{
    int num_chars = 0;
    while (*str != '\0')
    {
        num_chars++;
        str++;
    }
    num_chars--;
    return num_chars;
}

/* Tokenizer function */
char **tokenize(char* str){
    int size = count_words(str);
    char **tokens = (char**)malloc((size + 1) * sizeof(char*));
    
    char* start = str;
    char* end = word_terminator(str);
    
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(i > 0) {
            start = word_start(end);
            end = word_terminator(start);
        }
        
        int word_size = end - start;
        //printf("%d\n", word_size);
        tokens[i] = malloc(word_size * sizeof(char));
        
        for(int j = 0; j < word_size; j++)
        {
            tokens[i][j] = start[j];
        }
    }
    tokens[i] = '\0';
    return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
    int i;
    for(i = 0; tokens[i] != NULL; i++)
    {
        printf("Token [%d]: %s\n", i, tokens[i]);
    }
    //  printf("Token [%d]: %s\n\n", i, "0");
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    int i;
    for(i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}
