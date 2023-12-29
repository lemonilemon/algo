#include <stdint.h>
#include <stdlib.h>
 
void ModifyingMusicData(const short int buffer[], const int buffersize, short int modified[]) {
    for(int i = 0; i < buffersize; i++) {
        modified[i * 2] = buffer[i];
        modified[i * 2 + 1] = buffer[i];
    }
}
