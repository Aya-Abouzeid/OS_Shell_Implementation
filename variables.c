#include "variables.h"
#include <stdbool.h>
#include <stdio.h>
#include "stdlib.h"
#include <string.h>

char *cd_paths[]; //for the visited paths
char *variable_name[]; //for shell variables
char *variable_value[]; // value of shell variable


const char* lookup_variable( const char* key )
{
	// you should implement this function
}

void set_variable( const char* key , const char* value )
{
	// you should implement this function
}

void print_all_variables( void )
{
	// you should implement this function
}
