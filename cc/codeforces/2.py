def solve(name):
	ans = -1
	incl = [False for i in range(size)]
	it = 0
	i = 0	
	while it is not len(name):
		if s[i]	== name[it]:
			incl[i] = True
			it = it + 1
			if i > ans:
				ans = i
			i = 0

		i = i + 1	
	print(ans + 1)		

size = int(input())
s = input() # string
t = int(input())

while t != 0:
	name = input()
	solve(name)
	t = t - 1