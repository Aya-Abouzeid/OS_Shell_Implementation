#include "command.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <stdbool.h>
#include "environment.h"

char* array[]; //for paths
char project_directory[1024];
int done; // acts as a boolean for operation success
void cd(const char* words[], int words_length ,bool background  )
{
	if (words_length == 1 || strcmp(words[1], "~") == 0) {

            done = chdir(getenv("HOME"));
		    getcwd(project_directory, sizeof(project_directory));
		    printf(">>> %s \n",project_directory );

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

//    array = get_path_array();
//	char* temp;
//	temp = malloc(512);
//	words[words_length] = NULL;
//	signal(SIGCHLD, handler);
//	int pid = fork();
//	int i = 0;
//	if (pid == 0) {
//
//		if(execv(ans[0], ans) == -1){
//		while (ans[0][i] != '\0')
//			temp[i] = ans[0][i++];
//		temp[i++] = '\0';
//		i = 0;
//		while (i < PATH_SIZE) {
//		    ans[0] = append(PATH[i] , temp);
//			if (execv(ans[0], ans) != -1)
//				break;
//			i++;
//
//		}
//		if (i == PATH_SIZE) {
//			perror("Error");
//		}
//	}
//		 _exit(0);
//
//	} else {
//		if (background == false) {
//	    	//waitpid(pid, NULL, 0);
//
//		}
//	}




// perror("Error");
}
