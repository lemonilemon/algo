from sys import stdin, stdout
from collections import deque
k, n = map(int, stdin.readline().split())
ans = set()
color = set()
que = deque() 
que.append((0, 1, k))
color.add((0, 1, k))
ansstr = ""
while n > 0 and len(que) > 0:
    a, b, c = que.popleft()
    if min(a, b, c) > 0 and a != b and b != c and a != c:
        if not (a in ans or b in ans or c in ans):
            ans.add(a)
            ans.add(b)
            ans.add(c)
            s = f"{a} {b} {c}\n"
            ansstr += s
            n -= 1
    v = (b * k + c * k - a, b, c)
    if not (v in color):
        que.append(v)
        color.add(v)
    v = (a, a * k + c * k - b, c)
    if not (v in color):
        que.append(v)
        color.add(v)
    v = (a, b, a * k + b * k - c)
    if not (v in color):
        que.append(v)
        color.add(v)
stdout.write(ansstr)
