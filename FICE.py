# maybe get accepted (but mostly gets TLE)

ls = [0] * 1001
ls[0], ls[1] = 0, 1
for i in range(2, 1001):
    ls[i] = ls[i-1] + ls[i-2]

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(2 * ls[n] % m)
