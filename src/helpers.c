/*
Non-traversal related functions go here
*/

#include "main.h"

// custom strupr function built to be portable for every compiler
char *strupr(char *str) {
    char *orig = str;
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
    return orig;
}