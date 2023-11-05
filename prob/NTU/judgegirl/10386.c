#include <stdio.h>
#include <string.h>
const int MAX = 1005;
int main() {
    char line[105][MAX];
    int n = 0;
    while(fgets(line[n], MAX, stdin) != NULL) {
        ++n;
    }
    char *from[105], *to[105];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < strlen(line[i]); ++j) {
            char* p = strchr(line[(i + 1) % n], line[i][j]);
            if(p != NULL) {
                from[(i + 1) % n] = p;
                to[i] = line[i] + j;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += to[i] - from[i];
    }
    printf("%d\n", ans);
}
