#ifndef COMMAND_PARSER_H   /* Include guard */
#define COMMAND_PARSER_H
<<<<<<< HEAD

/*
	- This function should be responsible for importing all details of the command
	- Should specify the type of the command "comment, cd, echo, expression - X=5 -, else"
	- Should specify the arguments of the command
=======
#include <stdbool.h>

/*
	- This function should be responsible for importing all details of the command
	- Should specify the type of the command "comment, cd, echo, expression - X=5 -, else"  <<<<<<<
	- Should specify the arguments of the command  <<<<<<<<
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
	- Should specify if the command is background or foreground
	- Should consider all parsing special cases, example: many spaces in  "ls     -a"
	- You're left free to decide how to return your imported details of this command
	- Best practice is to use helper function for each collection of logical instructions,
	  example: function for splitting the command by space into array of strings, ..etc
*/
<<<<<<< HEAD
void parse_command( const char* command );
=======
bool parse_command( const char* command );
void split_line( const char* command );
void is_background();
bool determine_command();
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40


#endif // COMMAND_PARSER_H
