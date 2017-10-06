#include "variables.h"
#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

char *cd_paths[]; //for the visited paths
char *variable_name[]; //for shell variables
char *variable_value[]; // value of shell variable
int iterator = 0;
int max = 512;
char *buffer;  //buffer for 1024 characters

const char* lookup_variable( const char* key )
{
    int i=0;
	for(i; i<iterator; i++){


        if(strcmp(variable_name[i] , key) == 0 ){
                return variable_value[i];
        }

	}

	return "";

}

void set_variable( const char* key , const char* value ){

//printf("nooooooooooooow3 \n");
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

                variable_name[iterator] = key;

                variable_value[iterator] = value;

                iterator++;

}
else {
variable_value[j] = value;

}
}
void print_all_variables( void )
{
    int i=0;
	for(i; i<iterator; i++){
        printf("%s > %s \n" , variable_name[i] ,  variable_value[i]);
	}
}



