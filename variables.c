#include "variables.h"
#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

char *cd_paths[]; //for the visited paths
char *variable_name[512]; //for shell variables
char *variable_value[512]; // value of shell variable
int iterator = 0;
int max = 512;
char *buffer;  //buffer for 1024 characters
char* parent_path[]; // parent path for the current path
extern char **environ;

const char* lookup_variable( const char* key )
{
    int i=0;
	for(i; i<iterator; i++){

        char *temp = malloc(max);

        if(strcmp(variable_name[i] , key) == 0 ){
                return variable_value[i];
        }

	}

	if(getenv(key) != NULL)
	return getenv(key);


	return "";

}

char* get_parent_path(){


   char cwd[1024];
getcwd(cwd, sizeof(cwd));
int i=0;
char *splitter;
 char s[2] = "/";
   splitter = strtok(cwd, s);
   while( splitter != NULL ) {   //splitting by '/'
   parent_path[i] = malloc(513);
parent_path[i] = splitter;
      splitter = strtok(NULL, s);
      i++;
      }

char* temp = malloc( 1024 );
                                strcpy(temp,"/");
                                int k=0;
                                while(k < i-1){
                                strcat(temp,parent_path[k]);
                                strcat(temp,"/");
                                k++;
                                }

return temp;

}

void printenv(){

int i=1;
if(strcmp(lookup_variable("PATH") , getenv("PATH")) != 0 ){
printf("Error: command not found");
}
else{
int i = 0;
while(environ[i]) {
  printf("%s\n", environ[i++]); // prints in form of "variable=value"
}

}


}
void set_variable( const char* key , const char* value ){

int k=0;
bool found =false;
int j;
for(j=0 ; j<iterator ; j++){

if(strcmp(variable_name[j] , key) == 0)
{
found = true;
break;
}


}
 if(found == false){


                variable_name[iterator] = malloc(max);
                variable_value[iterator] = malloc(max);

          strcpy(      variable_name[iterator],  key);
              strcpy(  variable_value[iterator] , value);

                iterator++;

}
else {
memset( variable_value[j] , 0 , sizeof(variable_value[j]));
strcpy( variable_value[j]  , value);

}

}
void print_all_variables( void )
{
    int i=0;
	for(i; i<iterator; i++){
        printf("%s > %s \n" , variable_name[i] ,  variable_value[i]);
	}
}



