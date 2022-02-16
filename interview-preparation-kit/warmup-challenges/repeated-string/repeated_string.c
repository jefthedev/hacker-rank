#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

long parse_long(char*);
long count_letter(char l, long offset, char* s);

/*
 * Complete the 'repeated_string' function below.
 * The function accepts the following parameters: (1) LONG_INTEGER n; (2) STRING s.
 * The function is expected to return a LONG_INTEGER: amount of a's inside repeated string.
*/
long repeated_string(long n, char* s) {
    long counter;
    long a_s = count_letter('a', strlen(s), s);
    
    if(a_s == 0)                     // No a's.
        counter = 0;
    else {                           // At least one a.
        long r = n % strlen(s);
        counter = (n / strlen(s)) * a_s;
        counter += (r != 0) ? count_letter('a', r, s) : 0;     
    }

    return counter;
}

/*
 * The function accepts the following parameters: (1) CHAR letter; (2) LONG_INTEGER offset; (3) STRING s.
 * The function is expected to return the a LONG_INTEGER: the occurrences of letter l inside string s.
*/
long count_letter(char l, long offset, char* s) {
    long l_count = 0;

    for(long i = 0; i < offset; i++)
        if(s[i] == l)
            l_count++;
    
    return l_count;
}

int main() {
    char* s = readline();
    long n = parse_long(ltrim(rtrim(readline())));
    long result = repeated_string(n, s);

    printf("%ld\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while(true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if(!line)
            break;

        data_length += strlen(cursor);
        if(data_length < alloc_length - 1 || data[data_length - 1] == '\n')
            break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if(!data) {
            data = '\0';
            break;
        }
    }

    if(data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);

        if(!data) 
            data = '\0';
    } else {
        data = realloc(data, data_length + 1);

        if(!data)
            data = '\0';
        else
            data[data_length] = '\0';
    }

    return data;
}

char* ltrim(char* str) {
    if(!str)
        return '\0';

    if(!*str)
        return str;

    while(*str != '\0' && isspace(*str))
        str++;

    return str;
}

char* rtrim(char* str) {
    if(!str)
        return '\0';

    if(!*str)
        return str;

    char* end = str + strlen(str) - 1;
    while(end >= str && isspace(*end))
        end--;

    *(end + 1) = '\0';
    return str;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);

    if(endptr == str || *endptr != '\0')
        exit(EXIT_FAILURE);

    return value;
}
