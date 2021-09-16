Project 1: Tokenizer
====================
## Introduction:

 The objective of the first lab project is to build a tokenizer that maintains a history. 
 Tokenizing is the process of dividing a string into tokens by some delimeter (e.g. the string librarys split() function). 
 Consider tokenizing the string “The cake is a lie!” using the space character. 
 This would result in: [“The”, “cake”, “is”, “a”, “lie!”].
 
 This directory contains source code for a program "tokenizer."
 
 ### Milestone 1: Building a Simple UI
 The file echo.c is a simple functioning user interface that does the job of just echoing the input back to the user.
 When the program runs it displays
 >Enter a String.
 >
 >\>
 
 Then after the user inputs a string it prints it back

 ### Milestone 2: Tokenizer
 The second milestone of your project is to define several of the functions declared and described in tokenizer.h 
 Each function definition appropriately uses the arguments and return the correct type declared in the method declaration. 
 
 #### Part 1: Working with Strings
 In the first part of milestone 2, the methods defined are
 - int space_char(char c); // true if c is a tab or space, and not zero
- int non_space_char(char c); // true if c not a tab or space, and not zero
- char *word_start(char *s); // * to first (non-space) char in first word in s
- char *word_terminator(char *word); // * to char after end of word
- int count_words(char *s); // the number of words in s
- char *copy_str(char *inStr, short len); // return a pointer to a (terminated) copy of inStr

 
 #### Part 2: Adding tokens 
 The last part is to put them together and define the tokenizer
 - char **tokenize(char *s);
 - void print_tokens(char**);
 - void free_tokens(char**);
 
 TBD
 
 ### Milestone 3: History
 TBD

## Compiling & Running the Code
To compile & execute the user interface program

While being inside this directory write on the terminal 
> make 
> 
This will compile the program, So to run it you'll write 
> 
> ./test 
> 
 (the compiling name is test since right now we are on the second milestone and it is still in a testing phase)
 
## Cleaning Directory
To remove the compiled files and program

While being inside this directory write on the terminal 
> make clean
> 
This will delete any -.o files as well as the executable
