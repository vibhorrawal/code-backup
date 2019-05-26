def to_bin(n):
	st = ""
	while n:
		a = n % 2
		
		st += str(a)
		n /= 2
	return str(reverse_recursion(st))
	return st

def reverse_recursion(s):
    if len(s) == 0:
        return s
    
    return reverse_recursion(s[1:]) + s[0]	

k = int(input())  
print(to_bin(k))
