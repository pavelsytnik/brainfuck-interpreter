#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ARR_SIZE 30000

int main(int argc, char **argv) {
    FILE *file;
    uint8_t *ptape;
    char *pcode;
    int c;
    uint8_t tape[ARR_SIZE];
    char code[ARR_SIZE];

    if (argc != 2) return 1;

    memset(tape, 0, sizeof(tape));
    ptape = tape;

    file = fopen(argv[1], "r");
    pcode = code;
    while ((c = getc(file)) != EOF) {
        *pcode++ = (char)c;
    }
    *pcode = '\0';
    fclose(file);

    for (pcode = code; *pcode != '\0'; pcode++) {
        switch (*pcode) {
        case '+': (*ptape)++; break;
        case '-': (*ptape)--; break;

        case '>': ptape++; break;
        case '<': ptape--; break;

        case '[':
            if (*ptape == 0) {
                int depth = 1;
                while (depth > 0) {
                    pcode++;
                    if (*pcode == '[') depth++;
                    else if (*pcode == ']') depth--;
                }
            }
            break;

        case ']':
            if (*ptape != 0) {
                int depth = 1;
                while (depth > 0) {
                    pcode--;
                    if (*pcode == '[') depth--;
                    else if (*pcode == ']') depth++;
                }
            }
            break;

        case '.':
            putchar(*ptape); break;
        case ',':
            *ptape = (uint8_t)getchar(); break;
        }
    }

    return 0;
}
