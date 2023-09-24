#include <stdio.h>
inline char readchar(){
	const int S = 1<<16;
	static char buf[S], *p = buf, *q = buf;
	return p == q and (q = (p = buf) + fread(buf, 1, S, stdin)) == buf ? EOF : *p++;
}

#define getchar getchar_unlocked

inline bool input(unsigned int &_x)
{
    _x = 0;
    char _tc = getchar();
    while((_tc < '0' || _tc > '9') && _tc != '-' && _tc != EOF) _tc = getchar();
    while(_tc >= '0' && _tc <= '9') _x = (_x << 3) + (_x << 1) + (_tc-48), _tc = getchar();
    return _x;
}
#define putchar putchar_unlocked

inline void output(unsigned int _x)
{
    char _buff[10]; int _f = 0;
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(--_f; _f >= 0; --_f)
        putchar(_buff[_f]);
}
int main() {
    unsigned int a, b;
    input(a);
    input(b);
    output(a + b);
}
