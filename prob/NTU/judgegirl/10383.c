#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
const int MAX = 1e5 + 5;
const char* reserved[] = {
    "if", "else", "while", "for",
    "switch", "case", "break", "return",
    "void", "int", "float", "char"
};
const char* delim = " \n,;.(){}[]!?=+-*/%~@#$^&|\\\'\"<>`";
int main() {
    char line[MAX];
    char names[35][30] = {{0}};
    int frequency[35] = {0};
    int cnt = 0;
    while(fgets(line, MAX, stdin) != NULL) {
        char* str = strtok(line, delim);
        while(str != NULL) {
            bool check = isalpha(str[0]) || (str[0] == '_');
            for(int i = 0; i < 12; ++i) {
                if(!strcmp(str, reserved[i])) {
                    check = 0;
                    break;
                } 
            }
            if(check) {
                bool flag = 1;
                char substr[30] = {0};
                strncpy(substr, str, 24);
                for(int i = 0; i < cnt; ++i) {
                    if(!strcmp(substr, names[i])) {
                        ++frequency[i];
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    frequency[cnt] = 1;
                    strncpy(names[cnt++], substr, 24);
                }
            }
            str = strtok(NULL, delim);
        }
    }
    for(int i = 0; i < cnt; ++i) {
        printf("%s %d\n", names[i], frequency[i]); 
    }
}

