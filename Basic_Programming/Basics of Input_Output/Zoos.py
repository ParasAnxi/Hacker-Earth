a = input()

from collections import Counter
x = Counter(a)
if x['z']*2 == x['o']:
    print("Yes")
else:
    print("No") 