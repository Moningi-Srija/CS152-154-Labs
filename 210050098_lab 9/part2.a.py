'''Moningi Srija
   210050098
   Frequency of common elements
'''
l1 = []
n1 = int(input("number of elements in list 1? : "))
for i in range(0,n1):
	element = int(input())
	l1.append(element)
	
l2 = []
n2 = int(input("number of elements in list 2? : "))
for i in range(0,n2):
	element = int(input())
	l2.append(element) 

s1 = set(l1)
s2 = set(l2)

s3 = s1&s2
size = len(list(s3))
l3=[]

for e in s3:
	a = 0
	while e in l1:
		a = a + 1
		l1.remove(e)
	while e in l2:
		a = a + 1
		l2.remove(e)
	l3.append([e,a])

print(l3)
