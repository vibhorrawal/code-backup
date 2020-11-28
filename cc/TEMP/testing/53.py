for _ in range(int(input())):
    n = int(input())
    s = input()
    x = ""
    # while len(s) > 0:
    f = int(s[0])
    for i in range(1,n):
        if f == int(s[i]):
            x += s[i]
        else:
            f = 1-f
    # print(x)
    cnt = 1
    while len(x) > 0:
        z = ""
        f = int(x[0])
        for i in range(1,len(x)):
            if f == int(x[i]):
                z += x[i]
            else:
                f = 1-f
        x = z
        # print(x)
        cnt+=1
    print(cnt)
