'''
   Name : Moningi Srija
   Roll no: 210050098
   Program : Ackerman
'''
store = [[-1 for i in range(10000)]for j in range(10)]
#i -> n j -> m

#defining ackerman 
def ack(m,n):
	if store[m][n] != -1: return store[m][n]
	else:
		if m==0:
			result = n+1	
		elif n==0:
			result = ack(m-1,1)
		else:
			result = ack(m-1,ack(m,n-1))
		store[m][n] = result	
	return store[m][n]

#storing some values in store beforehand
for i in range(6):
	store[0][i] = i+1

for i in range(5):
	store[i][0] = ack(i,0)

for i in range(9):
	store[3][i] = ack(3,i)  
store[4][0] = 13
		
print (ack(3,8))

