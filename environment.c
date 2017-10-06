#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include "variables.h"

const char* path;
const char* home;
int max_length;
char project_directory[1024];


void setup_environment( )
{
    // you should implement this function
    path= getenv("PATH");
    home= getenv("HOME");

    set_variable("PATH" , path);
    set_variable("HOME" , home);
    max_length = 512;
    getcwd(project_directory, sizeof(project_directory));


}




char* get_path(){
    return path;
}
//char* get_path_array(){
//    return *path_array;
//}


char* get_home(){
    return home;
}
char get_project_directory(){
    return project_directory;
}


int get_max_length(){
    return max_length;
}
