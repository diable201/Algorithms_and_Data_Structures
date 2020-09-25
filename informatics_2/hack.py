s = list(map(int,input().split()))[1:]
ma = max(s)
mi = min(s)
n = [mi if i == ma else i for i in s]
for a in n:
    print(a, end=' ')