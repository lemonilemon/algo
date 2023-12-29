#include <stdio.h>
int main() {
    char c[1];
    fseek(stdin, -1, SEEK_END);
    fread(c, 1, 1, stdin);
    puts((c[0] & 1)? "Yes" : "No");
}
