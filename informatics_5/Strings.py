s, t = input(), input()
t += t
ans = 0
for i in range(len(t)):
	if t.startswith(s, i):
		ans = i
		break
	else:
		ans = -1
print(ans)
