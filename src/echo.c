#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include "tokenizer.c"
#define MAX 300

int count = 0;

int main()
{
    char user_input[MAX];
    int hist_id;
    char* hist_itm;
    List *history = init_history(); //Initialize History
    
    /* First Milestone: Simple functioning UI that echos user input */
    printf("\nEnter a String. Enter '!' to see history. Type 'x' to exit\nEnter \"!<number>\" to see a specific part of the history.\n");
    
    while(user_input[0] != 'x')
    {
        printf(">");
        fgets(user_input, MAX, stdin);
        
        if(user_input[0] == 'x') { //close program
            break;
        } 
        else if(user_input[0] == 'i') { //print instructions
            printf("Enter string. ! for history. x to exit\n\"!<number>\" see a specific part of history.\n");
        } 
        else if(user_input[0] == '!') { //history option
	  printf("\n\n\n %c \n\n\n", user_input[1]);
            if(user_input[1] == '\0'){ //print all history
                printf("Printing all history \n");
                print_history(history);
            }else{ //print specific part of history
                hist_id = atoi(user_input+1);
                hist_itm = get_history(history,hist_id);
                printf("History Item at %d: %s", hist_id, hist_itm);
            }
        } 
        else if(user_input[0] != '!') {
            printf("\nMilestone 1\nInput: %s\n", user_input);
            
            /* After milestone one echo.c becomes the main ui for the tokenizer */
            /*Second Milestone: test commands using the input from milestone one */
            printf("Milestone 2\n");
            /* Count_words test */
            int str_length = count_words(user_input);
            printf("Number of words: %d\n", str_length);
            
            /* word_start & word_terminator test */
            /* these also test space_char & non_space_char */
            char* start_word = word_start(user_input);
            printf("Start of Word: %s", start_word);
            char* end_word = word_terminator(start_word);
            printf("End of word: %s", end_word);
            
            // Copy_str test
            char* str_copy = copy_str(user_input, string_length(user_input));
            printf("Copy of String: %s\n", str_copy);
            
            /* Test whole string to make sure start and terminator work correctly
             *        int i = 1;
             *        while(i < str_length){
             *        start_word = word_start(end_word);
             *        printf("Start of next: %s\n", start_word);
             *        end_word = word_terminator(start_word);
             *        printf("End of next: %s\n",end_word);
             *        i++;
        }
        */
            /*Two part 2 Milestone: Make tokens using the methods implemented in milestone 2 & using the input from milestone one */
            printf("Milestone 2.5 \n");
            
            //Test Tokenizer & Print_tokens
            printf("Tokens from String: \n");
            char** tokens = tokenize(user_input);
            print_tokens(tokens);
            
            //Test free_tokens
            printf("...Freeing Tokens... \n");
            free_tokens(tokens);
            // printf("Print tokens: \n");
            //print_tokens(tokens);
            
            //Milestone 3 \: Keep a history of the tokenizer
            printf("\nMilestone 3 \n");
            
            add_history(history, str_copy);
            print_history(history);
            
            
        }
        printf("Type i to see instructions again\n");
    }
    printf("\nHistory of the run:\n");
    print_history(history);
    free_history(history);
    
    printf("On to the next one!\n");
    return 0;
    
}
