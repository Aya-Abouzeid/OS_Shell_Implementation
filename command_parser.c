#include "command_parser.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "environment.h"

char *words[]; // array for words in commands
int words_index; //for accessing the array
char *temp; // for reading words.
int temp_index;
int index; // for looping on command.
int max_length;
int boolean;
int i;
void parse_command( const char* command )
{
	// you should implement this function

	//printf("%s \n" , command);
	//	printf("%d" , strlen(command));
	  max_length = get_max_length();
	  i = 0;
      while (command[i] != '\0' && (command[i] == ' ' || command[i] == '\t')){
            i++;
            if (command[i] == '\0' || command[i] == '\n' ) {
                return;
            }
       }
       if(strlen(command) > 512){

		    printf("Command Length Exceeded!");
       }
       else {

            split_line(command);

		}

}
void split_line( const char* command )
{
    index=0;
    words_index = 0;
    while(command[index] != '\0' && command[index] != '\n'){
        temp_index = 0;
        temp = malloc(temp_index + 1);
        boolean = 0;
            while(command[index]!= '\t' && command[index]!= ' ' &&
                   command[index]!= '\n' && command[index] != '\0'){

                temp[temp_index] = command[index];
                temp_index++;
                temp = realloc(temp, temp_index+1);
                boolean = 1;
                    if(command[index+1] != '\n' && command[index+1]  != '\0'){
                        index++;
                    }
                    else {
                        break;
                    }

            }
            if(boolean == 1) {
                 temp[temp_index] = '\0';
                 words[words_index] = malloc(max_length);
                 words[words_index] = temp;
                 printf("%s  %d \n" , words[words_index],words_index);
                 words_index++;
                 free(temp);
            }
             index++;


    }



  }
