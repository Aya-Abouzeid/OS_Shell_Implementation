#ifndef COMMANDS_H_   /* Include guard */
#define COMMANDS_H_
<<<<<<< HEAD
=======
#include <stdbool.h>

>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

/*
	- This function should be responsible for implementing the "cd" shell command
*/
<<<<<<< HEAD
void cd( const char* path );

=======
void cd( const char* words[], int words_length ,bool background  );
void exp(const char* words[], int words_length ,bool background  );
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
/*
	- This function should be responsible for implementing the "echo" shell command
	- Typically should lookup any variable included in the message
*/
<<<<<<< HEAD
void echo( const char* message );
=======
void echo( const char* words[] , int words_length ,bool background  );

void execute_command(const char* words[] , int words_length ,bool background, char* path );;
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

#endif // COMMANDS_H_
