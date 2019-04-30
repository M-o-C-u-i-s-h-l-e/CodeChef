from math import sqrt

for _ in range(int(input())):
	h, s = map(float, input().split())
	if h * h < 4 * s:
		print(-1)
		continue
	a = sqrt(h * h + 4 * s)
	b = sqrt(h * h - 4 * s)
	print(round((a-b)/2, 6), round((a+b)/2, 6), round(h, 6))
