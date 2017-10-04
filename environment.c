#include "environment.h"
#include "stdio.h"
#include "stdlib.h"

const char* path;
const char* home;
int max_length;
void setup_environment( void )
{
    // you should implement this function
 path= getenv("PATH");
    home= getenv("HOMEPATH");
    max_length = 512;

}
char* get_path(){
return path;
}
char* get_home(){
return home;
}

int get_max_length(){
return max_length;
}
