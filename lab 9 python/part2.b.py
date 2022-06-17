'''
  Moningi Srija
  210050098
  Powerset of given set
'''
def powerset(fullset):
	listsub = list(fullset)
	subsets = []
	for i in range(2**len(listsub)):
		subset = []
		for k in range(len(listsub)):            
			if i & 1<<k:
				subset.append(listsub[k])
		if(len(subset) == 0):
			subsets.append({})
		else:
			subsets.append(set(subset))       
	return subsets

l = []
n = int(input("Number of elements in the set?: "))
for i in range(0,n):
	elem = int(input())
	l.append(elem)

pl = powerset(l)

print(pl)
