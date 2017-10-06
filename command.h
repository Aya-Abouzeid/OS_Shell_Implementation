#ifndef COMMANDS_H_   /* Include guard */
#define COMMANDS_H_
#include <stdbool.h>


/*
	- This function should be responsible for implementing the "cd" shell command
*/
void cd( const char* words[], int words_length ,bool background  );
void exp(const char* words[], int words_length ,bool background  );
/*
	- This function should be responsible for implementing the "echo" shell command
	- Typically should lookup any variable included in the message
*/
void echo( const char* words[] , int words_length ,bool background  );

void execute_command(const char* words[] , int words_length ,bool background, char* path );;

#endif // COMMANDS_H_
