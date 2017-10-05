#include "command_parser.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "environment.h"
#include <stdbool.h>
#include "command.h"
#include "file_processing.h"



char *words[]; // array for words in commands
int words_index; //for accessing the array
char *temp; // for reading words.
int temp_index;
int index2;   // for looping on command.
int max_length;
bool line_boolean = false; //for end of lie
int i;
bool background = false;
void write_history(char* text);
void get_history();
char* concat2(char* first, char* second);
void parse_command( const char* command )
{
	// you should implement this function

	  max_length = get_max_length();
	  i = 0;
      while (command[i] != '\0' && (command[i] == ' ' || command[i] == '\t')){
            i++;
            if (command[i] == '\0' || command[i] == '\n' ) {
                return;
            }
       }

       write_history(command);
       if(strlen(command) > 512){

		    printf("Command Length Exceeded!");
       }
       else {

            split_line(command);
            is_background();
            determine_command();

		}

}
void split_line( const char* command )
{

    index2=0;
    words_index = 0;
    while(command[index2] != '\0' && command[index2] != '\n'){
        temp_index = 0;
        words[words_index] = malloc(temp_index +1);

            while(command[index2]!= '\t' && command[index2]!= ' ' && command[index2] != '\0'){
                                 words[words_index][temp_index] = command[index2];
                                 temp_index++;
                                 words[words_index] = realloc(words[words_index], temp_index+1);

                     if(command[index2+1]  == ' ' || command[index2+1] == '\t'){

                                  words[words_index][temp_index]  = '\0';
                                  words_index++;
                                  temp_index++;
                                  index2++;
                    }
                     else if(command[index2+1]  != '\0'){

                                  index2++;
                    }
                    else {
                                 words[words_index][temp_index]  = '\0';
                                 words_index++;
                                 temp_index++;
                                 break;
                    }
            }
             index2++;
} }


void is_background(){
	if (words_index > 1 && strcmp(words[words_index - 1], "&") == 0) {
		background = true;
		words_index--;
	}else if( words_index > 1 && words[words_index-1][strlen(words[words_index-1])-1] == '&'){
		background = true;
		words[words_index-1][strlen(words[words_index-1])-1]= '\0';

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
	//printf("%s <<< concat \n" , concatenated);
	return concatenated;
}

void determine_command(){

    if(strcmp(words[0] ,"cd") == 0){
        cd( words,words_index, background );
    }
    else if(strcmp(words[0] ,"echo") == 0){
        echo( words ,words_index, background );

    }
    else if(words_index == 1 && strcmp(words[0] ,"history") == 0){

get_history();
    }
    else {
        execute_command(words ,words_index, background );
    }



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
//FILE* history = fopen(h, "r");
//	char text[513];
//	if (history == NULL) {
//		printf("No History\n");
//	}else {
//	while (fgets(text, 513, history) != NULL) {
//		printf("%s \n ", text);
//	}
//fclose(history);
//}
}
char *get_words(){
    return words;
}
int get_words_index(){
    return words_index;
}
bool get_background_bool(){
    return background;
}



