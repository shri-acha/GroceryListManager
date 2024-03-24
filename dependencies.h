#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_SIZE 1024
#define MAX_LENGTH 2048

void sort();
void load_file();
void add_to_list_file();
void read_list_from_file();
void delete_from_file();
void choice_taker(int);
void label();
void clear_array(int);
void clear_all();
void exit_or_not();
void function_caller(int);
void scroll_able(int );
void scroll_renderer(int);
void print_slip();
//GLOBAL DEFINITIONS
char storage[MAX_SIZE][MAX_LENGTH];

