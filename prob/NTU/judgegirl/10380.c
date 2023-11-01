#include <stdio.h>
// #include "Turing_Machine.h"
int n, p, K;
int tape[10];
void Turing_Machine(int *head, int K) {
    int state = 0;
    for(int k = 0; k < K; ++k) {
        // printf("%d %d %d\n", *head, state, head - &tape[p]);
        *head += state;
        *head %= 4;
        int val = *head;
        if(state == 0) {
            state = 2 - (val & 1);
            ++head;
        } else if(state == 1) {
            state = 2 * (val & 1);
            head += 1 - (val & 1) * 2;
            // head -= !(val & 1);
        } else {
            state = !(val & 1);
            if(val == 3) --head; 
            else if(val == 0) ++head;
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &p, &K);
    for(int i = 0; i < n; i++) scanf("%d", &tape[i]);
 
    int *head = &tape[p];
    Turing_Machine(head, K);
 
    for(int i = 0; i < n; i++) printf("%d ", tape[i]);
 
    return 0;
}
