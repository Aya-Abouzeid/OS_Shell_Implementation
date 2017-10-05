#include "command.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <stdbool.h>
#include "environment.h"
#include <signal.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>


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

char* concat(char* first, char* second);
void cd(const char* words[], int words_length ,bool background  )
{
	if (words_length == 1 || strcmp(words[1], "~") == 0) {

            done = chdir(getenv("HOME"));


	} else if(words_length == 2 ){
            done = chdir(words[1]);
            getcwd(project_directory, sizeof(project_directory));
		    printf(">>> %s \n",project_directory );
	}
	else {
            perror("Error");
	}

	if(done != 0) {
            perror("Error");
	}

}


void echo(const char* words[] , int words_length ,bool background )
{


    if(words_length == 1) {
                printf("\n");

    }
    else if(words_length == 2 && words[1][0] == '&'){

        char* var =   memmove(words[1], words[1]+1, strlen(words[1]));


            if(strcmp(lookup_variable(var),"") != 0 ){

                     printf("%s" , lookup_variable(words));
            }
            else {
                     printf("\n");

                     perror("Error");

            }
    }
    else if( words_length == 2 && words[1][0] != '&'){
                    printf("%s" , words[1]);
    }
    else{
       int i=1;
        for(i ; i< words_length ;i++){
             printf("%s " , words[i]);
        }

    }

}

void execute_command(const char* words[] , int words_length ,bool background ){
        char* x = words[0];
    char* array = words;
split_path();
//printf(">>>>>> %s \n" , path_array[0]);
//printf(">>>>>> %s \n" , path_array[1]);
//printf(">>>>>> %s \n" , path_array[2]);
//printf(">>>>>> %s \n" , path_array[3]);
//printf(">>>>>> %s \n" , path_array[4]);
//printf(">>>>>> %s \n" , path_array[5]);
//printf(">>>>>> %s \n" , path_array[6]);
//printf(">>>>>> %s \n" , path_array[7]);
//printf(">>>>>> %s \n" , path_array[8]);


	char* temp;
	temp = malloc(512);
	words[words_length] = NULL;
	int i = 0;
	bool done = false;
	char* command;
    int status;
    int required = -1;
    siginfo_t childstat;
    pid_t pid = fork();

        if (pid == 0) {

                while(i <iter){

                       command = concat(path_array[i] , x);

FILE *file;
    file = fopen(command, "r");
    if (file != NULL) {
        required = i;
    }
    i++;
                                                printf(" i = %d \n" , i);
                                            printf("iter = %d \n" , iter);

}
                                            printf("%d \n" , required);

//                            if ( required > -1){
//                            execv(command, array);
//                            printf("heeeeeere");
//
//                                }
//
//               else if (done == false){
//
//                perror("error");
//                }
//                                                            printf("heeeeeere222");
//
//                exit(0);
        }else if(pid>0)
            {

                    waitid(P_PID,pid, &childstat ,WEXITED);

        printf("%d \n" , pid);

            }

        else {

perror("error");
return;
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
	size++;
	iter = size;

}
char* concat(char* first, char* second) {
	char* concatenated = malloc(strlen(first) + strlen(second) - 1);
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
	//printf("%s <<< concat \n" , concatenated);
	return concatenated;
}
