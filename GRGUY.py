for _ in range(int(input())):
	s1 = input()
	s2 = input()
	n = len(s1)
	ls1 = [0] * n
	ls2 = [0] * n
	ls1[0] = 0 if s1[0] == '.' else int(1e7)
	ls2[0] = 0 if s2[0] == '.' else int(1e7)
	for i in range(1, n):
		ls1[i] = min(ls1[i-1], ls2[i-1] + 1) if s1[i] == '.' else int(1e7)
		ls2[i] = min(ls2[i-1], ls1[i-1] + 1) if s2[i] == '.' else int(1e7)
	ans = min(ls1[n-1], ls2[n-1])
	print("{}\n{}".format("Yes", ans)) if ans < int(1e7) else print("No")
