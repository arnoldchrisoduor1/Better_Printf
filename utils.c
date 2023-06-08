#include "main.h"


// is_printable - evaluates if a char is printable
int is_printable(char c){
    if(c >= 32 && c < 127){
        return (1);
    } else {
        return (0);
    }
}

int append_hexa_code(char ascii_code, char buffer[], int i){
    char map_to[] = "0123456789ABCDEF";
    //hexa format code is always 2 digits long
    if (ascii_code < 0){
        ascii_code *= -1;
    }

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];

    return 3;
}

int is_digit(char c){
    if (c >= '0' && c <= '9'){
        return (1);
    } else {
        return (0);
    }
}

// checks whether num is long int, short in or int
long int convert_size_number(long int num, int size){
    if(size == S_LONG){
        return (num);
    }
    else if (size == S_SHORT){
        return ((short)num);
    } else {
        return ((int)num);
    }
}

//checks whether unsigned num is long int, short int or int
long int convert_size_unsgnd(unsigned long int num, int size){
    if(size == S_LONG){
        return (num);
    }
    else if(size == S_SHORT){
        return ((unsigned short)num);
    } else {
        return ((unsigned short)num);
    }
}
