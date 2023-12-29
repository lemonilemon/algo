#include <unistd.h>
char ch[17] = "AaW大哥牛逼!";
int main() {
    write(1, ch, 16);
}
