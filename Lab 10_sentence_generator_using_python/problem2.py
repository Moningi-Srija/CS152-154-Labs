''' 
	Moningi Srija
	Roll no. 210050098
	Problem 2 Sentence Generator Modified
'''
#taking all words into lists from files
#for subjects
sub = []
with open('subject.txt') as s:
	for line in s:
		for word in line.split():
			sub.append(word)

sa = sub[:4] #group a
for i in range(4,7):
	sa.append("")

sb = sub[4:] #group b
for i in range(3,7):
	sb.append("")
s.close() 

#for verbs
ver = []
with open('verb.txt') as v:
	for line in v:
		for word in line.split():
			ver.append(word)

vpr = ver[1:3]    #verbs -> simple present tense
for i in range(2,7):
	vpr.append("")

vprc = []
for i in range(0,1):
	vprc.append(vpr[i] + " and " + vpr[i+1])
for i in range(1,7):
	vprc.append("")

vprb = []
for i in range(0,7):
	if i >= 0 and i<2:
		vprb.append(vpr[i]+"s")
	else:
		vprb.append(vpr[i])

vprbc = []
for i in range(0,1):
	vprbc.append(vprb[i] + " and " + vprb[i+1])
for i in range(1,7):
	vprbc.append("")

vp = ver[4:6]    #verbs -> simple past tense
for i in range(2,7):
	vp.append("")

vpc = []
for i in range(0,1):
	vpc.append(vp[i] + " and " + vp[i+1])
for i in range(1,7):
	vpc.append("")

vf = []
for i in range(0,7):
	if i >= 0 and i<2:
		vf.append("will "+vpr[i])
	else:
		vf.append(vpr[i])

vfc = []
for i in range(0,1):
	vfc.append("will " + vpr[i] + " and " + vpr[i+1])
for i in range(1,7):
	vfc.append("")

v.close()

#for objects
obj = []
with open('object.txt') as o:
	for line in o:
		for word in line.split():
			obj.append(word)
for i in range(2,7):
	obj.append("")

objc = []
for i in range(0,1):
	objc.append(obj[i] + " and " + obj[i+1])
for i in range(1,7):
	objc.append("")
o.close()

#constants for this text file we can change these if we modify text file
R = 3
C = 7 

def printsen(s, m, n, result):
	result[m] = a[m][n]  #adding current word to output array

	#base case
	#print -> if this is the last word of the list -> (that is sentence got completed)
	if m==R-1:
		for i in range(R):
			print(result[i],end = " ")
		print()
		return

	#recursion
	for i in range(C):
		if a[m+1][i] != "":
			printsen(a,m+1,i,result)

def printsenhelper(a):
	result = [""]*R  #this array is to store sentences
					 #creates ["","",.......R elements]
	# words in the row 1 are considered as starting points and
	# sentences get printed

	for i in range(C):
		if a[0][i] != "":
			printsen(a,0,i,result)

def orderfun(a,p,q,r):
	a.append(p)
	a.append(q)
	a.append(r)
	printsenhelper(a)


#this is the driver code like int main in c++
print("\n/// Simple Present Tense Compund Type 1 ///\n")
a=[]
orderfun(a,sa,vprc,obj)
orderfun(a,sb,vprbc,obj)

print("\n/// Simple Past Tense Compound Type 1 ///\n")
a=[]
orderfun(a,sub,vpc,obj)

print("\n/// Simple Future Tense Compound Type 1 ///\n")
a=[]
orderfun(a,sub,vfc,obj)

print("\n/// Simple Present Tense Compund Type 2 ///\n")
a=[]
orderfun(a,sa,vpr,objc)
orderfun(a,sb,vprb,objc)

print("\n/// Simple Past Tense Compound Type 2 ///\n")
a=[]
orderfun(a,sub,vp,objc)

print("\n/// Simple Future Tense Compound Type 2 ///\n")
a=[]
orderfun(a,sub,vf,objc)




