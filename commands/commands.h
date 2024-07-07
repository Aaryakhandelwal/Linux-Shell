#ifndef COMMMANDS
#define COMMMANDS

void cd();
void echo();
void pinfo();
void pwd();
void shell_commands(int bg);
void bg();
void jobs();

// history
void reset_history_buffer();
void load_history_from_file();
void save_history_to_file();
void add_to_history_buffer(char *line);
void print_history();
void get_history_at_index(int *ind, char *input_command);

#endif