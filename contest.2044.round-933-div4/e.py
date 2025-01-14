import math

t = int(input())
for _ in range(t):
    k, l1, r1, l2, r2 = [int(x) for x in input().split()]
    res = 0
    start = max([l1, l2])
    end = min([r1, r2])
    if start <= end:
        res += end - start + 1
    nmax = 40
    for n in range(1, nmax):
        kn = k ** n
        l = math.ceil(l2 / kn)
        r = int(r2 / kn)

        xmax = min([r1, r])
        xmin = max([l1, l])
        while xmin * kn < l2:
            xmin += 1
        while xmax > r2 / kn:
            xmax -= 1
        if xmin > xmax:
            continue
        res += int(xmax) - int(xmin) + 1

    print(res)
