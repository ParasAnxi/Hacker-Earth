n = int(input())
a = list(map(int,input().split()))
start = 1
k = 2
while start<=n:
    start += k
    k+=1

start -= k-1
k-=2
initialSum = sum(a[:start])
ma = initialSum

for i in range(1,n):
    initialSum -= a[i-1]
    if start<n:
        initialSum += a[start]
        start+=1
    else:
        k-=1
        initialSum -= sum(a[n-k:n])
        start -= k
    if initialSum > ma:
        ma =initialSum
print(ma)