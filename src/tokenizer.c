#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "history.c"

/* Return true (non-zero) if c is a whitespace characer ('\t' or ' '). */ 
int space_char(char c)
{
    if(c == ' ' || c == '\t' || c == '0') 
        return 1;
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace character (not tab or space). */
int non_space_char(char c)
{
    if(c == ' ' || c == '\t' || c == '0') 
        return 0;
    return 1;
}

/* Returns a pointer to the first character of the next space-separated word in zero-terminated str. */
char *word_start(char *str)
{
    if (space_char(*str)) //In case it starts on a whitespace can skip to first letter
        str++;
    while (space_char(*str))
    {
        if (non_space_char(*str++)) //In case it starts on a whitespace can skip to first letter
            return(str);
    }
    return (str++); 
}

/* Returns a pointer to the first space character in zero-terminated str. */
char *word_terminator(char *str)
{
    while(non_space_char(*str))
    {
        str++;
        if (*str == 32) //Set to 32 as it means space in ASCII
            return str; // Return the end of current word
        if (str == NULL)
            return "0";
    }
    return "0";
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
    if(word_terminator(p) == "0")
        words++;
    return words;
    
}

/* Returns a fresly allocated new string containing <len> chars from <inStr> */
char* copy_str(char* inStr, short len)
{
    char* copy = (char*)malloc(len+1 * sizeof(char));
    copy[len] = '\0';
    
    int plc = 0;
    while(*inStr != '\0') {
        copy[plc] = *inStr++;
        plc++;
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
    return num_chars;
}

/* Tokenizer function */
char **tokenize(char* str){}

/* Prints all tokens. */
void print_tokens(char **tokens){}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){}
