#codechef snackdown
n = int(input())
count = list(range(n))
j = 0
while(n != 0):
 	teams,k = input().split(" ")
 	teams = int(teams)
 	k = int(k)
 	scores = []
 	scores = input().split(" ")
 
 	for i in range(teams):
 		scores[i] = int(scores[i])

 	scores.sort(reverse=True)	
 	#print (scores)
 	value = scores[k-1]
 	count[j] = 0
 	for i in range(teams):
 		if(scores[i]>=value):
 			#print('count['+str(j)+'] = '+str(count[j]))
 			count[j] = count[j] + 1
 	#print (count)
 	n = n - 1		
 	j = j + 1

for i in range(j):
 	print (count[i])	