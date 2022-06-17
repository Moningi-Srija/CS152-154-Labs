''' 
	Moningi Srija
	Roll no. 210050098
	Problem 3 Iterative
'''
def factorial(p):
	if p == 1:
		return 1
	return p*factorial(p-1)

def permuiter(l,n):
	i = 0
	num = 0
	if n == 1:
		print(l)
	else:
		while num < factorial(n):
			if(i+2 == n):
				i = 0
			num = num + n 
			print(l)
			for j in range(1,n):
				print (l[j:]+l[0:j])
			l[i], l[i+1] = l[i+1], l[i]
			i+=1

# driver program which acts like int main()
l = []
n = int(input("Number of elements in the list?: "))
for i in range(0,n):
	elem = int(input())
	l.append(elem)
permuiter(l,n)