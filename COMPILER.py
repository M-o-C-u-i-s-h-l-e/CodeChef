t = int(input())
while t:
	t -= 1
	s = input()
	st = list()
	Count = 0
	for i in range(len(s)):
		if s[i] == '<':
			st.append(s[i])
		else:
			if len(st) == 0:
				break
			else:
				st.pop()
			if len(st) == 0:
				Count = i + 1
	print(Count)
