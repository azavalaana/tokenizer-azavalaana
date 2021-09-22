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
  printf("Enter a String. Type x to exit \n> ");
  char user_input[MAX];
  fgets(user_input, MAX, stdin);

  if(user_input[0] == 'x'){
    printf("On to the next one!\n");
    return 0;
  }

  printf("\nMilestone 1\nInput: %s\n", user_input);

  /* After milestone one echo.c becomes the main ui for the tokenizer */
  /*Second Milestone: test commands using the input from milestone one */
  printf("Milestone 2\n");
  /* Count_words test */
  int str_length = count_words(user_input);
  printf("Number of words: %d\n\n", str_length);
  
  /* word_start & word_terminator test */
  /* these also test space_char & non_space_char */
  char* start_word = word_start(user_input);
  printf("Start of Word: %s\n", start_word);
  char* end_word = word_terminator(start_word);
  printf("End of word: %s\n", end_word);
  
  // Copy_str test
  char* str_copy = copy_str(user_input, string_length(user_input));
  printf("Copy of String: %s\n", str_copy);
    
  // Test whole string to make sure start and terminator work correctly
  /*
  int i = 1;
  while(i < str_length){
  start_word = word_start(end_word);
  printf("Start of next: %s\n", start_word);
  end_word = word_terminator(start_word);
  printf("End of next: %s\n",end_word);
  i++;
  }
  */
  /*Third Milestone: Make tokens using the methods implemented in milestone 2 & using the input from milestone one */
  printf("Milestone 3\n");
  
  //Test Tokenizer & Print_tokens
  printf("Tokens from String: \n");
  char** tokens = tokenize(user_input);
  print_tokens(tokens);
  
  //Test free_tokens
  printf("Freeing Tokens: \n");
  free_tokens(tokens);
  print_tokens(tokens);
  
  if(user_input[0] != 'x')
    main();

  return 0;

}
