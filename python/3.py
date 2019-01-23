#codechef snackdown
n = int(input())
count = list(range(n))
i = 0
while(n != 0):
	n = n - 1
	days = int(input())
	people = []
	people = input().split()
	#people = [int(x) for x in raw_input().split()]
	people = [int(i) for i in people]
	total,j = 0,0
	while days>=0:
		total = total + people[j]
		days = days - total
		j = j + 1
	count[i] = j - 1
	i = i + 1	

for l in range(i):
	print (count[l])	