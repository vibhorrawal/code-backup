for _ in range(int(input())):
    n = int(input())
    s = str(input())
    cnt = 0
    while len(s) > 0:
        oz = s.count("10")
        zo = s.count("01")
        if oz >= zo:
            s = s.replace("10","",oz)
        else:
            s = s.replace("01","",zo)
        cnt+=1

    print(cnt)
