#include "command.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <stdbool.h>
#include "environment.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "variables.h"
#include <ctype.h>


int done; // acts as a boolean for operation success
char *path_array[]; // array for splitted path
int index2; // for looping on path.
int temp_index;
char *temp; // for reading words.
bool path_boolean = false; //for end of line
int max_length = 512;
char cwd2[1024];  //current working directory
int iter;
char* logPath;
void concat(char* second);
void signal_log();
bool same_user; //for checking ~username command
bool compare_user(const char* words[]);
char *remove_quotes(char *string);
void cd(const char* words[], int words_length ,bool background  ) //change directory function
{
    done =0;

	if (words_length == 1  || (strcmp(words[1], "~")) == 0) {

            done = chdir(lookup_variable("HOME"));


	}else if( words_length >= 2 && (strcmp(words[1], ".")) ==0 ){

       }
       else if( words_length >= 2 && (strcmp(words[1], "..")) ==0 ){
            done = chdir(get_parent_path());
       }
       else if( words_length == 2 && words[1][0] == '$' ){
            char* temp;
            char s[2] = "$";
             char* temp3 = malloc(513);
             temp3 = memcpy(temp3 , words[1], 513);
               char *splitter;
               splitter = strtok(temp3, s);
               while( splitter != NULL ) {   //splitting by '$'
            temp = splitter;
                  splitter = strtok(NULL, s);
                  }

            if(strcmp(lookup_variable( temp) ," " ) != 0){

                               done = chdir(lookup_variable( temp) );

                   }
                   else {
                   done =1;
                   }

       }

	else if( words_length >= 2 && words[1][0]=='~' && words[1][0]=='/'){


memmove(words[1], words[1]+1, strlen(words[1]));
                   done = chdir(concat2( "/home",   memmove(words[1], words[1]+1, strlen(words[1]))));


	}
	else if(words_length >= 2 ){

            done = chdir(words[1]);

	}
	else {

printf("ERROR: directory not found\n");
	}

	if(done != 0) {
printf("ERROR: directory not found\n");
	}

}
bool compare_user(const char* words[]){

char* temp1 = malloc(513) ;
 char* temp3 = malloc(513);
 temp3 = memcpy(temp3 , getenv("HOME"), 513);

 char s[2] = "/";

   char *splitter;
   splitter = strtok(temp3, s);
   while( splitter != NULL ) {   //splitting by '/'
temp1 = splitter;
      splitter = strtok(NULL, s);
      }

char* temp2 = malloc( 513 );
                                strcpy(temp2,"~");
                                strcat(temp2,temp1);
free(temp3);


      if(strcmp(words[1] ,temp2) ==0){

         return true;
      }

      return false;

}

void exp(const char* words[], int words_length ,bool background  ){  //for executing export command

if(words_length == 2) {


bool error = true;

char* quoted_string = malloc(513);
memset(quoted_string , 0 ,sizeof(quoted_string));
char* temp = malloc(513);
memcpy(temp , words[1] , 513);

int x = temp[0];
int z =isalpha(x);

if (z != 0){  //arguments key is a digit
error = false;
     }

 const char s[2] = "=";
   char *splitter;
   splitter = strtok(temp, s);
int q =0;
   char* arr[2];
   if(error == false){
   while( splitter != NULL ) {   //splitting by '='
 arr[q] = splitter;
      q++;
      splitter = strtok(NULL, s);

      }
      }

      if(arr[1][0] =='"' && arr[1][strlen(arr[1])-1] == '"'){
            quoted_string = remove_quotes(arr[1]);

            set_variable(arr[0] , quoted_string);
      }


               else if(error == false && strlen(arr[0]) != 0  && words[1][strlen(words[1])-1]== '=' ){

                set_variable(arr[0] , "");

                }
                else if(error == false && strlen(arr[0]) != 0  && strcmp(arr[0] , words[1]) == 0  ){

                set_variable(arr[0] , "");
                }
                else if(error == false && strlen(arr[0]) != 0 && strlen(arr[1]) != 0 ){
                set_variable(arr[0] , arr[1] );

                }else {
                    printf("Error: Command not found");
                    return;
                }




}
else {
                    printf("Error: Command not found");

    }


}


char *remove_quotes(char *string){
    char *text;
 const char s[2] = "\"";
   char *splitter;
   splitter = strtok(string, s);
   while( splitter != NULL ) {   //splitting by '='
 text = splitter;
      splitter = strtok(NULL, s);

      }
return text;

}
void echo(const char* words[] , int words_length ,bool background ) //executing echo command
{

    if(words_length == 1) {
                printf("\n");

    }
    else if( words_length >= 2 && words[1][0] == '&'){

                    printf("Error: Command not found\n");
    }
    else if(words_length == 2 && words[1][0] == '$'){

         memmove(words[1], words[1]+1, strlen(words[1]));
        char* j =lookup_variable(words[1]);
            if(strcmp(j,"") != 0 ){

                     printf("%s\n" , j);
            }
            else {
                    printf("\n");


            }
    }

    else if( words_length == 2 && words[1][0] != '$'){

                    printf("%s\n" , words[1]);
    }
    else{
       int i=1;
        for(i ; i< words_length ;i++){
             printf("%s\n " , words[i]);
        }

    }

}

void execute_command(const char* words[] , int words_length ,bool background ){

        char* x =malloc(513) ;
//= words[0];
memset(x , 0 , sizeof(x));
        strcpy(x, words[0]);

split_path();

  int k;
char* z[iter];
printf("heeeeeeeeeeeeeeeere\n");

for(k=0 ; k<iter; k++){

 z[k] = malloc(strlen(path_array[k]) + strlen(x) +1);
                                strcpy(z[k],path_array[k]);
                                strcat(z[k],x);

}printf("heeeeeeeeeeeeeeeere2\n");



	words[words_length] = NULL;

	int i = 0;
	bool done = false;
	char* command;
    signal(SIGCHLD,signal_log);
    int status;
    siginfo_t childstat;
    pid_t pid = fork();

        if (pid == 0) {

                while(i <iter){

                        if(execv(x, words) != -1){
                                    done = true;

                                        break;

                        }
                       else if (execv(z[i], words) != -1) {
                        done = true;
                                        break;

                                        }

                                      else
                                      if(execve(x, words,NULL) != -1){
        done = true;
                                        break;

        }
      else if(execve(z[i], words,NULL) != -1){
        done = true;

                                        break;

        }


i++;
}

                if (done == false){
        printf("ERROR: Invalid Command.\n");
                }

                exit(0);
        }else if(pid>0)
            {
                if (background == false) {
//int status;
//while( !WIFEXITED(status) && !WIFSIGNALED(status) ){
//    waitpid(pid, &status, WUNTRACED);
//
//}
waitpid(pid,status,0);

}
            }

        else {

perror("error");
return;
        }
        int m;
         for (m = 0; m < iter; m++) {
        free(z[m]);
    }
 for (m = 0; m < iter; m++) {
        free(path_array[m]);
    }

}

void signal_log(){

logPath = concat2(getcwd(cwd2, sizeof(cwd2)) , "MyLog");

FILE *log = fopen(logPath, "a");
    if(log!=NULL)
    {
        fprintf(log, "Child process was terminated \n");
        fclose(log);
    }
    else
    {
        printf("%s\n", " ERROR : cann't open log file");
    }

}
void split_path(){

char* path =  lookup_variable("PATH");

        int size =0;
    int index2=0;
            path_array[0] = malloc(513);

int j;

for (j = 0; path[j] != '\0'; j++) {
		if (path[j] != ':') {

            path_array[size][index2] = path[j];
			index2++;

		} else {

            path_array[size][index2]='/';
            index2++;
			path_array[size][index2] = '\0';
			size++;

			path_array[size] = malloc(513);

			index2 = 0;
		}

	}
	            path_array[size][index2]='/';

	size++;
	iter = size;


}
void concat(  char* second) {

	int i = 0;
while(i< iter){
int index =0;
		int index2 =0;


	for (index ; path_array[i][index] != '\0'; index++){

		}

	for (index2; second[index2] != '\0'; index2++) {
		path_array[i][index] = second[index2];
		index++;

	}
	path_array[index] = '\0';

	i++;
	}


}
