#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>

const char* path;
const char* home;
int max_length;
char project_directory[1024];
char *path_array[]; // array for splitted path
int index2; // for looping on path.
int sentense_index; //for accessing the array
int temp_index;
char *temp; // for reading words.
bool path_boolean = false; //for end of lie

void setup_environment( void )
{
    // you should implement this function
    path= getenv("PATH");
    home= getenv("HOME");
    max_length = 512;
    getcwd(project_directory, sizeof(project_directory));
    split_path();

}

void split_path(){


    index2=0;
    sentense_index = 0;
    while(path[index2] != '\0'){
        temp_index = 0;
        temp = malloc(temp_index + 1);
        path_boolean = false;
            while(path[index2]!= ':'){

                temp[temp_index] = path[index2];
                temp_index++;
                temp = realloc(temp, temp_index+1);
                path_boolean = true;
                    if( path[index2+1]  != '\0'){
                        index2++;
                    }
                    else {
                        break;
                    }

            }
            if(path_boolean == true) {
                 temp[temp_index] = '\0';
                 path_array[sentense_index] = malloc(max_length);
                 path_array[sentense_index] = temp;
                 sentense_index++;
                 free(temp);
            }
             index2++;

}
}


char* get_path(){
    return path;
}
char* get_home(){
    return home;
}
char get_project_directory(){
    return project_directory;
}


int get_max_length(){
    return max_length;
}
