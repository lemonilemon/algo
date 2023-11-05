#include <stdio.h>
#include <string.h>
const int MAX = 1e5 + 5;
char* suffix[] = { 
    "able", "ary", "ed", "ence",
    "ful", "hood", "ical", "ing",
    "ish", "ism", "ist", "ive",
    "ize", "less", "ly", "ment",
    "ness", "ous", "ship", "tion"
};
const char delim[] = " .,!?;:\n";
int cnt[20];
int main() {
    char line[MAX];
    while(fgets(line, MAX, stdin) != NULL) {
        char* str = strtok(line, delim);
        while(str != NULL) {
            for(int i = 0; i < 20; ++i) {
                char substr[100];
                strncpy(substr, str + strlen(str) - strlen(suffix[i]), strlen(str));
                if(!strcmp(substr, suffix[i])) {
                    ++cnt[i];
                    break;
                }
            }
            str = strtok(NULL, delim);
        }
    }
    for(int i = 0; i < 20; ++i) {
        if(cnt[i]) {
            printf("%s:\n", suffix[i]);
            printf("Frequency: %d\n", cnt[i]);
        }
    }
}
