# Linux Shell in C

### Make Instructions
In the directory containing the source code, execute:
```bash
$ make
$ ./a.out
```

## Functionality

### Prompt
  - Prompt is displayed in the same format as in BASH with username, system name and current working directory. Home directory ("~") is considered as the directory from which the shell a.out was executed. 
  - Errors while getting the current working directory (home directory), username or system name leads to termination of the shell.
  
**Input** : multiple commands can be given separated by `;`.
Extra whitespaces given in commands or arguments is ignored.  
  
**Error checking** : If any command fails to execute due to mulitple reasons, the relevant error message will be printed to the terminal by use of `perror` and in some cases without `perror`. That command will be skipped and shell will continue to run.

### Commands
  1. `pwd` - prints the absolute path of the current working directory.
  2. `echo` - prints whatever is given as argument as it is
  3. `cd` - changes the cwd to the mentioned directory, if no argument, changes to the home (~) directory.
     - arguments: `.`, `..`, `-`, `~`, any relative/absolute path to a directory
  4. `history`
     - by default prints the last 10 typed commands of shell, or if lesser than 10 available, then print them.
     - with flag *num*. Prints last *num* commands from history. *1 < num < 21*.
     - Maximum of 20 commands are stored in the history.
     - On closing the shell by using `CTRL+D` or `exit` or `quit`, the history is saved to a file `.shell_history` in the home directory. History is loaded from the same file for other shell sessions.
     - If the file `.shell_history` is not formed yet, or is unreadable, it is ignored. Errors are generated if writing to this file is problematic.
     - `Up Arrow` - on pressing the up arrow, recent commands can be seen in the order newer to older.
     - `Down Arrow` - on pressing the down arrow, recent commands can be seen in the order older to newer.
  5. `pinfo` - displays the details of a process with pid passed as argument.
     - If no argument passed, the pid of the running shell is considered. 
   6. Other commands from Bash - executed with the help of `execvp` command. 
   7. `jobs` - List all the background processes of the shell, with Job_Num, status (either Running or Stopped), Name, PID. 
      -  The result is sorted albhabetically by the Name of the command, and then by the Job Num.
      -  The `Job Num` is alloted by the shell and changed dynamically as the processes are killed/terminated from the background.
      -  The `Job Num` is given sequentially, a process starting earlier will have lower Job Num.
   8.  `bg` - Takes the argument *job_num* which is made by the shell. It continues any stopped process which is in the background, if its already running, it will be ignored.
   
### Processes and Other functionalities
- **Foreground process** - execution of process that happen in the foreground. These take away control from shell and must be finished/terminated to regain control of the shell.
- **Background process** - any command passed with `&` flag is treated as background process. The user can use the shell normally without waiting for completion of command. The pid of child process is printed to terminal when command is executed. 
- **Finishing of Background process** - a message is printed whenever a background process is completed/terminated, expressing whether is was normal or abnormal termination. 
- **Piping** - The shell supports `|` piping, which transfers the input and output from one command to another instead of the terminal and thus allows interprocess communication. Implemented using `dup` and `dup2`.
- **Signal Handling**-
  - `CTRL+Z` - converts any foreground process to background and stops it. Signal used - `SIGTSTP`. no effect on the shell if no foreground process running. Implemented using `signal()` function.
  - `CTRL+C` - Interrupts any foreground process. Signal used - `SIGINT`. No effect on the shell if no foreground process running. Implemented using `signal()` function.
  - `CTRL+D` - Closes this shell, but not the actual terminal of the computer. Implemented by considering the EOF (end of file) ASCII character. 
## File Structure
| Files            | Functionality                                                                                                     |
| ---------------- | ----------------------------------------------------------------------------------------------------------------- |
| cd.c             | `cd` command                                                                                                      |
| echo.c           | `echo` command                                                                                                    |
| history.c        | `history` command                                                                                                 |
| pinfo.c          | `pinfo` command                                                                                                   |
| pwd.c            | `pwd` command                                                                                                     |
| jobs.c           | `jobs` command                                                                                                    |
| sig.c            | `sig` command                                                                                                     |
| bg.c             | `bg` command                                                                                                      |
| shell_commands.c | Executing foreground/background processes, and the commands which were not implemented exclusively for this shell |
| piping.c         | Implmentation of Piping feature of the shell                                                                      |
| arrow.c          | For taking input from the shell through a lower level code                                                        |
| commands.h       | Header file for declarations of all the commands related .c files                                                 |
| prompt.c         | Prompt functionality in shell                                                                                     |
| utils.c          | Various utility functions                                                                                         |
| utils.h          | Header File for declaring functions in utils.c                                                                    |
| main.c           | The main file containing the `main` function for running the shell                                                |
| headers.h        | Header file for declaring all global variables and including other .h files                                       |
| makefile         | make instructions for compiling the code                                                                          |
