#include <stdio.h>
#include <string.h>
const int MAXLEN = 1e5 + 5, MAXTOKEN = 1005;
const char delim[] = ".,!?;:[](){} \n";
int split(char* c, char* dest[MAXTOKEN]) {
    int cnt = 0;
    char* substr = strtok(c, delim);
    while(substr != NULL) {
        dest[cnt++] = substr;
        substr = strtok(NULL, delim);
    }
    return cnt;
}
int main() {
    char c[2][MAXLEN];
    char* dest[2][MAXTOKEN];
    fgets(c[0], MAXLEN, stdin);
    fgets(c[1], MAXLEN, stdin);
    int n = split(c[0], dest[0]);
    int m = split(c[1], dest[1]);
    int i = 0, j = 0;
    while(i < n || j < m) {
        if(i >= n) {
            printf("%s", dest[1][j++]);
            continue;
        } 
        if(j >= m) {
            printf("%s", dest[0][i++]);
            continue;
        }
        if(strcmp(dest[0][i], dest[1][j]) < 0) {
            printf("%s", dest[0][i++]);
        } else {
            printf("%s", dest[1][j++]);
        }
    }
    printf("\n");
    return 0;
}
