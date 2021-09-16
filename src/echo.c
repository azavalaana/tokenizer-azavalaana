#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#define MAX 300

int count = 0;

int main()
{
    printf("Enter a String.\n> ");
    char user_input[MAX];
    fgets(user_input, MAX, stdin);
    printf("\nInput: %s\n", user_input);
  
    char* str_copy = copy_str(user_input, string_length(user_input));
    
    printf("Number of words: %d\n", count_words(user_input));
    
    char* start_word = word_start(user_input);
    printf("Start of Word: %s\n", start_word);
    
    char* end_word = word_terminator(start_word);
    printf("End of word: %s\n", end_word);
    
    start_word = word_start(end_word);
    printf("Start of next: %s\n", start_word);
    end_word = word_terminator(start_word);
    printf("End of next: %s\n",end_word);
    start_word = word_start(end_word);
    printf("Start of next: %s\n", start_word);
    end_word = word_terminator(start_word);
    printf("End of next: %s\n",end_word);
    start_word = word_start(end_word);
    printf("Start of next: %s\n", start_word);
    end_word = word_terminator(start_word);
    printf("End of next: %s\n",end_word);
    
    printf("Copy of String: %s\n", str_copy);
    
    return 0;

}
