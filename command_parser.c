#include "command_parser.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "environment.h"
<<<<<<< HEAD
=======
#include <stdbool.h>
#include "command.h"
#include "file_processing.h"


>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

char *words[]; // array for words in commands
int words_index; //for accessing the array
char *temp; // for reading words.
int temp_index;
<<<<<<< HEAD
int index; // for looping on command.
int max_length;
int boolean;
int i;
void parse_command( const char* command )
{
	// you should implement this function

	//printf("%s \n" , command);
	//	printf("%d" , strlen(command));
=======
int index2;   // for looping on command.
int max_length;
bool line_boolean = false; //for end of lie
int i;
bool background = false;
void write_history(char* text);
void get_history();
int words_length;
char* concat2(char* first, char* second);
bool parse_command( const char* command )
{
	// you should implement this function
bool x = true;
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
	  max_length = get_max_length();
	  i = 0;
      while (command[i] != '\0' && (command[i] == ' ' || command[i] == '\t')){
            i++;
            if (command[i] == '\0' || command[i] == '\n' ) {
                return;
            }
       }
<<<<<<< HEAD
=======

       write_history(command);
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
       if(strlen(command) > 512){

		    printf("Command Length Exceeded!");
       }
       else {

            split_line(command);
<<<<<<< HEAD

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
=======
            is_background();
           x= determine_command();

		}
return x;
}
void split_line( const char* command )
{

    int index2=0;
    int words_index = 0;
            temp_index = 0;
        words[words_index] = malloc(513);

    while(command[index2] != '\0' && command[index2] != '\n'){

            if(command[index2]!= '\t' && command[index2]!= ' ' && command[index2] != '\0'){

                                 words[words_index][temp_index] = command[index2];
                                   //      printf(">>%s \n",words[words_index]);

                                 temp_index++;
                                 index2++;

            }
            else {
                while (command[index2] == ' ' || command[index2] == '\t'){

                            index2++;

                            }
                            if(command[index2]  != '\0'){
                      words_index++;
                              temp_index = 0;
                        words[words_index] = malloc(513);
                }


                if (command[index2]  == '\0') {
                    words[words_index][temp_index]  = '\0';
                }
            }

    }
    words_length = words_index+ 1;
}


void is_background(){
background = false;
 if( words_length == 1 && words[words_length-1][strlen(words[words_length-1])-1] == '&'){
		background = true;
		words[words_length-1][strlen(words[words_length-1])-1]= '\0';

	}
	if (words_length > 1 && strcmp(words[words_length - 1], "&") == 0) {
		background = true;
		words_length--;
	}else if( words_length > 1 && words[words_length-1][strlen(words[words_length-1])-1] == '&'){
		background = true;
		words[words_length-1][strlen(words[words_length-1])-1]= '\0';

	}

}


char* concat2(char* first, char* second) {
	char* concatenated = malloc(strlen(first) + strlen(second) - 1);
	int index =0;
	int i = 0;

	for (index ; first[index] != '\0'; index++){
		concatenated[i++] = first[index];
		}
		concatenated[i++] = '/';
		index =0;
	for (index; second[index] != '\0'; index++) {
		concatenated[i++] = second[index];
	}
	concatenated[i] = '\0';
	return concatenated;
}

bool determine_command(){
bool x = true;
    if(strcmp(words[0] ,"cd") == 0){
        cd( words,words_length, background );
    }
    else if(strcmp(words[0] ,"echo") == 0){
        echo( words ,words_length, background );

    }
    else if(strcmp(words[0] ,"export") == 0){
        exp( words ,words_length, background );

    }
    else if(strcmp(words[0] ,"exit") == 0){
x = false;
    }
    else if(words_length == 1 && strcmp(words[0] ,"history") == 0){

get_history();
    }
    else {
        execute_command(words ,words_length, background , concat2(getenv("HOME"), "MyLog"));
    }
return x;
}

void write_history(char* text){

 char* h= concat2(getenv("HOME"), "MyHistory");

FILE *history = fopen(h, "a");
    if(history!=NULL)
    {
        fprintf(history, "%s \n", text);
        fclose(history);
    }
    else
    {
        printf("%s\n", " ERROR : cann't open history file");
    }

}
void get_history()
{
    char command[513];
		char* h= concat2(getenv("HOME"), "MyHistory");
		    FILE* history = fopen(h, "r");

if (history == NULL)
        printf("%s\n", "No History");
    else
    {
        while (fgets(command, 513, history))
            printf("%s", command);
        fclose(history);
    }

}
char *get_words(){
    return words;
}
int get_words_index(){
    return words_length;
}
bool get_background_bool(){
    return background;
}



>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40
