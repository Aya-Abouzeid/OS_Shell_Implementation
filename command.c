#include "command.h"
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <stdbool.h>

char project_directory[1024];
int done; // acts as a boolean for operation success
void cd(const char* words, int words_length ,bool background  )
{
printf(">>>>>>>...");
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
       // perror("Error");
	}

	if(done != 0) {
         perror("Error");
	}

}


void echo(const char* words , int words_length ,bool background )
{


// perror("Error");
}

void execute_command(const char* words , int words_length ,bool background ){




// perror("Error");
}
