
#ifndef LINUX_IPC_UTILS_H
#define LINUX_IPC_UTILS_H

const string RESET   = "\033[0m";
//char *RESET = str1.to_str();
const string RED  =    "\033[31m";      /* Red */
//char *RED = str2.to_str();
const string GREEN  =  "\033[32m";      /* Green */
//char *GREEN = str3.to_str();

void error_message(char *);
void error_and_exit(char *);
void status_message(char *);

void remove_newline(char *);
int read_line(char *, int);
int read_int_from_stdin(int *);
int read_int_from_buffer(const char *, int *);

#endif //LINUX_IPC_UTILS_H




