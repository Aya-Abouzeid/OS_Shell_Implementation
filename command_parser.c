#include "command_parser.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "environment.h"
#include <stdbool.h>
#include "command.h"
#include "file_processing.h"
#include <ctype.h>




int words_index ; //for accessing the array
char *temp; // for reading words.
int index2;   // for looping on command.
char *words[1024];  //for splitting command into array of words
int max_length;
bool line_boolean = false; //for end of lie
int i;
int temp_numbers;
char* variables[513];
char* new_line;
char* variable_temp; //for replacing '$' in command
bool background = false;
void write_history(char* text);
bool variable_found;
bool sign_found;
   char *splitter;
int start_index = 0;
int end_index =0;
void get_history();
char cwd[1024];  //current working directory
int words_length;
char* concat2(char* first, char* second);
char* concat3(char* first, char* second);
void substitute_variable(int temp_index); //for replacing '$' in command
bool used_substitute; //a boolean to indicate that substitute_variable() was used to split words by ' '
char *words2[513]; //for splitting if used_substitute is true
int words2_index;
bool check_equivelance();
bool parse_command( const char* command )
{

      bool x = true;
	  max_length = get_max_length();
	  i = 0;
	  if ( command[0] == '#'){
	  return true;
	  }
      while (command[i] != '\0' && (command[i] == ' ' || command[i] == '\t')){
            i++;
            if (command[i] == '\0' || command[i] == '\n' || command[i] == '#' ) {
                return true;
            }
       }

       write_history(command);
       if(strlen(command) > 512){

		    printf("Command Length Exceeded!");
       }
       else {

            split_line(command);
            is_background();
        printf("5alas el splitting \n");
            x= determine_command();

		}
    return x;
}
void split_line( const char* command )
{



    for (i = 0; i < words_index; i++) {

        free(words[i]);
    }

variable_found = false;
used_substitute = false;
     int index2=0;
     words_index = 0;
     int temp_index = 0;
bool new_word = false;
bool sign_found = false;
     words[words_index] = malloc(513);
     memset(words[words_index] , 0 ,sizeof(words[words_index]));
while (command[index2] == ' ' || command[index2] == '\t'){
                            index2++;
                        }
    while(command[index2] != '\0' && command[index2] != '\n'){



  if(command[index2] == '"' && new_word==false) {
            new_word = true;
        printf("Iteration111 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

			index2++;
			bool done = false;
			while(command[index2] != '\0' && done ==false){
			if(command[index2] != '"'){
					words[words_index][temp_index] = command[index2];
					                                										temp_index++;


					}
                    printf("Iteration222 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

					if(command[index2] == '"')
						done =  true;

					if( command[index2] == '$'){

                            variable_found = true;

                                }
                                if( command[index2] == '~'){

                            sign_found = true;

                                }

                                index2++;

}
if(done == false){
memcpy(words[0] , "notacommand",sizeof(words[0]));
    memset(words[words_index] , 0 ,sizeof(words[words_index]));
    new_word = false;
                                variable_found = false;
                                sign_found = false;
                                                            temp_index = 0;


                    printf("Iteration333 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

} else {
                    printf("IterationANAHENA %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            words[words_index][temp_index] = '\0';

                    printf("IterationANAHENAba3delta3deel %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            new_word = false;
                            if(variable_found == true){
                            substitute_variable(temp_index);
                            used_substitute = true;
                                                        }
                                                        if(sign_found == true){
                            substitute_sign(temp_index);
                                                        }
                                    printf("Iterationteeeeeeeest %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            words_index++;
                            sign_found = false;
                            temp_index = 0;
                            words[words_index] = malloc(513);
                                 memset(words[words_index] , 0 ,sizeof(words[words_index]));

                            }

                            }     else if(command[index2]!= '\t' && command[index2]!= ' ' && command[index2] != '\0' ) {
            new_word = true;
                    printf("Iteration444 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);


                                if( command[index2] == '$'){

                            variable_found = true;


                                }
                                if( command[index2] == '~'){

                            sign_found = true;

                                }
                                if(command[index2] == '"'){
                                bool done = true;
                                			while(command[index2] != '\0' && done ==true){
                                			                    printf("Iteration555 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

					words[words_index][temp_index] = command[index2];
					                                										temp_index++;

					if(command[index2+1] == '\0' && command[index2] != '"')
						done =  false;

					if( command[index2] == '$'){

                            variable_found = true;

                                }
                                if( command[index2] == '~'){

                            sign_found = true;

                                }

                                index2++;

}
if(done == false){
                    printf("Iteration666 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

memcpy(words[0] , "notacommand",sizeof(words[0]));
    memset(words[words_index] , 0 ,sizeof(words[words_index]));
    new_word = false;
                                variable_found = false;
                                sign_found = false;
                                                            temp_index = 0;



} else {
                    printf("Iteration777 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            words[words_index][temp_index] = '\0';

                            new_word = false;
                            if(variable_found == true){
                            substitute_variable(temp_index);
                                                        used_substitute = true;

                                                        }
                                                         if(sign_found == true){
                            substitute_sign(temp_index);

                                                        }
                                                        sign_found = false;
                            words_index++;
                            variable_found = false;
                            temp_index = 0;
                            words[words_index] = malloc(513);
                                 memset(words[words_index] , 0 ,sizeof(words[words_index]));
                            }


} else {
                    printf("Iteration888 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                                 words[words_index][temp_index] = command[index2];
                                 temp_index++;
                                 if(command[index2+1] == '\0'){
                                               words[words_index][temp_index]  = '\0';
                            new_word = false;
                            if(variable_found == true) {
                            substitute_variable(temp_index);
                                                        used_substitute = true;

                            }
                             if(sign_found == true) {
                            substitute_sign(temp_index);
                            }
                            sign_found = false;
                            words_index++;
                                                        variable_found = false;

                                 }
                                                                  index2++;

                                 }
            }   else {
        printf("Iteration999 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                        while (command[index2] == ' ' || command[index2] == '\t'){
                            index2++;
                            new_word = false;
                        }
                        if(command[index2]  != '\0'){
                                            printf("Iteration123123 %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            words[words_index][temp_index] = '\0';
                            new_word = false;
                            if(variable_found == true){
                            substitute_variable(temp_index);
                                                        used_substitute = true;

                                                        }
                                                        if(sign_found == true){
                            substitute_sign(temp_index);
                                                        }
                                                        sign_found = false;
                            words_index++;
                            variable_found = false;
                            temp_index = 0;
                            words[words_index] = malloc(513);
                                 memset(words[words_index] , 0 ,sizeof(words[words_index]));

                        }
                        if (new_word == true && command[index2]  == '\0') {
                                            printf("Iteration %d ... Word>>>%s<<<\n" , index2 , words[words_index]);

                            words[words_index][temp_index]  = '\0';
                            new_word = false;
                            if(variable_found == true) {
                            substitute_variable(temp_index);
                                                        used_substitute = true;

                            }
                            if(sign_found == true) {
                            substitute_sign(temp_index);
                            }
                            sign_found = false;
                            words_index++;
                                                        variable_found = false;

                        }
            }
    }
printf("WASALT HENAA \n");
    if(variable_found == true) {
                            substitute_variable(temp_index);
                                                        used_substitute = true;

                            }
                             if(sign_found == true) {
                            substitute_sign(temp_index);
                            }

    words_length = words_index;
printf("WASALT HENAA2 %d \n" , words_index);


}

void substitute_sign(int temp_index){

char *new_line;
new_line = malloc(513);
memset(new_line,0,sizeof(new_line));


if(strcmp(words[words_index] , "~") == 0){
strcpy(words[words_index]  , lookup_variable("HOME"));
return;


}
                      if( words[words_index][0] == '~' && words[words_index][1] == '/'){
                               memmove(words[words_index], words[words_index]+1, strlen(words[words_index]));

                        new_line = concat3("/home/aya" , words[words_index]);

                }
                else {
                         memmove(words[words_index], words[words_index]+1, strlen(words[words_index]));

                new_line = concat3("/home/" , words[words_index]);
                }



        new_line[strlen(new_line)]='\0';


strcpy(words[words_index]  , new_line);
}
void substitute_variable(int temp_index){

printf("heere\n");

int i=0;
bool found = false;
variables[513] ;
new_line = malloc(513);
memset(new_line,0,sizeof(new_line));

int new_line_iter = 0;
temp_numbers =0;
int iter= 0;
        for(i ; i<= temp_index;i++){
                if( words[words_index][i] == '$'){
                        if(found ==false){

                        variables[temp_numbers]= malloc(513);
                        memset(variables[temp_numbers] , 0 ,sizeof(variables[temp_numbers]));
                        iter =0;
                        found = true;
                        start_index = i +1 ;

                        }
                        else {

                        end_index = i;
                        found = false;

                        if( strcmp(lookup_variable(variables[temp_numbers]) ,"") ==0 ){

                            }else{

                                new_line = concat3(new_line, lookup_variable(variables[temp_numbers]));
                                new_line_iter = new_line_iter + strlen(lookup_variable(variables[temp_numbers]));



                                }

                                temp_numbers++;
                                variables[temp_numbers]= malloc(513);
                                memset(variables[temp_numbers] , 0 ,sizeof(variables[temp_numbers]));
                                iter =0;

                        found = true;
                        start_index = i +1 ;
                        }

                }
                else if(words[words_index][i] == '\0' ){

                end_index = i;
lookup_variable(variables[temp_numbers]);
            if(found == true){
                        if( strcmp(lookup_variable(variables[temp_numbers]) ,"") ==0 ){

                new_line = concat3(new_line, variables[temp_numbers]);
                                new_line_iter = new_line_iter + strlen(variables[temp_numbers]);
                            }else{

                                new_line = concat3(new_line, lookup_variable(variables[temp_numbers]));
                                new_line_iter = new_line_iter + strlen(lookup_variable(variables[temp_numbers]));

                                }
                                }
                                variables[temp_numbers][iter] = words[words_index][i];

                        new_line[new_line_iter] = words[words_index][i];
                        new_line_iter++;
                        iter++;
                                                        temp_numbers++;
                                                        iter =0;


                        }
                        else if (found == true && words[words_index][i] != '\0' && words[words_index][i] != '/' ) {

                                 variables[temp_numbers][iter] = words[words_index][i];

                                 iter++;
                        }
                        else {

if(found == true && words[words_index][i]== '/' ){
                        end_index = i;
                        found = false;

                        if( strcmp(lookup_variable(variables[temp_numbers]) ,"") ==0 ){

                            }else{

                                new_line = concat3(new_line, lookup_variable(variables[temp_numbers]));
                                new_line_iter = new_line_iter + strlen(lookup_variable(variables[temp_numbers]));


                                } }

                        new_line[new_line_iter] = words[words_index][i];
                                new_line_iter++;

                        }

        }
        new_line[new_line_iter]='\0';


strcpy(words[words_index]  , new_line);

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

char* concat3(char* first, char* second) {

	char* concatenated = malloc(strlen(first) + strlen(second) );
	memset(concatenated , 0 , sizeof(concatenated));
	int index =0;
	int i = 0;

	for (index ; first[index] != '\0'; index++){
		concatenated[i++] = first[index];
		}
		index =0;

	for (index; second[index] != '\0'; index++) {
		concatenated[i++] = second[index];
	}
	concatenated[i] = '\0';
	return concatenated;
}

char* concat2(char* first, char* second) {

	char* concatenated = malloc(strlen(first) + strlen(second) - 1);
		memset(concatenated , 0 , sizeof(concatenated));

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
   printf("73ml free \n");

bool x = true;
    if(strcmp(words[0] ,"cd") == 0){
        cd( words,words_length, background );
    }
    else if(strcmp(words[0] ,"echo") == 0){
        echo( words ,words_length, background );

    }
    else if(strcmp(words[0] ,"printenv") == 0){
        printenv();

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
   printf("da5alt f else \n");

   if(check_equivelance() == false) {
       printf("3mlt check equivelance\n");

   if(used_substitute){
          printf("d5alt f if\n");

        int i=0;
        char s[2] = " ";
   words2_index=0;
      printf("ba- split \n");

        for(i ; i<words_length ; i++){

        splitter = strtok(words[i], s);

   while( splitter != NULL ) {   //splitting by '/'
     words2[words2_index] = malloc(513);
     memset(words2[words2_index] , 0 ,sizeof(words2[words2_index]));
words2[words2_index] = splitter;
      splitter = strtok(NULL, s);
      words2_index++;
      }


        }
   printf("7a-execute words2\n");

           execute_command(words2 ,words2_index, background );

   }else{
   printf("7a-execute words1\n");
           execute_command(words ,words_length, background);

   }

        }
    }
return x;
}


bool check_equivelance(){


if(words_length == 1) {
char s[2] = "=";
   char *splitter;
   char *splitted[2];
   int iterator=0;
   char* temp = malloc(513);
memcpy(temp , words[0] , 513);

   splitter = strtok(temp, s);

   while( splitter != NULL ) {   //splitting by '/'
splitted[iterator] = splitter;
      splitter = strtok(NULL, s);
      iterator++;
      }
      if( (iterator == 1 && words[0][0] == '=') || (iterator == 1 && words[0][strlen(words[0])-1]!= '=')){
    return false;
}

int x = splitted[0][0];
int z =isalpha(x);

if (z == 0){  //arguments key is a digit
return false;
     }

char* quoted_string = malloc(513);
memset(quoted_string , 0 ,sizeof(quoted_string));

     if(splitted[1][0] =='"' && splitted[1][strlen(splitted[1])-1] == '"'){
            quoted_string = remove_quotes(splitted[1]);

            set_variable(splitted[0] , quoted_string);
      }


               else if(strlen(splitted[0]) != 0  && words[0][strlen(words[0])-1]== '=' ){

                set_variable(splitted[0] , "");

                }
                else if( strlen(splitted[0]) != 0  && strcmp(splitted[0] , words[0]) == 0  ){

                set_variable(splitted[0] , "");
                }
                else if( strlen(splitted[0]) != 0 && strlen(splitted[1]) != 0 ){
                set_variable(splitted[0] , splitted[1] );

                }else {
                    printf("Error: Command not found");
                    return;
                }





      }
      else{
      return false;
    }
    return true;

}
void write_history(char* text){

 char* h= concat2(getcwd(cwd, sizeof(cwd)) , "MyHistory");

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
		char* h= concat2(getcwd(cwd, sizeof(cwd)) , "MyHistory");
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



