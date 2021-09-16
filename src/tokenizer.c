#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "history.c"

// Return true (non-zero) if c is a whitespace characer ('\t' or ' ').  
int space_char(char c)
{
    if(c == ' ' || c == '\t') 
    {
        return 1;
    }
    return 0;
}

//Return true (non-zero) if c is a non-whitespace character (not tab or space).  
int non_space_char(char c)
{
    if(c == ' ' || c == '\t') 
    {
        return 0;
    }
    return 1;
}

// Returns a pointer to the first character of the next space-separated word in zero-terminated str.
char *word_start(char* str)
{
  if (count_words(str) > 0) // Determine if more than zero words exist
    {
        int ptr = 0; //Initialize a pointer
        if (space_char(str[ptr])) //In case it starts on a whitespace can skip to first letter
        {
            str++;
        }
        while (space_char(str[ptr]))
        {
            ptr++;
        }
        return (str++); //Returns a pointer to the first character of the next space-separated word
    }
        return str; // Return original array if no valid chars exist
}

// Returns a pointer to the first space character in zero-terminated str.
char *word_terminator(char* str)
{
    while(non_space_char(*str))
    {
        str++;
        if (*str == 32) //Set to 32 as it means it doesn't point anywhere 
        //if (space_char(*str))
            {
                return str; // Return the end of current word
            }
    }
    return "0";
    /*
    if (count_words(str) > 0) // Determine if more than zero words exist
    {
        int ptr = 0; //Initialize a pointer
        while (non_space_char(*str))
        {
            str++;
        }
        return (str++); //Returns a pointer to the first character of the next space-separated word
    }
        return "0"; // Return original array if no valid chars exist
        */
}

// Counts the number of words in the string argument. 
int count_words(char* str)
{
    int i = 0;
    int count = 0;

    while(str[i] != '\0')
{
        if(non_space_char(str[i]) && space_char(str[i+1]))
        {
            count++;
        }
        i++;
    }
    count += 1;
    if (space_char(str[i-2]))
    {
        count--;
    }
    return count;
}

/* Returns a fresly allocated new string containing <len> chars from <inStr> */
char* copy_str(char* inStr, short len)
{
    char* copy = (char*)malloc(len+1 * sizeof(char));
    int plc = 0;
    while(plc<len) {
        //printf("[%d]: %c", i, inStr[i], "\n");
        copy[plc] = inStr[plc];
        plc++;
        //printf("[%d]: %c", i, copy[i], "\n");
    }
    return copy;
}

/* Helper method to copy_str*/
int string_length(char *str)
{
    int num_chars = 0;
    int pos = 0;
    while(str[pos])
    {
        num_chars++;
        pos++;
    }
    return num_chars;
}
