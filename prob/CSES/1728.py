from decimal import *
n = int(input())
ex = Decimal(0)
r = list(map(Decimal, input().split()))
for i in range(n):
    for j in range(i):
        if r[j] >= r[i]:
            ex += (2 * r[j] - r[i] - 1) / (2 * r[j])
        else:
            ex += (r[j] - 1) / (2 * r[i])
ex = ex.quantize(Decimal('0.000001'), rounding=ROUND_HALF_EVEN)
print(ex)
