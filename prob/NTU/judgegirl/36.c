#include <stdio.h>
#include <stdbool.h>
const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mat[5][7];
int main() {
    int y, m, cur;
    scanf("%d%d%d", &y, &m, &cur);
    if(cur >= 7 || cur < 0 || m > 12 || m <= 0) {
        printf("invalid\n");
        return 0;
    }
    bool leap = y % 400 == 0? 1 : y % 100 == 0? 0 : y % 4 == 0;
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    int d = day[m - 1] + (leap && m == 2), w = 0;
    int cnt = 1; 
    while(cnt <= d) {
        mat[w][cur++] = cnt++;
        if(cur == 7) {
            ++w;
            cur = 0;
        }
    }
    if(cur == 0) --w;
    for(int i = 0; i <= w; ++i) {
        int spaces = 0;
        for(int j = 0; j < 7; ++j) {
            if(mat[i][j] == 0) ++spaces;
            else {
                for(int k = 0; k < spaces; ++k) {
                    printf("   ");
                }
                spaces = 0;
                printf("%3d", mat[i][j]);
            }
        }
        printf("\n");
    }
    printf("=====================\n");
}


