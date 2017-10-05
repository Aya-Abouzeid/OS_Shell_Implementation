#include "file_processing.h"
#include "stdio.h"
/*
	history file section
*/
FILE *file;

void open_history_file()
{
	// you should implement this function
}

FILE *get_history_file()
{
   /* FILE *fp;
	fp = fopen(HISTORY_FILE, "r");
	char str[MAX_SIZE];
	if (fp == NULL) {
		printf("No previous History\n");
		return;
	}
	while (fgets(str, MAX_SIZE, fp) != NULL) {
		printf("%s", str);
	}
	fclose(fp);*/
	// you should implement this function
}

void close_history_file()
{
	// you should implement this function
}


/*
	log file section
*/
void open_log_file()
{
	// you should implement this function
}

FILE *get_log_file()
{
	// you should implement this function
}

void close_log_file()
{
	// you should implement this function
}


/*
	CommandsBatch file section
*/
void open_commands_batch_file()
{
	// you should implement this function

	file = fopen("C:\\Users\\aya_a_000\\Desktop\\shell.txt","r");

	if(file == NULL)
   {
      printf("File Not Found!");
      exit(1);
   }

}

FILE *get_commands_batch_file()
{

    return file;
	// you should implement this function
}

void close_commands_batch_file()
{
	// you should implement this function
	fclose(file);
}
