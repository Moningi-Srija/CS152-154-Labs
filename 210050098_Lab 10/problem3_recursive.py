''' 
	Moningi Srija
	Roll no. 210050098
	Problem 3 Recursive
'''

def factorial(p):
	if p == 1:
		return 1
	return p*factorial(p-1)

def permutation(l,lft,rgt):
	#lft is leftmost and right is rightmost index
	#l is the list
	if lft == rgt:
		#base case
		#recursion reached the end 
		print(l)
	else:
		for i in range(lft,rgt):
			#elements get swapped
			l[lft], l[i] = l[i], l[lft]
			permutation(l,lft+1,rgt) #one step ahead and goes ahead from there
			#goes one step behind
			#to avoid repetitions
			l[lft], l[i] = l[i], l[lft]

# driver program which acts like int main()
l = []
n = int(input("Number of elements in the list?: "))
for i in range(0,n):
	elem = int(input())
	l.append(elem)

permutation(l,0,n)
print(f"total number of possibilities are {factorial(n)}")