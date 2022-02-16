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
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'sock_merchant' function below.
 * The function accepts the following parameters: (1) INTEGER n; (2) INTEGER ar_count; (3) INTEGER_ARRAY ar.
 * The function is expected to return an INTEGER: the numbers of sock pairs.
 */
int sock_merchant(int n, int ar_count, int* ar) {
    int i = 0;
    int* counter = malloc(100 * sizeof(int));
    for(i = 0; i < n; i++)
        counter[ar[i] - 1]++;
        
    ar_count = 0;
    for(i = 0; i < 100; i++)
        ar_count += counter[i]/2;
    
    return ar_count;
}

int main() {
    int n = parse_int(ltrim(rtrim(readline())));
    char** ar_temp = split_string(rtrim(readline()));
    int* ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int ar_item = parse_int(*(ar_temp + i));
        *(ar + i) = ar_item;
    }

    int result = sock_merchant(n, n, ar);
    printf("%d\n", result);
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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while(token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if(!splits)
            return splits;

        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if(endptr == str || *endptr != '\0')
        exit(EXIT_FAILURE);

    return value;
}

