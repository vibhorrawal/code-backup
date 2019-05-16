#python 3 code
def z(num):
	count = 0
	for i in range(num+1):
		m = i
		while True:
			if ((m / 5 != 0) and (m % 5 == 0)):
				count = count + 1
				m = m / 5
			else:
				break
	return count				


n = int(input())
for i in range(n):
	k = int(input())
	print (z(k))