#include "stdio.h"
#include "stdlib.h"
#define FILE_PROCESSING_H_
#include "file_processing.h"
#define _GNU_SOURCE
#include <string.h>
#include "environment.h"
<<<<<<< HEAD

typedef enum{ false = 0 , true = 1 } bool ;
FILE *file;
FILE *log;
FILE *history;
int maxLength;
const char* path;
const char* home;
char c; //for reading new lines
int index; // for index in newline
char *s; //of dynamic size to read command with unknown length

void start_shell(bool read_from_file);
void shell_loop(bool input_from_file);
int main(int argc, char *argv[])
{

    setup_environment();
     path= get_path();
    home= get_home();
     maxLength = get_max_length();

    // any other early configuration should be here
    if( argc > 1 ){
        start_shell(true);
    }
    else{
        start_shell(false);
    }
=======
#include "command_parser.h"
#include <stdbool.h>


int maxLength;
const char* path;
  char *line = NULL;
char* batch_path;
const char* home;
int bufsize = 1024;
char *buffer;  //buffer for 1024 characters
char c; //for reading new lines
int index1; // for index in newline
 //of dynamic size to read command with unknown length
void start_shell(bool read_from_file);
void shell_loop(bool input_from_file);

int main(int argc, char *argv[])
{

         setup_environment();
         path= get_path();
         home= get_home();
         maxLength = get_max_length();

        if( argc == 2 ){
        batch_path = argv[1];
            start_shell(true);
        }
        else{
            start_shell(false);
        }



>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

    return 0;
}

void start_shell(bool read_from_file)
{
<<<<<<< HEAD
	cd(""); // let shell starts from home

	if(read_from_file){
		// file processing functions should be called from here
open_commands_batch_file();
file = get_commands_batch_file();
		shell_loop(true);
=======
	chdir (home); // let shell starts from home


	if(read_from_file){

        shell_loop(true);
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
	}
	else{
		shell_loop(false);
	}
}

void shell_loop(bool input_from_file)
{
	bool from_file = input_from_file;

	while(true){
		if(from_file){
<<<<<<< HEAD
			//read next instruction from file
//char line[256];
=======

		char command[513];
		char* h= batch_path;
		    FILE* batch = fopen(h, "r");

        if (batch == NULL) {
		perror("Error opening file");
		return;
		}


        while (fgets(command, 513, batch)) {
        if (command[0] == '\n') {
						continue;
		}
            printf("Command: %s", command);
            int length = strlen(command);
            if(command[length-1] = '\n')
            command[length-1] = '\0';

            write_history(command);
            if(parse_command(command) == false)
                        break;
                        }
            fclose(batch);
    		 from_file = false;
    		 continue;

>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

  //  while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
      //  printf("%s", line);
    //}

<<<<<<< HEAD
    		// if end of file {from_file = false; continue;}
		}
		else{
			//read next instruction from console
s = malloc(1);
index =0;
    printf("\n Shell> ");
     while((c = getchar()) != '\n' )
    {
        s[index++] = c;
        s = realloc(s, index+1); // Add space for another character to be read.
    }
    s[index] = '\0';
    if(index != 0 ) {
    parse_command(s);
    }
    free(s);


		}

		//parse your command here

		//execute your command here

		/*
			you don't need to write all logic here, a better practice is to call functions,
			each one contains a coherent set of logical instructions
		*/
=======
		}
		else{

			buffer = malloc(sizeof(char) * bufsize);
                index1 =0;
                printf("\n Shell> ");


                     while((c = getchar()) != '\n' && c != EOF)
                    {

                       buffer[index1] = c;


                       index1++;

                       if (index1 >= bufsize) {
                      bufsize += 1024;
                      buffer = realloc(buffer, bufsize);

                      }

                    }

                    buffer[index1] = '\0';
                    if(index1 != 0 ) {
                        if(parse_command(buffer) == false)
                        break;
                    }
                    free(buffer);


		}


>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
	}
}
