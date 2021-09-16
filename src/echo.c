#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#define MAX 300

int count = 0;

int main()
{
  /* First Milestone: Simple functioning UI that echos user input */
  printf("Enter a String.\n> ");
  char user_input[MAX];
  fgets(user_input, MAX, stdin);
  printf("\nInput: %s\n", user_input);

  /* After milestone one echo.c becomes the main ui for the tokenizer */
  /*Second Milestone: test commands using the input from milestone one */

  /* Count_words test */
  printf("Number of words: %d\n\n", count_words(user_input));
  
  /* word_start & word_terminator test */
  /* these also test space_char & non_space_char */
  char* start_word = word_start(user_input);
  printf("Start of Word: %s\n", start_word);
  char* end_word = word_terminator(start_word);
  printf("End of word: %s\n", end_word);
  
  // Copy_str test
  char* str_copy = copy_str(user_input, string_length(user_input));
  printf("Copy of String: %s\n", str_copy);
  
  // 4 Words String Test make sure with or without final backspace would display 4 words and no errors
  /*
  while(int i=1 ; i < 4; i++){
  start_word = word_start(end_word);
  printf("Start of next: %s\n", start_word);
  end_word = word_terminator(start_word);
  printf("End of next: %s\n",end_word);
  }
  /*
  start_word = word_start(end_word);
  printf("Start of next: %s\n", start_word);
  end_word = word_terminator(start_word);
  printf("End of next: %s\n",end_word);
  start_word = word_start(end_word);
  printf("Start of next: %s\n", start_word);
  end_word = word_terminator(start_word);
  printf("End of next: %s\n",end_word);
  */
    
  return 0;

}
