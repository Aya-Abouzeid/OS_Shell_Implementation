# OS_Shell_Implementation

A Unix shell is a command-line interpreter that provides a traditional user interface for the Unix
operating system and for Unix-like systems. The shell can run in two modes: interactive and batch.
In the shell interactive mode, ,the shell displays a prompt (e.g. Shell>) and the user of the shell 
types commands at the prompt. the shell program executes each of thesecommands and terminates when
the user enters the exit command at the prompt. 

- In the shell batch mode, the shell starts by calling the shell program and specifying a batch file 
to execute the commands included in it. This batch file contains the list of commands (on separate lines)
that the user wants to execute. 

- The shell terminates when the end of the batch file isreached or the user types
```R
Ctrl-D.
or
exit
```

### Running

- The C program must be invoked exactly as follows:
```R
Shell [batchFile]
```
where the batchFile is an optional argument to the shell program. If it is present, the shell will
read each line of the batchFile for commands to be executed. If not present, the shell will run in
interactive mode by printing a prompt to the user at stdout and reading the command from stdin.

