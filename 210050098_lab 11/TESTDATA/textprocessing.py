'''
   Name : Moningi Srija
   Roll no: 210050098
   Program : Text Processing
'''

from functools import reduce
 
def analyse(filename):
	tf = open(filename,"r")
	v = 0
	l = []
 	
	vowel_list = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
 	
	with open(filename,"r"):
		for line in tf:
			for word in line.split():
				for alpha in word:
					if alpha in vowel_list:
						v+=1
				l.append(v)
				v=0
	tf.close()
	return l
	
l = ["data1.txt", "data2.txt", "data3.txt", "data4.txt","data5.txt"]
m = map(analyse, l)
list_level_2 = list(m)
#print(list_level_2)

def sum(x,y):
	return x+y
def avg(l):
	return reduce(sum,l)/len(l)
	
mf = map(avg,list_level_2)
list_final = list(mf)
#print(list_final)

def top(x):
	l = max(lis)
	if(x == l): return True
	else: return False

lis = list_final[:]
fp = filter(top,list_final)
lf = list(fp)
print("Top 1 data",end = "")
print(list_final.index(max(lis))+1,end = "")
print(".txt",end =" ")
print(lf[0])

for i in range(2):
	lis.remove(lf[0])
	fp = filter(top,list_final)
	lf = list(fp)
	print("Top",i+2 ,"data",end = "")
	print(list_final.index(max(lis))+1,end = "")
	print(".txt",end =" ")
	print(lf[0]) 		
