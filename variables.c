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

void set_variable( const char* key , const char* value )
{

       if(iterator ==0 ){
               variable_name[iterator] = malloc(max);
               variable_value[iterator] = malloc(max);

       }
       else {

                variable_name[iterator] = realloc(variable_name[iterator], max);
                variable_value[iterator] = realloc(variable_value[iterator], max);
             }
                variable_name[iterator] = key;

                variable_value[iterator] = value;

                iterator++;



}

void print_all_variables( void )
{
    int i=0;
	for(i; i<iterator; i++){
        printf("%s > %s \n" , variable_name[i] ,  variable_value[i]);
	}
}



