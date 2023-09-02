#include <stdio.h>

#define getchar getchar_unlocked

inline void input(int &_x)
{
    _x = 0;
    char _tc = getchar();
    while((_tc < '0' || _tc > '9') &&  _tc != EOF) _tc = getchar();
    while(_tc >= '0' && _tc <= '9') _x = (_x << 3) + (_x << 1) + (_tc-48), _tc = getchar();
}
#define putchar putchar_unlocked

inline void output(int _x)
{
    char _buff[10]; int _f = 0;
    if(!_x) putchar('0');
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(--_f; _f >= 0; --_f)
        putchar(_buff[_f]);
}

int main() {
    int k, n;
    int cnt = 0;
    input(k);
    input(n);
    int x = k - 1 < n? k - 1 : n;
    output((x * (x + 1)) >> 1);
}

