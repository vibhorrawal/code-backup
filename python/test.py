tc = int(input())
for i in range(tc):
    lis = list(map(int,input().split()))
    m = lis[0]
    n = lis[1]
    typ = list(map(int,input().split()))
    cost = list(map(int,input().split()))
    arr = [0] * m
    res = []
    for i in range(len(typ)):
        arr[typ[i]] = cost[i] + arr[typ[i]]
    for j in arr:
        if j!=0:
            res.append(j)

    print(min(res))
