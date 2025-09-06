# Write your code here
from functools import reduce
from math import factorial
 
mod = 1000000007
n, k = list(map(int, input().strip().split()))
bricks = sorted(map(int, input().strip().split()))
if bricks[0] != 1:
    bricks = [0] + bricks
if bricks[-1] != n:
    bricks.append(n + 1)
cnt = []
for i in range(len(bricks) - 1):
    count = bricks[i + 1] - bricks[i]
    if count != 1:
        cnt.append(count - 1)
x = reduce(lambda a, b: a * factorial(b) % mod, cnt, 1)
length = len(cnt)
total = sum(cnt)
if bricks[0] == 0:
    length -= 1
    total -= cnt[0]
if bricks[-1] == n + 1:
    length -= 1
    total -= cnt[-1]
res = factorial(sum(cnt)) * pow(x, mod - 2, mod) * pow(2, total - length, mod)
res %= mod
print(res)
