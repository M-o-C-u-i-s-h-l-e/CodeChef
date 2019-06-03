from math import gcd

for _ in range(int(input())):
    n = int(input())
    ls = sorted(list(map(int,input().split())))
    flag = True
    for i in range(2, n):
        if ls[i] != (ls[i-1] + gcd(ls[i-1], ls[i-2])):
            flag = False
            index1 = ls[i]
            break
    if flag:
        index = ls.pop()
        ls = [index] + ls
        flag = True
        for i in range(2, n):
            if ls[i] != (ls[i-1] + gcd(ls[i-1], ls[i-2])):
                index = ls.pop(0)
                ls = ls + [index]
                break
    if not flag:
        ls.remove(index1)
        ls = [index1] + ls
        flag = 1
        for i in range(2, n):
            if ls[i] != (ls[i-1] + gcd(ls[i-1], ls[i-2])):
                flag = False
                break
    if n < 3:
        ls.sort(reverse=True)
    if flag == 0:
        print('-1')
    else:
        print(*ls, sep = ' ')
