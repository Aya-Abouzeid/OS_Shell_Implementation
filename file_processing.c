#include "file_processing.h"
#include "stdio.h"
/*
	history file section
*/
<<<<<<< HEAD
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
=======
FILE *batch;
FILE *history;
FILE *log;


char* concat2(char* first, char* second);
//void get_history()
//{
//printf("here");
//
//		char* h= concat2(getenv("HOME"), "MyHisory");
//
//history = fopen(h, "r");
//	char text[513];
//	if (history == NULL) {
//		printf("No History\n");
//	}else {
//	while (fgets(text, 513, history) != NULL) {
//		printf("%s \n ", text);
//	}
//fclose(history);
//}
//}
//void write_history(char* text){
//
//    char* h= concat2(getenv("HOME"), "MyHisory");
//		if( fopen(h, "r") == NULL){
//        history = fopen(h, "a");
//        }
//        else {
//        history = fopen(h, "w");
//        }
//
//fprintf(history, "%s \n", text);
//	fclose(history);
//
//}

//FILE *get_history_file()
//{
//   /* FILE *fp;
//	fp = fopen(HISTORY_FILE, "r");
//	char str[MAX_SIZE];
//	if (fp == NULL) {
//		printf("No previous History\n");
//		return;
//	}
//	while (fgets(str, MAX_SIZE, fp) != NULL) {
//		printf("%s", str);
//	}
//	fclose(fp);*/
//return history;
//
//}

void write_log(char* text){


}
//void close_history_file()
//{
//	// you should implement this function
//	fclose(history);
//}
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40


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
<<<<<<< HEAD
=======
	return log;
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
}

void close_log_file()
{
	// you should implement this function
<<<<<<< HEAD
=======
	fclose(log);

>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
}


/*
	CommandsBatch file section
*/
void open_commands_batch_file()
{
	// you should implement this function

<<<<<<< HEAD
	file = fopen("C:\\Users\\aya_a_000\\Desktop\\shell.txt","r");

	if(file == NULL)
   {
      printf("File Not Found!");
      exit(1);
   }
=======
//fp = fopen("textFile.txt" ,"a");
//
//	file = fopen("C:\\Users\\aya_a_000\\Desktop\\shell.txt","r");
//
//	if(file == NULL)
//   {
//      printf("File Not Found!");
//      exit(1);
//   }
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

}

FILE *get_commands_batch_file()
{

<<<<<<< HEAD
    return file;
=======
    return batch;
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
	// you should implement this function
}

void close_commands_batch_file()
{
	// you should implement this function
<<<<<<< HEAD
	fclose(file);
}
=======
	fclose(batch);
}

>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
