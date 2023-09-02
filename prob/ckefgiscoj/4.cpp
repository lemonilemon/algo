#include <stdio.h>
char c[1];
int main() {
    fseek(stdin, -1, SEEK_END);
    fread(c, 1, 1, stdin);
    if((c[0] ^ '0') & 1) puts("Yes");
    else puts("No");
}
