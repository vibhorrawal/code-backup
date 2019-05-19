def fib(limit):
	a = 1
	b = 1
	if limit == 1:
		print (a)
		return
	if limit >= 2:
		print(b)
		print(a)
	count = 2
	while (count < limit):
		c = a + b
		print (c)
		a = b
		b = c
		count += 1

# l = int(input())
l = 5
fib(l)