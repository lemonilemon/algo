#include "freqCalculator.h"
#include <string.h>
#include <stdlib.h>
double* freqCalculate(char names[1024]) {
    double* ret = (double*)malloc(sizeof(double) * 512);
    const double freq1[] = { 55, 61.735, 32.703, 36.708, 41.203, 43.654, 48.999 };
    char* token;
    token = strtok(names, " \n");
    int cnt = 0;
    while(token != NULL) {
        double freq = freq1[token[0] - 'A'];
        int mult = token[1] - '0';
        for(int i = 1; i < mult; ++i) {
            freq = freq * 2;
        }
        ret[cnt++] = freq;
        token = strtok(NULL, " \n");
    }
    return ret;
}
