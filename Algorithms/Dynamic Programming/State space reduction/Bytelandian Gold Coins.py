# Write your code here
dp = {0: 0}

def exchange(x, dp):
    if x in dp:
        return dp[x]
    else:
        dp[x] = max(x, exchange(x // 2, dp) + exchange(x // 3, dp) + exchange(x // 4, dp))
        return dp[x]
 
 
while True:
    try:
        n = int(input())
        print(exchange(n, dp))
    except:
        break
