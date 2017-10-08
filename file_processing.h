#ifndef FILE_PROCESSING_H_   /* Include guard */
#define FILE_PROCESSING_H_
#include "stdio.h"

/*
	history file basic functions' prototypes
*/

void open_history_file();
FILE *get_history_file();
void close_history_file();
<<<<<<< HEAD
=======
void get_history();
void write_history(char* text);
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

/*
	log file basic functions' prototypes
*/


void open_log_file();
FILE *get_log_file();
void close_log_file();


/*
	CommandsBatch file basic functions' prototypes
*/

void open_commands_batch_file();
FILE *get_commands_batch_file();
void close_commands_batch_file();


#endif // FILE_PROCESSING_H_
