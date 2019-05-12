j, s, m = map(int, input().split())
ans = (m - j) // s
print("Unlucky Chef") if (ans & 1) else print("Lucky Chef")
