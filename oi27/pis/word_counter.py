from collections import Counter

M = open("Mickiewicz.txt", "r")
S = open("Sienkiewicz.txt", "r")
P = open("Prus.txt", "r")

cM = Counter(M.read().split())
cS = Counter(S.read().split())
cP = Counter(P.read().split())

def sortSecond(val):
    return val[1]

top_M=cM
top_S=cS
top_P=cP
#top_M = sorted(cM, key=cM.get, reverse=True)
#top_S = sorted(cS, key=cS.get, reverse=True)
#top_P = sorted(cP, key=cP.get, reverse=True)

i = 0
print("#MICKIEWICZ")
for word in top_M:
    if(i>=250):
        break
    if(i>=200 and not(word in top_S or word in top_P)):
        print('[\''+word+'\','+'0'+'],')
    i+=1
i=0
print("#SIENKIEWICZ")
for word in top_S:
    if(i>=250):
        break
    if(i>=200 and not(word in top_M or word in top_P)):
        print('[\''+word+'\','+'1'+'],')
    i+=1
i=0
print("#PRUS")
for word in top_P:
    if(i>=250):
        break
    if(i>=200 and not(word in top_S or word in top_M)):
        print('[\''+word+'\','+'2'+'],')
    i+=1
