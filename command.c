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


//char* array[]; //for paths
char project_directory[1024];
int done; // acts as a boolean for operation success
char *path_array[]; // array for splitted path
int index2; // for looping on path.
int sentense_index; //for accessing the array
int temp_index;
char *temp; // for reading words.
bool path_boolean = false; //for end of lie
int max_length = 512;
int iter;
char* logPath;
  char* words2[];
void concat(char* second);
void signal_log();
void cd(const char* words[], int words_length ,bool background  )
{
	if (words_length == 1 || strcmp(words[1], "~") == 0) {

            done = chdir(getenv("HOME"));
//            getcwd(project_directory, sizeof(project_directory));
//		    printf(">>> %s \n",project_directory );


	} else if(words_length == 2 ){
            done = chdir(words[1]);
//            getcwd(project_directory, sizeof(project_directory));
//		    printf(">>> %s \n",project_directory );
	}
	else {
printf("ERROR: Directory Not Found");
	}

	if(done != 0) {
printf("ERROR: Directory Not Found");
	}

}

void exp(const char* words[], int words_length ,bool background  ){

int length;
if(words_length == 2) {

int i;
bool found = false;
bool error = false;

char* temp = malloc(513);
memcpy(temp , words[1] , 513);
 const char s[2] = "=";
   char *token;

   /* get the first token */
   token = strtok(temp, s);

   /* walk through other tokens */int q =0;
   char* arr[2];
   while( token != NULL ) {
 arr[q] = token;
      q++;
      token = strtok(NULL, s);

      }

                if(strlen(arr[0]) != 0  && words[1][strlen(words[1])-1]== '=' ){
                set_variable(arr[0] , "");
                }
                else if(strlen(arr[0]) != 0  && strcmp(arr[0] , words[1]) == 0 ){


                set_variable(arr[0] , "");
                }
                else if(strlen(arr[0]) != 0 && strlen(arr[1]) != 0  ){

                set_variable(arr[0] , arr[1] );
                }else {

                    perror("error");
                    return;
                }




}
else {
                    printf("Error: Command not found");

    }
}


void echo(const char* words[] , int words_length ,bool background )
{

    if(words_length == 1) {
                printf("\n");

    }
    else if( words_length == 2 && words[1][0] == '&'){

                    printf("Error: Command not found");
    }
    else if(words_length == 2 && words[1][0] == '$'){

        char* var =   memmove(words[1], words[1]+1, strlen(words[1]));
    char* j =lookup_variable(var);
//    printf("%s \n" , j);
            if(strcmp(j,"") != 0 ){

                     printf("%s" , j);
            }
            else {
                    printf("\n");


            }
    }
    else if( words_length == 2 && words[1][0] != '$'){

                    printf("%s" , words[1]);
    }
    else{
       int i=1;
        for(i ; i< words_length ;i++){
             printf("%s " , words[i]);
        }

    }

}

void execute_command(const char* words[] , int words_length ,bool background ,char* fileName ){
        char* x = words[0];
    char* array = words;
    logPath = fileName;
split_path();
  int k;
char* z[iter];
for(k=0 ; k<iter; k++){
 z[k] = malloc(strlen(path_array[k]) + strlen(x) );
                                strcpy(z[k],path_array[k]);
                                strcat(z[k],x);


}



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
                       printf("%s" , z[i]);
                        done = true;
                                        break;

                                        }


i++;
}

                if (done == false){
        printf("ERROR: Invalid Command.");
                }

                exit(0);
        }else if(pid>0)
            {
                if (background == false) {
                    waitpid(pid, &status ,0);
}
            }

        else {

perror("error");
return;
        }


}

void signal_log(){


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

char* path =  getenv("PATH");

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
//int k;
//  for( k=0 ; k< iter ; k++){
//  					printf("%s \n" , path_array[k]);
//
//  }
char* concatenated;


	//concatenated= malloc(strlen(first) + strlen(second) - 1);


	int i = 0;
while(i< iter){
int index =0;
		int index2 =0;
		printf(">>>>>> %d \n" , i);

				printf(" >> %s concat \n" , path_array[i]);

	for (index ; path_array[i][index] != '\0'; index++){

		}

	for (index2; second[index2] != '\0'; index2++) {
		path_array[i][index] = second[index2];
		index++;

	}
	path_array[index] = '\0';
		printf("%s <<<<<<<<<<<<< concat \n" , path_array[i]);

	i++;
	}
	//printf("%s <<< concat \n" , concatenated[y]);


}
