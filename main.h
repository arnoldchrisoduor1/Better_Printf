#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*SIZES*/
#define S_LONG 2
#define S_SHORT 1

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

//fmt - the format
//fn - the function associated

struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int ,int);
};

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list, char buffer[],
int flags, int width, int precision, int size);

//Functions to print chars and strings
int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_percentage(va_list types, char buffer[], int flags, int width,
int precision, int size);

/*Functions to handle specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/***********************UTILS*************************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif