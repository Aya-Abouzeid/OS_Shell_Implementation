#ifndef ENVIRONMENT_H_   /* Include guard */
#define ENVIRONMENT_H_


/*
	- This function should be responsible for importing environment variables into your project.
	- Typically, this function should add $PATH, $HOME & any other needed variables into your variables table
	- Any future work on variables added by this function should be done through your variable table
	- You also need to store the path of the directory containing this project into a variable,
	  you'll need it in printning the history & log into a files beside your executable file
*/
<<<<<<< HEAD
void setup_environment( void );
char* get_path();
char* get_home();
int get_max_length();
=======
void setup_environment( );
char* get_path();
char* get_home();
int get_max_length();
char* get_path_array();
char get_project_directory();
>>>>>>> 6dafcd10c0579dc0cf9e80d5b037528135dc0a40

#endif // ENVIRONMENT_H_
